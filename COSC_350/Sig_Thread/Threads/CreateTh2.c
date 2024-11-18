/* CreateTh2.c Demonstrate creation of threads */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

static pthread_t getCurrentThreadID() {
    return pthread_self();
}

// the function pointed to by each thread by passing different parameter
void *PrintHello(void *threadid) {
    int tid;
    tid = (int)threadid;
    pthread_t id = getCurrentThreadID();
    printf("Hello World! It's me, thread #%d! with thread id %u\n", tid, id);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int rc, t;
    // create five threads pointing to the same function with different arguments
    for (t = 0; t < NUM_THREADS; t++) {
        printf("In main: creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        if (rc != 0) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }

    pthread_exit(NULL);
    exit(0);
}
