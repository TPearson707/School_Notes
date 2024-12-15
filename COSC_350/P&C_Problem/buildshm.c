/* buildshm.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <errno.h>
#include "header.h"

int main() {
    int shmid;
    key_t key;
    struct SharedMemory *shm;

    // Create a unique key
    key = ftok(".", 'x');
    
    // Create shared memory
    if ((shmid = shmget(key, sizeof(struct SharedMemory), IPC_CREAT | 0666)) < 0) {
        perror("shmget error");
        exit(1);
    }

    // Attach shared memory
    shm = (struct SharedMemory*) shmat(shmid, NULL, 0);

    if((long)shm == -1) {
        perror("shmat error");
        exit(1);
    }

    // Initialize buffer indeces
    shm->in = 0;
    shm->out = 0;

    // Initialize semaphores
    sem_init(&shm->semaphores[EMPTY], 1, BUFFER_SIZE); // Initially all slots are empty
    sem_init(&shm->semaphores[FULL], 1, 0); // Initially no slots are full
    sem_init(&shm->semaphores[MUTEX], 1, 1); // Mutex is initially unlocked 
    
    printf("Shared memory and semaphores has been initialized\n");

    return 0;
}
