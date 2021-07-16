/*
7. Write a simple program to print the created thread ids.
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>   
#include <unistd.h>
#include <pthread.h>
void *threadFunc(void *data) 
{
pthread_t thread_id = pthread_self();
printf("Thread ID's== %ld\n",thread_id);
}
 
 int main()
 {
 pthread_t tid;
 pthread_create(&tid,NULL,threadFunc,NULL);
 /*
 	int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
 */
 pthread_exit(NULL);
 
 return 0;
 }
//gcc filename.c -pthread
//gcc -pthread filename.c

