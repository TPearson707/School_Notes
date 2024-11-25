#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread1(void *);
void *thread2(void *);
void *thread3(void *);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        perror("argument number error");
        exit(1);
    }

    int num = atoi(argv[1]);
    int rc;
    pthread_t t1, t2, t3;
    void *tret1, *tret2, *tret3;

    rc = pthread_create(&t1, NULL, thread1, (void *) num);
    rc = pthread_join(t1, &tret1);
    
    rc = pthread_create(&t2, NULL, thread2, (void *) tret1);
    rc = pthread_join(t2, &tret2);

    rc = pthread_create(&t3, NULL, thread3, (void *) tret2);
    rc = pthread_join(t3, &tret3);

    num = (int) tret3;

    printf("The final result of the three thread's calculation is %d\n", num);
    
    return 0;
}

void *thread1(void *arg) {
    int num = (int)arg;
    num += 10;
    return ((void *) num);
}

void *thread2(void *arg) {
    int num = (int)arg;
    num += 20;
    return ((void *) num);
}

void *thread3(void *arg) {
    int num = (int)arg;
    num += 30;
    return ((void *) num);
}
