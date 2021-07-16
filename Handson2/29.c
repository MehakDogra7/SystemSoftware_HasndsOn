/*
29. Write a program to remove the message queue.
*/

#include <stdio.h>
#include<string.h>
#include <sys/ipc.h> 
#include <sys/msg.h>

int main()
{int rem;
	key_t key= ftok("hello.txt", 32);
	int msgid = msgget(key,  IPC_CREAT|0744);
	if(msgid<0){perror("ID ERROR");}
	printf("Do you want to remove the queue...[0/1]:");
	scanf("%d",&rem);
	if(rem==1){
	msgctl(msgid,IPC_RMID,0);
	printf("Removed successfully.....\n");
	}
return 0;}
