/*
============================================================================
Name : 10c.c
Author : Soumya Jain
Description :Write a separate program using sigaction system call to catch the following signals.
c.SIGFPE
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

void handle_sigfpe(int signum) {
    printf("Caught SIGFPE (Floating Point Exception)\n");
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa_sigfpe;

    sa_sigfpe.sa_handler = handle_sigfpe;
    sa_sigfpe.sa_flags = 0;
    sigemptyset(&sa_sigfpe.sa_mask);
    sigaction(SIGFPE, &sa_sigfpe, NULL);

    while (1) {
        printf("Working...\n");
        sleep(1);

        int result = 1 / 0;
    }
    return 0;
}

/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ nano 10c.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 10c.c
10c.c: In function ‘main’:
10c.c:24:24: warning: division by zero [-Wdiv-by-zero]
   24 |         int result = 1 / 0;
      |                        ^
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Working...
Caught SIGFPE (Floating Point Exception)
*/
