#ifndef HEADER_H
#define HEADER_H

#include <semaphore.h>
#include <pthread.h>

#define BUFFER_SIZE 5
#define EMPTY 0
#define FULL 1
#define MUTEX 2

struct SharedMemory {
    int buffer[BUFFER_SIZE];
    int in;
    int out;
    sem_t semaphores[3]; // 0: empty, 1: full, 2: mutex
};

#endif
