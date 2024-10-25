/*
============================================================================
Name : 7.c
Author : Soumya Jain
Description :Write a simple program to print threads ids.
Date: 21st September, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void* func(void* p) {
   printf("From the function, the thread id = %lu\n", pthread_self()); 
      pthread_exit(NULL);
   return NULL;
}
void main() {
   pthread_t thread;
   pthread_create(&thread, NULL, func, NULL);
   pthread_join(thread, NULL);
}
/*output:
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cc 7.c
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ ./a.out
From the function, the thread id = 139980246611648
*/
