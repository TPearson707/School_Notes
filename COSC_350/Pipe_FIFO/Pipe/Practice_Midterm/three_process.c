#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void terminate_parent(int sig);
void terminate_child(int sig);

int main() {
    pid_t child, grandchild;
    if ((child = fork()) < 0)
        exit(1);
    
    if (child == 0) {
        
        signal(SIGUSR1, terminate_child);

        if ((grandchild = fork()) < 0)
            exit(1);

        if (grandchild == 0) {

            for (int i = 0; i < 10; i++) {
                printf("grandchild process\n");
                sleep(1);
            }

            kill(getppid(), SIGUSR1);

            while(1) {

                if (getppid() != child) {
                    printf("terminating granchild process\n");
                    return 0;
                }

                sleep(1);
            }
        } else {
            while(1) {
                printf("child process\n");
                sleep(1);
            }
        }

    }  else {
        signal(SIGUSR2, terminate_parent);

        while(1) {
            printf("parent process\n");
            sleep(1);
        }
    }

return 0;
}

void terminate_parent(int sig) {
    printf("terminating parent process\n");
    exit(0);
}

void terminate_child(int sig) {
    kill(getppid(), SIGUSR2);
    printf("terminating child process\n");
    exit(0);
}
