/*
============================================================================
Name : 4.c
Author : Soumya Jain
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 21st September, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>


static inline uint64_t rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ (
        "rdtsc"
        : "=a" (lo), "=d" (hi)
    );
    return ((uint64_t)hi << 32) | lo;
}

int main() {

    uint64_t start, end;

    start = rdtsc();

    for (int i = 0; i < 100; i++) {
        getppid();
    }

    end = rdtsc();
    uint64_t timetaken = end - start;
    printf("Time taken for 100  getppid() calls: %lu cycles\n", timetaken);

    return 0;
}
/*soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ nano 4.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 4.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Time taken for 100  getppid() calls: 546093 cycles
*/
