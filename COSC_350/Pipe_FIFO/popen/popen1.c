/* popen1.c: demonstrate popen with "w" */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    FILE *wfp;
    char buffer[BUFSIZ + 1];

    sprintf(buffer, "This is testing popen with w \n");
    /* octal dump: displays contents as octal numbers */
    wfp = popen("od -c", "w");
    if (wfp != NULL) {
        fwrite(buffer, sizeof(char), strlen(buffer), wfp);
        pclose(wfp);
        return 0;
    }

    return 1;
}               
