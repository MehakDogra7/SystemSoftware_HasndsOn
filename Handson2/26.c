
/*
26. Write a program to send messages to the message queue. Check $ipcs -q
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
int main()
{
	struct msgbuf {
	long mtype;   /* message type, must be > 0 */
	char mtext[1024];/* message data */
	}msg;

		long int key = ftok(".",101);
		int msgid= msgget(key,0666|IPC_CREAT);

		printf("Enter the type of the text::\n");
		scanf("%ld",&msg.mtype);

		printf("enter the message... \n");
		scanf("%s",(char *)&msg.mtext);
		//int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
		msgsnd(msgid, &msg, sizeof(msg), 1);
		printf("Message sent to the message queue...\n");
		printf("data sent :: %s\n",msg.mtext);
		//msgctl(msgid, IPC_RMID, NULL);


return 0;}



/*

// create a key
// get the details of the message queue based on key
// set the msg type and message
// use msgid received from above step to set parameters in
msgsnd
msgsnd(msgid, &msg, strlen(msg.mtext)+1, 0);
*/
