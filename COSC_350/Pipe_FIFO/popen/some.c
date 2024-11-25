/* some.c function change upper case character string to lower case */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void err_sys(char *);

int main() {
    int c;
    
    while ((c = getchar()) != EOF) {
        if (isupper(c))
            c = tolower(c);
        if (putchar(c) == EOF)
            err_sys("output error");
        if (c == '\n')
            fflush(stdout);
    }

    return 0;
}

void err_sys(char *str) {
    printf("%s \n", str);
    exit(1);
}
