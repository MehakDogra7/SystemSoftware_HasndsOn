/*
31. Write a program to create a semaphore and initialize value to the semaphore.
	a. create a binary semaphore
	b. create a counting semaphore
*/

 #include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>
union sem{
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
};
int main(){
	union sem var;
	int key=ftok(".",0644);
	//int semget(key_t key, int nsems, int semflg);
	int semid=semget(key,1,IPC_CREAT|IPC_EXCL|0744);
	
	printf("The ID of the semaphore ==%d\n",semid);
		
	var.val=1;
	semctl(semid,0,SETVAL,var);
	printf("Successfullt created\n");
return 0;}
