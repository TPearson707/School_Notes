/* 
 * parent process sends "I love you" over a pipe to chlid process
 * child process reads the message and prints it to stdout as "my mom said I love you"
 * child process sends message "I love you too" over a pipe to its parent
 * parent reads the message and prints it to stdout as "My child said I love you too."
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define R_END 0
#define W_END 1

int main() {
    pid_t pid;
    int fd1[2], fd2[2], nread;
    char buffer[BUFSIZ];
    
    pipe(fd1); // parent -> child
    pipe(fd2); // child -> parent

    pid = fork();

    if (pid > 0) {
        close(fd1[R_END]);
        close(fd2[W_END]);
        char *message = "I love you";

        write(fd1[W_END], message, strlen(message)); /* write message parent -> child */
        nread = read(fd2[R_END], buffer, BUFSIZ); /* read message child -> parent */
        
        char buf[BUFSIZ];
        char *out = "My child said";
        sprintf(buf, "%s %s",out, buffer); // load what child said into buffer
        write(0, buf, strlen(buf)); // write child response to stdout
                                    
        close(fd1[W_END]);
        close(fd2[R_END]);
    } else {
        close(fd1[W_END]);
        close(fd2[R_END]);
        char *message = "I love you too";
        
        nread = read(fd1[R_END], buffer, BUFSIZ); /* read message parent -> child */
        
        char buf[BUFSIZ];
        char *out = "My mom said";
        sprintf(buf, "%s  %s",out, buffer); // load what parent said into buffer

        write(0, buf, strlen(buf)); // write what parent said to stdout
                            
        write(fd2[W_END], message, strlen(message)); /* write message child -> parent */
        
        close(fd1[R_END]);
        close(fd2[W_END]);
    }

    return 0;
}
        
