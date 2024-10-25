/*
============================================================================
Name : 29.c
Author : Soumya Jain
Description: Write a program to remove the message queue.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

int main() {
    int key;
    int msgid;

    key = ftok("29file", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        return 1;
    }

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID failed");
        return 1;
    }

    printf("Message queue removed successfully.\n");

    return 0;
}
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 29.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Message queue removed successfully.
*/
