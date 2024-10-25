/*
============================================================================
Name : 6.c
Author : Soumya Jain
Description :Write a simple program to create three threads.
Date: 21st September, 2024.
============================================================================
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


void* ThreadFun(void* vargp)
{
    printf("Thread created\n");
}

int main()
{
    int i;
    pthread_t tid;

    for (i = 0; i < 3; i++)
        pthread_create(&tid, NULL, ThreadFun, NULL);

    pthread_exit(NULL);
    return 0;
}

/*output:myFun is executed by each thread. 3 threads are created thus we get the statement printed 3 times.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 6.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Thread created
Thread created
Thread created
*/
