/*
============================================================================
Name : 17b.c
Author : Soumya Jain
Description :Write a program to execute ls -l | wc.
b. use dup2
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("forking error");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {

        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);

    }

    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {

        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[1]);
        close(pipefd[0]);
        execlp("wc", "wc", NULL);

    }


    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}
/*output:
oumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ nano 17b.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 17b.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
     22     191    1091
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ls -l| wc
     22     191    1091
*/
