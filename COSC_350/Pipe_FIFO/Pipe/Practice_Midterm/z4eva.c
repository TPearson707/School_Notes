/* z4eva.z write a complete C program which creates a zombie process stay in sys for ever */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid > 0) {
        while (1)
            sleep(1);
    } else {
        _exit(0);
    }

    return 0;
}
