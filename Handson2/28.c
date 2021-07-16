/*
28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
*/
#include <stdio.h>
#include<string.h>
#include <sys/ipc.h> 
#include <sys/msg.h>
int main()
{	struct msqid_ds mq;

	key_t key= ftok("hello.txt", 32);
	int msgid = msgget(key,  IPC_CREAT|0744);
	if(msgid<0){perror("ID ERROR");}
	//msgctl(msgid, IPC_SET, mq.msg_perm.mode);
	

	msgctl(msgid, IPC_STAT, &mq);
	printf("Before change: the mode  : %03o\n",mq.msg_perm.mode);
	printf("want to change the mode? 0 for NO and 1 for YES...\nGive your input...[0/1] ");
	int mode_queue;
	scanf("%d",&mode_queue);
	if(mode_queue==1)
	{	
		mq.msg_perm.mode = 0644;
		msgctl(msgid, IPC_SET, &mq);
		printf("new mode is : %03o\n",mq.msg_perm.mode);
	}
	else
	{
	printf("no change in mode ");
	}
	return 0;
}
