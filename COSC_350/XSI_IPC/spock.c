/*spock.c read message from the message queue */
/* created by kirt.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf {
    long mtype;
    char mtext[200];
};

int main(void) {
    struct my_msgbuf buf;
    int msqid;
    key_t key;

    /* create a key same as kirk.c */
    if ((key = ftok("kirk.c", 'B')) == -1) {
        perror("ftok error");
        exit(1);
    }

    /* open message queue already created by kirk.c */
    if ((msqid = msgget(key, 0644)) == -1) {
        perror("msgget error");
        exit(1);
    }

    printf("spock: ready to receive messages, captain.");

    for( ; ; ) {
        /* get each message from the message queue */
        if (msgrcv(msqid, (struct msgbuf *)&buf, sizeof(buf), 0, 0) == -1) {
            perror("msgrcv error");
            exit(1);
        }

        printf("spock: \"%s\" \n", buf.mtext);
    }
return 0;
}
