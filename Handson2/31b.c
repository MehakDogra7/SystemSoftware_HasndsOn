/*
31. Write a program to create a semaphore and initialize value to the semaphore.
	a. create a binary semaphore
	b. create a counting semaphore
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>
union semun{

//man 7 sysvipc
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
};
int main(){
	union semun var;
	
	int key=ftok(".",0644);
	printf("Enter the value you want to set for semaphose\n");
	int a;
	scanf("%d",&a);
	var.val=a;
	
	int semid=semget(key,1,IPC_CREAT|IPC_EXCL|0744);
	printf("The ID of the semaphore ==%d\n",semid);
	
	semctl(semid,0,SETVAL,var);
	printf("Value of semaphore=%d\n",var.val);
	printf("Successfullt created\n");
return 0;}

/*
union semun arg;
// set the key
Key_t key = ftok(‘.’, 112);
semid = semget(key, 1, IPC_CREAT|0644);
// set the val in arg to the semaphore value
arg.val = 1; // more than 1 for counting semaphore
semctl(semid, 0, SETVAL, arg);
*/
