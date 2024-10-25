/*
============================================================================
Name : 8b.c
Author : Soumya Jain
Description :Write a separate program using signal system call to catch the following signals.
b.SIGINT
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigint(int sig) {
    printf("Caught signal %d: Interrupt signal received.\n", sig);
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);

    while (1) {
        printf(" Press Ctrl+C to trigger SIGINT.\n");
    }

    return 0;
}

/*output:
Press Ctrl+C to trigger SIGINT.
^C Press Ctrl+C to trigger SIGINT.
Caught signal 2: Interrupt signal received.
*/
