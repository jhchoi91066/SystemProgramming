#include "sysv_ipc.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <string.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

void use_message_queue() {
    int msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    struct msgbuf message;
    message.mtype = 1;
    strcpy(message.mtext, "Hello, World!");
    msgsnd(msgid, &message, sizeof(message), 0);
}

void use_shared_memory() {
    int shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);
    char *str = (char*) shmat(shmid, NULL, 0);
    strcpy(str, "Hello, World!");
    printf("Data written in memory: %s\n", str);
    shmdt(str);
}
