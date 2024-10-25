/*
============================================================================
Name : 23.c
Author : Soumya Jain
Description :Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {

    struct rlimit rl;
    if (getrlimit(RLIMIT_NOFILE, &rl) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    printf("Maximum number of open files: soft limit = %lu, hard limit = %lu\n",
           (unsigned long)rl.rlim_cur, (unsigned long)rl.rlim_max);


    int pipe_fds[2];
    if (pipe(pipe_fds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }


    long pipe_size = fpathconf(pipe_fds[0], _PC_PIPE_BUF);
    if (pipe_size == -1) {
        perror("fpathconf");
        exit(EXIT_FAILURE);
    }

    printf("Size of the pipe: %ld bytes\n", pipe_size);

    close(pipe_fds[0]);
    close(pipe_fds[1]);

    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 23.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Maximum number of open files: soft limit = 1024, hard limit = 1048576
Size of the pipe: 4096 bytes
*/
