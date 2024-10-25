/*
============================================================================
Name : 18.c
Author : Soumya Jain
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd1[2];
    int fd2[2];
    pid_t pid1, pid2, pid3;


    if (pipe(fd1) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }


    if (pipe(fd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if ((pid1 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        close(fd1[0]);


        dup2(fd1[1], STDOUT_FILENO);
        close(fd1[1]);
        execlp("ls", "ls", "-l", NULL);

    }


    if ((pid2 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {
        close(fd1[1]);

        close(fd2[0]);

        dup2(fd1[0], STDIN_FILENO);
        close(fd1[0]);

        dup2(fd2[1], STDOUT_FILENO);
        close(fd2[1]);

        execlp("grep", "grep", "^d", NULL);


    }


    if ((pid3 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid3 == 0) {
        close(fd2[1]);

        dup2(fd2[0], STDIN_FILENO);
        close(fd2[0]);

        execlp("wc", "wc", "-l", NULL);


    }

    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);

    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ls -l | grep ^d | wc
      0       0       0
*/
