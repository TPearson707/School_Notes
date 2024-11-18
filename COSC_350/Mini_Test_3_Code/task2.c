#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *Thread1(void *arg);
void *Thread2(void *arg);
void *Thread3(void *arg);

int main(int argc, char*argv[]) {

    if (argc != 2) {
        printf("Usage: ./task2 integer");
        exit(1);
    }

    int input_value = atoi(argv[1]);
    pthread_t thread1, thread2, thread3;
   
    printf("Program starting...\n");

    // Create and run Thread1
    if (pthread_create(&thread1, NULL, Thread1, &input_value) != 0)
        return 1;

    // Wait for Thread1 to complete
    if (pthread_join(thread1, NULL) != 0) 
        return 1;
    
    // Create and run Thread2
    if (pthread_create(&thread2, NULL, Thread2, &input_value) != 0)
        return 1;

    // Wait for Thread2 to complete
    if (pthread_join(thread2, NULL) != 0)
        return 1;

    // Create and run Thread3
    if (pthread_create(&thread3, NULL, Thread3, &input_value) != 0)
        return 1;

    // Wait for Thread3 to complete
    if (pthread_join(thread3, NULL) != 0)
        return 1;

    printf("The result of the sums is: %d\n", input_value);
    
    return 0;
}

void *Thread1(void *arg) {
    int *input = (int *)arg;
    *input += 10;
    printf("Thread1: Adding 10, result = %d\n", *input);
    return NULL;
}

void *Thread2(void *arg) {
    int *input = (int *)arg;
    *input += 20;
    printf("Thread2: Adding 20, result = %d\n", *input);
    return NULL;
}

void *Thread3(void *arg) {
    int *input = (int *)arg;
    *input += 30;
    printf("Thread3: Adding 30, result = %d\n", *input);
    return NULL;
}


