/* producer.c */

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
    int item = 0;

    // Get the shard memory
    key = ftok(".", 'x');
    if ((shmid = shmget(key, sizeof(struct SharedMemory), 0666)) < 0) {
        perror("shmget error");
        exit(1);
    }

    // Attach the shared memory
    shm = (struct SharedMemory*) shmat(shmid, NULL, 0);
    if ((long)shm == -1) {
        perror("shmat error");
        exit(1);
    }

    printf("Producer is ready\n");

    while(1) {
        item++;

        // Wait for an empty slot
        sem_wait(&shm->semaphores[EMPTY]);

        // Lock the buffer
        sem_wait(&shm->semaphores[MUTEX]);

        // Produce an item
        shm->buffer[shm->in] = item;
        printf("produced: %d\n", item);
        shm->in = (shm->in + 1) % BUFFER_SIZE;

        // Unlock the buffer
        sem_post(&shm->semaphores[MUTEX]);

        // Signal that a slot is full
        sem_post(&shm->semaphores[FULL]);

        sleep(1);
    }
    
    shmdt(shm);
    return 0;
}
