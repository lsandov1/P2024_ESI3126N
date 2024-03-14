#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    // Prepare the message
    msgbuf.msg_type = 1;
    strcpy(msgbuf.msg_text, "Hello, this is a message!");

    // Send the message
    if (msgsnd(msgid, &msgbuf, sizeof(msgbuf), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent to the queue.\n");

    return 0;
}
