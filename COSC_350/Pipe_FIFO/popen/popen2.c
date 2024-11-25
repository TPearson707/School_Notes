/* popen2.c function demonstrate a popen function */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MAXLINE 256

void err_sys(char *);

int main() {
    char line[MAXLINE];
    FILE *fpin; /* use pointer to read from stdin */

    if ((fpin = popen("./some", "r")) == NULL)
        err_sys("popen error");
    for( ; ; ) {
        fputs("prompt> ", stdout);
        fflush(stdout);
        if (fgets(line, MAXLINE, fpin) == NULL) /* read from pipe */
            break;
        if (fputs(line, stdout) == EOF) /* write to stdout */
            err_sys("fputs error to pipe");
    }
    if (pclose(fpin) == -1)
        err_sys("pclose error");
    putchar('\n');
    return 0;
}

void err_sys(char *str) {
    printf("%s \n", str);
    exit(1);
}
