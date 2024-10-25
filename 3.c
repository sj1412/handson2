/*
============================================================================
Name : 3.c
Author : Soumya Jain
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
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
	if( getrlimit(RLIMIT_NOFILE, &old_lim) == 0)
		printf("Old limits -> soft limit= %ld \t" " hard limit= %ld \n", old_lim.rlim_cur,old_lim.rlim_max); 
	else
		fprintf(stderr, "%s\n", strerror(errno)); 

	lim.rlim_cur = 3;
	lim.rlim_max = 1024;

	if(setrlimit(RLIMIT_NOFILE, &lim) == -1) 
		fprintf(stderr, "%s\n", strerror(errno));
	if( getrlimit(RLIMIT_NOFILE, &new_lim) == 0) 
		printf("New limits -> soft limit= %ld \t" " hard limit= %ld \n", new_lim.rlim_cur, new_lim.rlim_max); 
	return 0; 
} 
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ nano 3.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 3.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
Old limits -> soft limit= 1024 	 hard limit= 1048576 
New limits -> soft limit= 3 	 hard limit= 1024 
*/
