/*
32. Write a program to implement semaphore to protect any critical
section.
		a. rewrite the ticket number creation program using semaphore
		b. protect shared memory from concurrent write access
		c. protect multiple pseudo resources ( may be two) using counting
		semaphore
		d. remove the created semaphore
*/
 // to compile gcc -lpthread 32d.c
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include <semaphore.h>

sem_t semaphore;

int main()
{
  int create=sem_init(&semaphore, 0,1);
  if(create == -1)
 	{perror("creat()");}
  else
  printf("created semaphore\n");

  int del=sem_destroy(&semaphore);
  if(del == -1)
  	{perror("Delete()");}
  else
  printf("Deleted semaphore... \n");
  return 0;

}
