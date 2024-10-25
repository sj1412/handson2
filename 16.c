/*
============================================================================
Name : 16.c
Author : Soumya Jain
Description :Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 21st September, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main() {
    int pipe1[2];
    int pipe2[2];
    int buffer_size=100;
    pid_t pid;
    char buffer[buffer_size];


    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe can't be created");
        exit(1);
    }


    pid = fork();
    if (pid < 0) {
        perror("error while forking process");
        exit(1);
    }

    if (pid > 0) {
        close(pipe1[0]);
        close(pipe2[1]);


        char *messages[] = {"hey!", "how are you?", "all good?"};
        for (int i = 0; i < 3; i++) {
            write(pipe1[1], messages[i], strlen(messages[i]) + 1);
            read(pipe2[0], buffer, buffer_size);
            printf("parent recieved: %s\n", buffer);
        }

    } else {
        close(pipe1[1]);
        close(pipe2[0]);

        while (1) {
            read(pipe1[0], buffer, buffer_size);
            printf("child recieved: %s\n", buffer);
            if (strcmp(buffer, "exit") == 0) {
                break;
            }

            char response[buffer_size];
            snprintf(response,buffer_size, "Child's response to '%s'", buffer);
            write(pipe2[1], response, strlen(response) + 1);
        }
    }

    return 0;
}
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 16.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
child recieved: hey!
parent recieved: Child's response to 'hey!'
child recieved: how are you?
parent recieved: Child's response to 'how are you?'
child recieved: all good?
parent recieved: Child's response to 'all good?'
child recieved: all good?
*/
