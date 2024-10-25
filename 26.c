/*
============================================================================
Name : 26.c
Author : Soumya Jain
Description :Write a program to send messages to the message queue. Check $ipcs -q
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define SIZE 128

struct message {
    long msg_type;
    char msg_text[SIZE];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;


    key = ftok("msg_queue1", 65); 
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }


    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i <= 5; i++) {
        msg.msg_type = 1;
        snprintf(msg.msg_text, SIZE, "Message %d", i);
        if (msgsnd(msgid, &msg, sizeof(msg.msg_text), 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
        printf("Sent: %s\n", msg.msg_text);
    }

    printf("Messages sent.  check the message queue with 'ipcs -q'.\n");

    return 0;
}

/*output:
oumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 26.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Sent: Message 1
Sent: Message 2
Sent: Message 3
Sent: Message 4
Sent: Message 5
Messages sent.  check the message queue with 'ipcs -q'.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x41156d30 2          soumya     666        640          5
*/
