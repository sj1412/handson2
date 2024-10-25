/*
============================================================================
Name : 1a-2.c(1a part2)
Author : Soumya Jain
Description : Write a separate program (for each time domain) to set a interval>
10micro second
a.ITIMER_REAL
Date: 21st September, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void timer_handler(int signum) {
    printf("Timer expired after 10 seconds!\n");
}

int main() {
    struct itimerval timer;

    signal(SIGALRM, timer_handler);
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 0;
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    while (1) {
        pause();
    }

    return 0;
}
/*output:
code printed "Timer expired after 10 seconds!" in every 10 sec infinitely.
*/
