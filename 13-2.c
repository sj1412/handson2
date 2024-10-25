/*
============================================================================
Name : 13.c(part-2)
Author : Soumya Jain
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 21st September, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    
    pid_t target_pid;
    printf("In program 2.Enter the PID of Program 1: ");
    scanf("%d", &target_pid);

    printf("Sending SIGSTOP to program 1 with PID %d.\n", target_pid);
    kill(target_pid, SIGSTOP);

    return 0;
}
