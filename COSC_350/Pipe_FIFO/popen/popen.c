/* popen.c demonstrate the popen function. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *cmd = "ls *.c";
    char buf[BUFSIZ]; /* BUFSIZ = 1024 defined in stdio.h */
    FILE *ptr;

    if ((ptr = popen(cmd, "r")) != NULL)
        while (fgets(buf, BUFSIZ, ptr) != NULL)
             printf("%s", buf);
    pclose(ptr);

    return 0;
}       
