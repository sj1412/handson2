/*
============================================================================
Name : 8e.c
Author : Soumya Jain
Description :Write a separate program using signal system call to catch the following signals.
e.SIGALRM(use settimer system call)
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigalrm(int sig) {
    printf("Caught signal %d: Alarm signal received from setitimer.\n", sig);
    exit(0);
}

int main() {
    struct itimerval timer;

    signal(SIGALRM, handle_sigalrm);

    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        printf("Waiting for the timer to go off...\n");
        sleep(1);
    }

    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 8e.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Waiting for the timer to go off...
Waiting for the timer to go off...
Waiting for the timer to go off...
Caught signal 14: Alarm signal received from setitimer.
*/
