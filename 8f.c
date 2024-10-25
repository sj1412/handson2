/*
============================================================================
Name : 8f.c
Author : Soumya Jain
Description :Write a separate program using signal system call to catch the following signals.
f.SIGVTALRM(use stetimer system call)
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>

void handle_sigvtalrm(int sig) {
    printf("Caught signal %d: Virtual timer alarm received.\n", sig);
    exit(0);
}

int main() {
    struct itimerval timer;

    signal(SIGVTALRM, handle_sigvtalrm);

    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1) {
	printf("Waiting for virtual timer...\n");
        for (int i = 0; i < 100000; i++);
    }

    return 0;
}

/*output:
Waiting for virtual timer...
Waiting for virtual timer...
Waiting for virtual timer...
Caught signal 26: Virtual timer alarm received.
*/

