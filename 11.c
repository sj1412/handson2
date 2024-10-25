/*
============================================================================
Name : 11.c
Author : Soumya Jain
Description :Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("Ignoring SIGINT (Ctrl+C)\n");
}

int main() {
    struct sigaction sa;


    sa.sa_handler = handle_sigint;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is currently ignored. Press Ctrl+C to check.\n");
    sleep(5);


    sa.sa_handler = SIG_DFL;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT: default action. Press Ctrl+C to check.\n");
    sleep(5);
    printf("Program finished.\n");
    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
SIGINT is currently ignored. Press Ctrl+C to check.
^CIgnoring SIGINT (Ctrl+C)
SIGINT: default action. Press Ctrl+C to check.
^C
*/
