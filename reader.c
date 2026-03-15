#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long type;
    char text[100];
};

int main()
{
    int msgid;

    // Create message queue
    msgid = msgget(1234, 0666 | IPC_CREAT);

    struct message msg;

    msg.type = 1;

    strcpy(msg.text, "dhilsan"); 

    // Send message
    msgsnd(msgid, &msg, sizeof(msg.text), 0);

    printf("Message sent: %s\n", msg.text);

    return 0;
}
