/*
============================================================================
Name : 12.c
Author : Soumya Jain
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void handle_signal(int sig) {
    printf("Parent process received SIGKILL signal.\n");
    exit(0);
}

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        signal(SIGKILL, handle_signal);
        printf("Parent process (PID: %d) is going to sleep.\n", getpid());
        sleep(5);
        wait(NULL);
    } if(pid==0) {
        printf("Child process (PID: %d) \n", getpid());
        sleep(1);
        printf("Child process (PID: %d) is sending SIGKILL to parent (PID: %d).\n", getpid(), getppid());
        kill(getppid(), SIGKILL);
        exit(0);
    }
    return 0;
}
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ nano 12.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 12.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Parent process (PID: 4253) is going to sleep.
Child process (PID: 4254) 
Child process (PID: 4254) is sending SIGKILL to parent (PID: 4253).
Killed
*/
