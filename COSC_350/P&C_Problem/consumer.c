/* consumer.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <errno.h>
#include "header.h"

int main() {
    int shmid;
    key_t key;
    struct SharedMemory *shm;

    // Get the shared memory
    key = ftok(".", 'x');
    if ((shmid = shmget(key, sizeof(struct SharedMemory), 0666)) < 0) {
        perror("shmget error");
        exit(1);
    }

    // Attach the shared memory
    shm = (struct SharedMemory*) shmat(shmid, NULL, 0);
    if((long)shm == -1) {
        perror("shmat error");
        exit(1);
    }

    printf("Consumer is ready\n");

    while(1) {
        int item;

        // Wait for full slot
        sem_wait(&shm->semaphores[FULL]);
        
        // Lock the buffer
        sem_wait(&shm->semaphores[MUTEX]);

        // Consumer an item
        item = shm->buffer[shm->out];
        printf("consumed: %d\n", item);
        shm->out = (shm->out + 1) % BUFFER_SIZE;

        // Unlock the buffer
        sem_post(&shm->semaphores[MUTEX]);

        // Signal that a slot is empty
        sem_post(&shm->semaphores[EMPTY]);
        sleep(2);
    }
    shmdt(shm);
    return 0;
}


