/*
============================================================================
Name : 27a.c
Author : Soumya Jain
Description :Write a program to receive messages from the message queue.
a. with 0 as a flag.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define MSG_SIZE 128

struct message {
    long msg_type;
    char msg_text[MSG_SIZE];
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

    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }


    printf("Waiting to receive messages \n");
    while (1) {

        if (msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("Received: %s\n", msg.msg_text);
    }

    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ gcc 27a.c -o 27a
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ gcc 26.c -o 26
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./26
Sent: Message 1
Sent: Message 2
Sent: Message 3
Sent: Message 4
Sent: Message 5
Messages sent.  check the message queue with 'ipcs -q'.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./27a
Waiting to receive messages 
Received: Message 1
Received: Message 2
Received: Message 3
Received: Message 4
Received: Message 5
*/
