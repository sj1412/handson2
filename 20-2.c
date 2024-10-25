/*
============================================================================
Name : 20-2.c(part 2)
Author : Soumya Jain
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *fifo_name = "20fifo";
    char buffer[100];


    int fd = open(fifo_name, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }


    read(fd, buffer, sizeof(buffer));
    printf("Reader: Recieved message: %s\n", buffer);


    close(fd);
    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ gcc 20-1.c -o 20-1
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ gcc 20-2.c -o 20-2
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./20-1
Writer:Sent message: this is from writer side!

soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./20-2
Reader: Recieved message: this is 
*/
