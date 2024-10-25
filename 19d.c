/*
============================================================================
Name : 19d.c
Author : Soumya Jain
Description : Create a FIFO file by:
d. mkfifo library function
Date: 21st September, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *fifo_name = "file_fifo";
    if (mknod(fifo_name, S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        exit(EXIT_FAILURE);
    }
    else{
    printf("FIFO file '%s' created successfully.\n", fifo_name);
    }
    return 0;
}
/*output: printed statement on succesful exection of program.
oumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 19d.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
FIFO file 'file_fifo' created successfully.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ls -l
prw-rw-r-- 1 soumya soumya     0 Sep 20 19:22 file_fifo
*/
