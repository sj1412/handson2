/*
============================================================================
Name : 31b.c
Author : Soumya Jain
Description :Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>

void initialize_semaphore(int semid, int value) {
    if (semctl(semid, 0, SETVAL, value) == -1) {
        perror("semctl failed");
        exit(1);
    }
}

int create_semaphore(int key) {
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget failed");
        exit(1);
    }
    return semid;
}

int main() {
    int counting_key = ftok("counting_sem", 66);
    
    int counting_sem = create_semaphore(counting_key);
    initialize_semaphore(counting_sem, 5);
    printf("Counting semaphore created and initialized to 5.\n");

    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 31b.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Counting semaphore created and initialized to 5.
*/
