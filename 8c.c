/*
============================================================================
Name : 8c.c
Author : Soumya Jain
Description :Write a separate program using signal system call to catch the following signals.
c.SIGFPE
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigfpe(int sig) {
    printf("Caught signal %d: Floating point exception (division by zero).\n", sig);
    exit(1);
}

int main() {
    signal(SIGFPE, handle_sigfpe);

    int x = 5;
    int y = 0;
    int result = x / y;

    printf("This message will not be printed.\n");
    return 0;
}
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 8c.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Caught signal 8: Floating point exception (division by zero).
*/
