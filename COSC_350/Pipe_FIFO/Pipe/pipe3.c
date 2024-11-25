/* pipe3.c: demonstrate pipe from the child to the parent */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

void err_sys(char *);

int main() {
    int n
    int fd[2]; /* pipe child -> parent */
    pid_t pid;
    char line[MAXLINE];
    
    if (pipe(fd) < 0) /* create a pipe */
        err_sys("failed to create pipe");
    
    if ((pid = fork()) < 0) /* create a child */
        err_sys("failed to fork parent process");

    else if (pid > 0) { /* parent */
        close(fd[1]);
        n = read(fd[0], line, MAXLINE); /* read from the pipe */
        write(STDOUT_FILENO, "My baby said ", 13);
        write(STDOUT_FILENO, line, n);
    } else { /* child */
        close(fd[0]);
        write(fd[1], "hello world\n", 12); /* write to a pipe */
    }

    return 0;
}

void err_sys(char *str) {
    printf("%s \n", str);
    exit(1);
}
