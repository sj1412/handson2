/*
============================================================================
Name : 30.c
Author : Soumya Jain
Description : Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 21st September, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>

#define SIZE 1024

int main() {
    int shmid;
    key_t key = ftok("shared_mem",65);
    char *str;


    shmid = shmget(key, SIZE, 0666|IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }


    str = (char*) shmat(shmid, (void*)0, 0);
    if (str == (char*)(-1)) {
        perror("shmat");
        exit(1);
    }


    sprintf(str, "In the shared memory!");

    printf("Data written to shared memory: %s\n", str);

    shmdt(str);


    str = (char*) shmat(shmid, (void*)0, SHM_RDONLY);
    if (str == (char*)(-1)) {
        perror("shmat");
        exit(1);
    }


    strcpy(str, "Trying to overwrite...");
    printf("Data in shared memory after overwrite: %s\n", str);
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

/*output: as expected we couldn't overwrite in read only mode & thus got segmentation fault.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 28.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Data written to shared memory: In the shared memory!
Segmentation fault (core dumped)
*/
