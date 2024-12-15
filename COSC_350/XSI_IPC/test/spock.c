#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf {
    long mtype;
    int num1;
    int num2;
};

int main(void) {
    struct my_msgbuf buf;
    int msqid;
    key_t key;

    // Create a key for accessing the message queue
    if ((key = ftok("kirk.c", 'B')) == -1) {
        perror("ftok error");
        exit(1);
    }

    // Open the message queue
    if ((msqid = msgget(key, 0644)) == -1) {
        perror("msgget error");
        exit(1);
    }

    printf("spock: Ready to receive messages, captain.\n");

    for (;;) {
        // Receive a message from the queue
        if (msgrcv(msqid, (struct msgbuf *)&buf, sizeof(struct my_msgbuf) - sizeof(long), 0, 0) == -1) {
            perror("msgrcv error");
            exit(1);
        }

        // Validate and process the received message
        if (buf.num1 != 0 || buf.num2 != 0) { // Both numbers are valid integers
            int sum = buf.num1 + buf.num2;
            printf("spock: Received %d and %d. Sum: %d\n", buf.num1, buf.num2, sum);
        } else {
            fprintf(stderr, "spock: Error - Received invalid input. Expected two integers.\n");
            continue;
        }
    }

    return 0;
}

