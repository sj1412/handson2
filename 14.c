/*
============================================================================
Name : 14.c
Author : Soumya Jain
Description :Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 21st September, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char writeMsg[] = "Hello from the pipe!";
    char readBuffer[100];


    if (pipe(pipefd) == -1) {
        perror("error creating pipe");
        exit(EXIT_FAILURE);
    }


    pid = fork();
    if (pid == -1) {
        perror("error creating child process");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(pipefd[0]);

        write(pipefd[1], writeMsg, strlen(writeMsg) + 1);

        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    } else {
        close(pipefd[1]);

        read(pipefd[0], readBuffer, sizeof(readBuffer));

        printf("In parent process, received data via pipe: %s\n", readBuffer);

        close(pipefd[0]);
    }

    return 0;
}
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 14.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
In parent process, received data via pipe: Hello from the pipe!
*/
