/*
============================================================================
Name : 32.c
Author : Soumya Jain
Description :Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>

#define SHM_SIZE 1024
#define MAX_TICKETS 5
#define MAX_RESOURCES 2

sem_t* create_semaphore(const char* name, int initial_value) {
    sem_t* sem = sem_open(name, O_CREAT | O_EXCL, 0644, initial_value);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }
    return sem;
}


void remove_semaphore(const char* name) {
    if (sem_unlink(name) == -1) {
        perror("sem_unlink");
    }
}


void ticket_creation(sem_t* sem) {
    for (int i = 0; i < MAX_TICKETS; i++) {
        sem_wait(sem);
        printf("Ticket number created: %d\n", i + 1);
        sem_post(sem);
        sleep(1);
    }
}


void shared_memory_example(sem_t* sem) {
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    char* shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char*)(-1)) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 5; i++) {
        sem_wait(sem);
        snprintf(shm_ptr, SHM_SIZE, "Message %d", i + 1);
        printf("Shared memory updated: %s\n", shm_ptr);
        sem_post(sem);
        sleep(1);
    }

    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);
}


void resource_management(sem_t* sem) {
    for (int i = 0; i < 5; i++) {
        sem_wait(sem);
        printf("Resource %d acquired\n", i + 1);
        sleep(1);
        sem_post(sem);
        printf("Resource %d released\n", i + 1);
    }
}

int main() {

    sem_t* ticket_sem = create_semaphore("/ticket_sem", 1);
    sem_t* shm_sem = create_semaphore("/shm_sem", 1);
    sem_t* resource_sem = create_semaphore("/resource_sem", MAX_RESOURCES);


    printf("Starting ticket number creation:\n");
    ticket_creation(ticket_sem);


    printf("\nStarting shared memory updates:\n");
    shared_memory_example(shm_sem);


    printf("\nStarting resource management:\n");
    resource_management(resource_sem);

    remove_semaphore("/ticket_sem");
    remove_semaphore("/shm_sem");
    remove_semaphore("/resource_sem");

    return 0;
}
/*output:
Ticket number created: 1
Ticket number created: 2
Ticket number created: 3
Ticket number created: 4
Ticket number created: 5

Starting shared memory updates:
Shared memory updated: Message 1
Shared memory updated: Message 2
Shared memory updated: Message 3
Shared memory updated: Message 4
Shared memory updated: Message 5

Starting resource management:
Resource 1 acquired
Resource 1 released
Resource 2 acquired
Resource 2 released
Resource 3 acquired
Resource 3 released
Resource 4 acquired
Resource 4 released
Resource 5 acquired
Resource 5 released
*/
