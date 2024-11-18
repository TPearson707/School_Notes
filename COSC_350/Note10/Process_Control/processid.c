/* processid.c get a process information */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Process ID of calling process
    printf("Process ID = %d \n", getpid());
    // Parent's ID of calling process
    printf("Parent's Process ID = %d \n", getppid());
    // Real user's ID of calling process
    printf("Real User's ID = %d \n", getuid());
    // Effective user's ID of calling ...
    printf("Effective User's ID = %d \n", geteuid());
    // Real group ID
    printf("Real Group's ID = %d \n", getgid);
    // Effective group ID of calling ...
    printf("Effect Group's ID = %d \n", getegid());

    return 0;
}
