/* pipe1.c demonstrate a pipe from the parent to the child */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256
void err_sys(char *);

int main() {
    int n, fd[2];
    pid_t pid;
    char line[MAXLINE];

    if (pipe(fd) < 0) /* create a pipe */
        err_sys("pipe error");
    
    if ((pid = fork()) < 0) /* create a child */
        err_sys("fork error");

    else if (pid > 0) {/* parent */ 
        close(fd[0]); // read end parent -> child
        sleep(5);
        write(fd[1], "hello world\n", 12); /* write to a pipe */
    } else {/* child */
        close(fd[1]);
        n = read(fd[0], line, MAXLINE); /* read from the pipe */
        write(STDOUT_FILENO, "my mom said ", 12);
        write(STDOUT_FILENO, line, n);
    }

    return 0;
}

void err_sys(char *str) {
    printf("%s \n", str);
    exit(1);
}   
