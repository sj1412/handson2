/*
============================================================================
Name : 25.c
Author : Soumya Jain
Description :Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds msg_info;


    key = ftok("msg_queue", 65);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }


    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }


    if (msgctl(msgid, IPC_STAT, &msg_info) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }


    printf("Message Queue ID: %d\n", msgid);
    printf("Owner UID: %d\n", msg_info.msg_perm.uid);
    printf("Owner GID: %d\n", msg_info.msg_perm.gid);
    printf("Access Permissions: %o\n", msg_info.msg_perm.mode & 0777);
    printf("Time of Last Message Sent: %s", ctime(&msg_info.msg_stime));
    printf("Time of Last Message Received: %s", ctime(&msg_info.msg_rtime));
    printf("Time of Last Change: %s", ctime(&msg_info.msg_ctime));
    printf("Size of the Queue (bytes): %lu\n", msg_info.__msg_cbytes);
    printf("Number of Messages in the Queue: %lu\n", msg_info.msg_qnum);
    printf("Maximum Number of Bytes Allowed: %lu\n", msg_info.msg_qbytes);
    printf("PID of Last Message Sent: %d\n", msg_info.msg_perm.__key);
    printf("PID of Last Message Received: %d\n", msg_info.msg_perm.__seq);

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 25.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Message Queue ID: 1
Owner UID: 1000
Owner GID: 1000
Access Permissions: 666
Time of Last Message Sent: Thu Jan  1 05:30:00 1970
Time of Last Message Received: Thu Jan  1 05:30:00 1970
Time of Last Change: Sat Sep 21 00:04:36 2024
Size of the Queue (bytes): 0
Number of Messages in the Queue: 0
Maximum Number of Bytes Allowed: 16384
PID of Last Message Sent: 1091923193
PID of Last Message Received: 0
*/
