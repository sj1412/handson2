/*
============================================================================
Name : 13.c(part-1)
Author : Soumya Jain
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("this is program 1, Waiting for SIGSTOP.\n");
    while (1) {
        pause();
    }

    return 0;
}
