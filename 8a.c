/*
============================================================================
Name : 8a.c
Author : Soumya Jain
Description :Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 21st September, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigsegv(int sig) {
    printf("Caught signal %d: Segmentation fault occurred.\n", sig);
    exit(1);
}

int main() {
    signal(SIGSEGV, handle_sigsegv);

    int *ptr = NULL;
    *ptr = 42;

    printf("This message will not be printed.\n");
    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 8a.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Caught signal 11: Segmentation fault occurred.
*/
