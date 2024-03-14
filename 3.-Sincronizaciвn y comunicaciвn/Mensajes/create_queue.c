#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define MSG_KEY 1234 // Unique key for message queue

int main() {
    int msgid;

    // Create a message queue with permissions 0666 (read/write for owner, group, and others)
    if ((msgid = msgget(MSG_KEY, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Message queue created with ID: %d\n", msgid);

    return 0;
}
