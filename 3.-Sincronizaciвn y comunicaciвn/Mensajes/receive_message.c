#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>

#define MSG_KEY 1234

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    int msgid;
    struct msg_buffer msgbuf;

    // Get the message queue ID
    if ((msgid = msgget(MSG_KEY, 0666)) == -1) {
        perror("msgget");
        exit(1);
    }

    // Receive the message
    if (msgrcv(msgid, &msgbuf, sizeof(msgbuf), 1, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    printf("Received message: %s\n", msgbuf.msg_text);

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Message queue deleted.\n");

    return 0;
}
