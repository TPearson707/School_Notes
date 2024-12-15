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

    // Create a key for creating the message queue
    if ((key = ftok("kirk.c", 'B')) == -1) {
        perror("ftok error");
        exit(1);
    }

    // Create a message queue
    if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
        perror("msgget error");
        exit(1);
    }

    printf("Enter two integers (e.g., '3 5'), or type ^D to quit:\n");
    buf.mtype = 1; // Use mtype 1 for simplicity

    // Read two integers and send them in the message queue
    while (scanf("%d %d", &buf.num1, &buf.num2) == 2) {
        if (msgsnd(msqid, (struct msgbuf *)&buf, sizeof(struct my_msgbuf) - sizeof(long), 0) == -1) {
            perror("msgsnd error");
        }
        printf("Message sent: %d %d\n", buf.num1, buf.num2);
    }

    // Clean up message queue
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl error");
        exit(1);
    }

    printf("Message queue removed.\n");
    exit(0);
}

