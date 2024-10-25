/*
============================================================================
Name : 5.c
Author : Soumya Jain
Description :Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_system_limits() {

    long arg_max = sysconf(_SC_ARG_MAX);
    if (arg_max != -1) {
        printf("Maximum length of arguments to exec family: %ld bytes\n", arg_max);
    } else {
        perror("Error fetching ARG_MAX");
    }

      long max_processes = sysconf(_SC_CHILD_MAX);
    if (max_processes != -1) {
        printf("Maximum number of simultaneous processes per user ID: %ld\n", max_processes);
    } else {
        perror("Error fetching CHILD_MAX");
    }

  
    long clock_ticks = sysconf(_SC_CLK_TCK);
    if (clock_ticks != -1) {
        printf("Number of clock ticks per second: %ld\n", clock_ticks);
    } else {
        perror("Error fetching CLK_TCK");
    }

  
    struct rlimit open_files_limit;
    if (getrlimit(RLIMIT_NOFILE, &open_files_limit) == 0) {
        printf("Maximum number of open files: %ld\n", (long)open_files_limit.rlim_cur);
    } else {
        perror("Error fetching RLIMIT_NOFILE");
    }

  
    long page_size = sysconf(_SC_PAGESIZE);
    if (page_size != -1) {
        printf("Size of a memory page: %ld bytes\n", page_size);
    } else {
        perror("Error fetching PAGESIZE");
    }

      long total_pages = sysconf(_SC_PHYS_PAGES);
    if (total_pages != -1) {
        printf("Total number of pages in physical memory: %ld\n", total_pages);
    } else {
        perror("Error fetching PHYS_PAGES");
    }

    long avail_pages = sysconf(_SC_AVPHYS_PAGES);
    if (avail_pages != -1) {
        printf("Number of currently available pages in physical memory: %ld\n", avail_pages);
    } else {
        perror("Error fetching AVPHYS_PAGES");
    }
}

int main() {
    print_system_limits();
    return 0;
}
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 5.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Maximum length of arguments to exec family: 2097152 bytes
Maximum number of simultaneous processes per user ID: 30980
Number of clock ticks per second: 100
Maximum number of open files: 1024
Size of a memory page: 4096 bytes
Total number of pages in physical memory: 2001493
Number of currently available pages in physical memory: 1002917
*/
