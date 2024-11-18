/* fork.c demonstates the forK() system call */
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_COUNT 1000

void ChildProcess(); /* child process prototype */
void ParentProcess(); /* parent process prototype */

void main(void) {
    pid_t pid;
    pid_t ppid = getpid(); /* get parent process ID */
    pid = fork(); /* create a child */
    if (pid == 0) /* pid is valid child process */
        ChildProcess();
    else
        ParentProcess();

}

void ChildProcess() {
    
    for (int i = 1; i <= MAX_COUNT; i++)
       printf("     This line is from cihld process value = %d\n", i);
    printf("    *** Child process is done ***\n");

}

void ParentProcess() {

    for (int i = 1; i <= MAX_COUNT; i++)
       printf("This line is from parent process    value = %d\n", i);
    printf("*** Parent is done ***\n");

}
