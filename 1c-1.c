/*
============================================================================
Name : 1c-1.c(1c part1)
Author : Soumya Jain
Description : Write a separate program (for each time domain) to set a interval>
10micro second
a.ITIMER_PROF
Date: 21st September, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void timer_handler(int signum) {
    printf("10 seconds elapsed!\n");
}

int main() {
    struct itimerval timer;


    struct sigaction sa;
    sa.sa_handler = timer_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGPROF, &sa, NULL);


    timer.it_value.tv_sec =0;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec =10;
    setitimer(ITIMER_PROF, &timer, NULL);
    while (1) {
        pause();
    }

    return 0;
}
