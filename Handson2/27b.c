/*
27. Write a program to receive messages from the message queue.
	a. with 0 as a flag
	b. with IPC_NOWAIT as a flag
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 

int main()
{

struct msgbuf {
long mtype;
char mtext[1024];
}msg;

key_t key= ftok(".", 101);
int msgid= msgget(key,  0);
//if(msgid==-1){
//	msgid=msgget(key,IPC_CREAT|0644);
//}
 
printf("Enter the type of the text::\n");
scanf("%ld",&msg.mtype);

//printf("enter the message... \n");
//scanf("%s",(char *)&msg.mtext);
//msgsnd(msgid, &msg, sizeof(msg), 0);
printf("message ID==%d\n",msgid);
int rc=msgrcv(msgid,&msg,sizeof(msg),msg.mtype,IPC_NOWAIT);

printf("message read  :%s\n",msg.mtext);


return 0;}

