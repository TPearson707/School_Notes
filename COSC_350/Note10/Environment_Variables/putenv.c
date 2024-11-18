/* putenv.c */
#include <stdlib.h>
#include <stdio.h>

int main() {
    putenv("MYENV=park");
    printf("MYENV=%s\n", getenv("MYENV"));

    return 0;
}
