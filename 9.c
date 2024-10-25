/*
============================================================================
Name : 9.c
Author : Soumya Jain
Description :Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void handle_sigint(int sig) {
    printf("Ignoring SIGINT (Ctrl+C)\n");
}

int main() {
    signal(SIGINT, handle_sigint);

    printf("SIGINT is currently ignored.\n");
    sleep(10);
    signal(SIGINT, SIG_DFL);

    printf("SIGINT: default action.\n");
    sleep(5);

    printf("Program finished.\n");
    return 0;
}
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ nano 8.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
SIGINT is currently ignored.
^CIgnoring SIGINT (Ctrl+C) {here even after ctrl+c the program didn't terminate because the signal sigint was handled}
SIGINT: default action.{After 10sec sigint was set to it's default action}
^C {As sigint to its default action, the program was now terminated with the help of ctrl+C}
*/
