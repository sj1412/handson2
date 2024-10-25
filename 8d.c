/*
============================================================================
Name : 8d.c
Author : Soumya Jain
Description :Write a separate program using signal system call to catch the following signals.
d.SIGALRM
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigalrm(int sig) {
    printf("Caught signal %d: Alarm signal received.\n", sig);
    exit(0);
}

int main() {
    signal(SIGALRM, handle_sigalrm);

    printf("Setting an alarm for 5 seconds...\n");
    alarm(5);

    while (1) {
        printf("Waiting for the alarm to go off...\n");
        sleep(1);
    }

    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 8d.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Setting an alarm for 5 seconds...
Waiting for the alarm to go off...
Waiting for the alarm to go off...
Waiting for the alarm to go off...
Waiting for the alarm to go off...
Waiting for the alarm to go off...
Caught signal 14: Alarm signal received.
*/
