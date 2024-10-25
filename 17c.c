/*
============================================================================
Name : 17c.c
Author : Soumya Jain
Description :Write a program to execute ls -l | wc.
c. use fcntl
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid1, pid2;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }


    if ((pid1 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        close(fd[0]);

         int flags = fcntl(fd[1], F_GETFL);
        fcntl(fd[1], F_SETFL, flags | O_NONBLOCK);

        if (dup2(fd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        close(fd[1]);

        execlp("ls", "ls", "-l", NULL);

        perror("execlp");
        exit(EXIT_FAILURE);
    }


    if ((pid2 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {

        close(fd[1]);

        if (dup2(fd[0], STDIN_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        close(fd[0]);

        execlp("wc", "wc", NULL);

        perror("execlp");
        exit(EXIT_FAILURE);
    }


    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 17c.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
     23     200    1144
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ls -l| wc
     23     200    1144
*/
