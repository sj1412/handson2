/*
============================================================================
Name : 10b.c
Author : Soumya Jain
Description :Write a separate program using sigaction system call to catch the following signals.
a. SIGINT
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

void handle_sigint(int signum) {
    printf("Caught SIGINT (Interrupt from keyboard)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct sigaction sa_sigint;

    sa_sigint.sa_handler = handle_sigint;
    sa_sigint.sa_flags = 0;
    sigemptyset(&sa_sigint.sa_mask);
    sigaction(SIGINT, &sa_sigint, NULL);

    printf("Press Ctrl+C to send SIGINT\n");
    while (1) {
        printf("Working...\n");
        sleep(1);
    }
    return 0;
}

/*output:
Press Ctrl+C to send SIGINT
Working...
Working...
Working...
Working...
^CCaught SIGINT (Interrupt from keyboard)
*/
