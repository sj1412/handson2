/*
============================================================================
Name : 31a.c
Author : Soumya Jain
Description :Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    sem_t *sem;


    sem = sem_open("newsemaphore", O_CREAT | O_EXCL, 0644, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    printf("Binary semaphore created and initialized to 1.\n");



    if (sem_wait(sem) == -1) {
        perror("sem_wait");
        sem_close(sem);
        sem_unlink("newsemaphore");
        exit(EXIT_FAILURE);
    }

    printf("Semaphore acquired.\n");


    sleep(2);


    if (sem_post(sem) == -1) {
        perror("sem_post");
        sem_close(sem);
        sem_unlink("newsemaphore");
        exit(EXIT_FAILURE);
    }

    printf("Semaphore released.\n");

    if (sem_close(sem) == -1) {
        perror("sem_close");
        exit(EXIT_FAILURE);
    }

    if (sem_unlink("newsemaphore") == -1) {
        perror("sem_unlink");
        exit(EXIT_FAILURE);
    }

    printf("Binary semaphore closed and unlinked.\n");

    return 0;
}
/*output:printed statements on succesful execution.
oumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 31a.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Binary semaphore created and initialized to 1.
Semaphore acquired.
Semaphore released.
Binary semaphore closed and unlinked.
*/
