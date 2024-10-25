/*
============================================================================
Name : 2.c
Author : Soumya Jain
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 21st September, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

        struct rlimit old_lim, lim, new_lim;
        if( getrlimit(RLIMIT_CORE, &old_lim) == 0)
        {
              printf("Core file limit: Old limits -> soft limit= %ld \t"
                        " hard limit= %ld \n", old_lim.rlim_cur,old_lim.rlim_max);
        }
if( getrlimit(RLIMIT_NOFILE, &old_lim) == 0)
        {
              printf("fd limit:Old limits -> soft limit= %ld \t"
                        " hard limit= %ld \n", old_lim.rlim_cur,old_lim.rlim_max);
        }
if( getrlimit(RLIMIT_DATA, &old_lim) == 0)
        {
              printf("Data segment size:Old limits -> soft limit= %ld \t"
                        " hard limit= %ld \n", old_lim.rlim_cur,old_lim.rlim_max);
        }
if( getrlimit(RLIMIT_FSIZE, &old_lim) == 0)
        {
              printf("File size:Old limits -> soft limit= %ld \t"
                        " hard limit= %ld \n", old_lim.rlim_cur,old_lim.rlim_max);
        }
if( getrlimit(RLIMIT_STACK, &old_lim) == 0)
        {
              printf("Stack size:Old limits -> soft limit= %ld \t"
                        " hard limit= %ld \n", old_lim.rlim_cur,old_lim.rlim_max);
        }
if( getrlimit(RLIMIT_AS, &old_lim) == 0)
        {
              printf("Total available memory:Old limits -> soft limit= %ld \t"
                        " hard limit= %ld \n", old_lim.rlim_cur,old_lim.rlim_max);
        }

}
/*output:
oumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1$ cd hl2
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ nano 1.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 1.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Core file limit: Old limits -> soft limit= 0 	 hard limit= -1
fd limit:Old limits -> soft limit= 1024 	 hard limit= 1048576
Data segment size:Old limits -> soft limit= -1 	 hard limit= -1
File size:Old limits -> soft limit= -1 	 hard limit= -1
Stack size:Old limits -> soft limit= 8388608 	 hard limit= -1
Total available memory:Old limits -> soft limit= -1 	 hard limit= -1
*/
