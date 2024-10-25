/*
============================================================================
Name : 21-2.c
Author : Soumya Jain
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 21st September, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO1 "fifo_a"
#define FIFO2 "fifo_b"

int main() {
    char buffer[1024];
    int fd_read, fd_write;


    fd_read = open(FIFO1, O_RDONLY);
    fd_write = open(FIFO2, O_WRONLY);

    if (fd_read == -1 || fd_write == -1) {
        perror("Error opening FIFO");
        exit(1);
    }


    while (1) {

        if (read(fd_read, buffer, sizeof(buffer)) > 0) {
            printf("Received: %s\n", buffer);


            printf("You: ");
            fgets(buffer, sizeof(buffer), stdin);

            write(fd_write, buffer, strlen(buffer) + 1);
        }
    }

    close(fd_write);
    close(fd_read);
    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ nano 21a.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ nano 21-1.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./21a
Sender side:
You: hello
Received: hi, im fine
You:

Receiver side:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./21b
Received: hello
You: hi, im fine
*/
