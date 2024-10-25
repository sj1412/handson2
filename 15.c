/*
============================================================================
Name : 15.c
Author : Soumya Jain
Description :Write a simple program to send some data from parent to the child process.
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
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { 
        close(pipefd[0]);

        const char *message = "Hello from parent!";
        write(pipefd[1], message, strlen(message) + 1);
        
        close(pipefd[1]);
    } else {
        close(pipefd[1]);


        read(pipefd[0], buffer, sizeof(buffer));

        close(pipefd[0]);

        printf( "In child process: Child received: %s\n", buffer);
    }

    return 0;
}
/*output:"hello from parent"- written by parent process & recieved by child using pipe
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ nano 15.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 15.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
In child process: Child received: Hello from parent!
*/
