/*
  6. Write a simple program to create three threads
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>   
#include <unistd.h>
#include <pthread.h>

void *threadFunc(void *data) {
		static int tid = 1;
		printf("Thread created with tid= %d \n",tid);
		tid++;
	}
	
int main()
{
/*
  int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
*/
pthread_t tid;
// tid = 1
if((pthread_create(&tid, NULL, threadFunc, NULL))<0) perror("pthread");sleep(1);
// tid = 2
if((pthread_create(&tid, NULL, threadFunc, NULL))<0) perror("pthread");sleep(1);
// tid =3
if((pthread_create(&tid, NULL, threadFunc, NULL))<0) perror("pthread");
//pthread_create(&tid, NULL, threadFunc, NULL); // tid = 2
//pthread_create(&tid, NULL, threadFunc, NULL); // tid = 3

sleep(1);
pthread_exit(NULL);

return 0;}

/*
	to compile the code on terminal
	gcc -pthread 06.c
	
	this is because Pthread is explicitly not added to gcc, you got to add it using gcc -pthread 6.c
*/
