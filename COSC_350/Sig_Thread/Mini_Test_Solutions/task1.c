#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void terminated(int sig) {
    
    if (sig == SIGUSR1) {
        printf("Mom said I need to study! Byte! I need to go!\n");
        _exit(0); // child send SIGCHLD when it is terminated
    } else if (sig == SIGCHLD) {
        printf("Please don't diturb my child studying!\n");
        exit(0);
    }
}

int main() {
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(1);
    }

    if (pid > 0) {/* parent process */
        signal(SIGCHLD, terminated);
        
        for (int i = 0; i < 10; i++) {
            printf("Son! It is time to study.\n");
            sleep(1);
        }

        kill(pid, SIGUSR1);

        while(1) {
            sleep(1);
        }
    } else { /* child process */
        signal(SIGUSR1, terminated);

        while(1) {
            printf("I am immortal!\n");
            sleep(1);
        }
    }

    return 0;
}
    
