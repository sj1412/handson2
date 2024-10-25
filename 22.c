/*
============================================================================
Name : 22.c
Author : Soumya Jain
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <errno.h>

#define FIFO_NAME "22fifo"

int main() {
    char buffer[100];

    mkfifo(FIFO_NAME, 0666);

    int fd = open(FIFO_NAME, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    fd_set read_fds;
    struct timeval timeout;


    timeout.tv_sec = 10;
    timeout.tv_usec = 0;


    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    printf("Waiting for data on FIFO for up to 10 seconds...\n");


    int retval = select(fd + 1, &read_fds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select");
        close(fd);
        exit(EXIT_FAILURE);
    } else if (retval == 0) {
       printf("Timeout occurred! No data after 10 seconds.\n");
    } else {

        if (FD_ISSET(fd, &read_fds)) {
            ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
            if (bytes_read > 0) {
                buffer[bytes_read] = '\0';
                printf("Received data: %s\n", buffer);
            } else if (bytes_read == -1) {
                perror("read");
            }
        }
    }

    close(fd);
    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ mkfifo 22fifo
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 22.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
In terminal-1
Waiting for data on FIFO for up to 10 seconds...
Received data: hello

from terminal-2:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ echo "hello">22fifo
*/
