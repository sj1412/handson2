/*
============================================================================
Name : 8g.c
Author : Soumya Jain
Description :Write a separate program using signal system call to catch the following signals.
g.SIGPROF (use setitimer system call)
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>

void handle_sigprof(int sig) {
    printf("Caught signal %d: Profiling timer alarm received.\n", sig);
    exit(0);
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, handle_sigprof);

    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1) {
	printf("Waiting...\n");
        for (int i = 0; i < 10000000; i++);
    }

    return 0;
}
/*output:
Waiting...
Waiting...
Waiting...
Waiting...
Caught signal 27: Profiling timer alarm received.
*/

