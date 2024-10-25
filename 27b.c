/*
============================================================================
Name : 27b.c
Author : Soumya Jain
Description :Write a program to receive messages from the message queue.
a. with IPC_NOWAIT as a flag.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include<errno.h>

#define MSG_SIZE 256
#define MSG_TYPE 1

struct msgbuf {
    long mtype;
    char mtext[MSG_SIZE]; 
};

int main() {
    key_t key;
    int msgid;
    struct msgbuf message;


    key = ftok("msg_queue1", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }


    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }


    while (1) {

        if (msgrcv(msgid, &message, sizeof(message.mtext), MSG_TYPE, IPC_NOWAIT) == -1) {

            if (errno == ENOMSG) {
                printf("No messages in the queue. Waiting...\n");
                sleep(1);
            } else {
                perror("msgrcv");
                break;
            }
        } else {

            printf("Received message: %s\n", message.mtext);
        }
    }


    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}
