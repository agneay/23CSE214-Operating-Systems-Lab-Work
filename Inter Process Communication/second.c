#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    // Generate unique key
    key = ftok("progfile", 65);

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    msg.msg_type = 1;
    printf("Enter message to send: ");
    fgets(msg.msg_text, sizeof(msg.msg_text), stdin);

    // Send message
    msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);

    printf("Message sent successfully!\n");
    return 0;
}
