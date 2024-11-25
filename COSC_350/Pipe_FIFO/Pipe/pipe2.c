/* pipe2.c */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
void read_from_pipe(int);
void write_to_pipe(int);
void err_sys(char *);

int main () {
    pid_t pid;
    int mypipe[2]; // parent -> child pipe

    if (pipe(mypipe) < 0) /* create the pipe. */
        err_sys("failed to create pipe");

    if ((pid = fork()) < 0) /* create a child process */
        err_sys("failed to fork parent process");

    else if (pid > 0) { /* parent */
        close(mypipe[0]);
        write_to_pipe(mypipe[1]);
    } else {
        close(mypipe[1]);
        read_from_pipe(mypipe[0]);
    }

    return 0;
}

/* read characters from the pipe and echo them to stdout. */
void read_from_pipe(int fd) {
    FILE *stream;
    int c;
    /* fdopen() associates a stream with existing file descriptor, fd */
    stream = fdopen(fd, "r");
    while (((c = fgetc(stream)) != EOF)) /* read a character form the stream until EOF */
            putchar (c);              /* write to standard output */
    
    fclose(stream);
}

/* write some random text to the pipe. */
void write_to_pipe(int fd) {
    FILE *stream;
    
    stream = fdopen(fd, "w"); /* open a pipe for writing */
    fprintf(stream, "hello, world!\n");
    fprintf(stream, "goodbye, world!\n");
    fclose(stream);

}

void err_sys(char *str) {
    printf("%s \n", str);
    exit(1);
}
