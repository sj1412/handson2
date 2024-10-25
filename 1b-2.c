/*
============================================================================
Name : 1b-2.c(1b part2)
Author : Soumya Jain
Description : Write a separate program (for each time domain) to set a interval>
10micro second
a.ITIMER_VIRTUAL
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void timer_handler(int signum) {
    printf("10 micro seconds timer expired!\n");
}

int main() {
    struct itimerval timer;


    signal(SIGVTALRM, timer_handler);


    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(EXIT_FAILURE);
    }


    while (1) {

        for (volatile int i = 0; i < 100000; i++);
    }

    return 0;
}
/*OUTPUT:
"10 micro seconds timer expired!" statement printed in every 10 micro seconds.
*/
