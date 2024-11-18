#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void terminateChild(int sig) {
    printf("My mom said go study\n");
    _exit(0);
}

void terminateParent(int sig) {
    printf("Don't disturb my child while he studies\n");
    exit(0);
}



int main() {
    pid_t pid;
    
    if ((pid = fork()) < 0)
        exit(1);

    if (pid > 0) {
        
        signal(SIGCHLD, terminateParent);

        for (int i = 0; i < 10; i++) {
            printf("Son go study\n");
            sleep(1);
        }

        kill(pid, SIGUSR1);

        while(1) {
            sleep(1);
        }

    } else {
        signal(SIGUSR1, terminateChild);

        while(1) {
            printf("I want to play forever\n");
            sleep(1);
        }
    }

    return 0;
}
