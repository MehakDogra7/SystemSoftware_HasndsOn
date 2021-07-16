/*
25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
	a. access permission
	b. uid, gid
	c. time of last message sent and received
	d. time of last change in the message queue
	d. size of the queue
	f. number of messages in the queue
	g. maximum number of bytes allowed
	h. pid of the msgsnd and msgrcv
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include<time.h>
int main()
{
//man 7 sysvipc

/*
struct msqid_ds mq;
key = ftok(".", 67);
msgid = msgget(key, 0);
msgctl(msgid, IPC_STAT, &mq);
*/
struct ipc_perm  ipc;
struct msqid_ds   msg;

	key_t key = ftok("hello.txt", 67);       
	int msg_id = msgget(key, 0);   
	if(msg_id<0){perror("msg_id()");}   
	
	int msg_ctl=msgctl(msg_id, IPC_STAT, &msg);//Retrieves the msqid_ds structure for a queue, and stores it in the address of the buf argument.
	if(msg_ctl<0){perror("msgctl()");}
	
	ipc = msg.msg_perm;
	
	printf("Access Permissions : %03o \n", ipc.mode & 0777);
	printf("UID : %d \n", ipc.uid);
	printf("Gid : %d\n", ipc.gid);
	printf("Time of last message sent: %s\n", ctime(&msg.msg_stime));
	printf("Time of last message received: %s\n", ctime(&msg.msg_rtime));
	printf("Time of last change in message queue: %s\n", ctime(&msg.msg_ctime));
	printf("Size of the message queue : %lu\n", msg.__msg_cbytes);
	
	printf("Number of the messages in the queue : %lu\n", msg.msg_qnum);
	printf("Maximum number of bytes allowed : %lu\n", msg.msg_qbytes);
	printf("PID of msgsnd : %d\n", msg.msg_lspid);
	printf("PID of msgrcv : %d\n", msg.msg_lrpid);

return 0;}

/*
struct msqid_ds {
               struct ipc_perm msg_perm;
               msgqnum_t       msg_qnum;     no of messages on queue 
               msglen_t        msg_qbytes;   bytes max on a queue 
               pid_t           msg_lspid;    PID of last msgsnd(2) call 
               pid_t           msg_lrpid;    PID of last msgrcv(2) call 
               time_t          msg_stime;    last msgsnd(2) time 
               time_t          msg_rtime;    last msgrcv(2) time 
               time_t          msg_ctime;    last change time 
           };


struct ipc_perm {
               uid_t          cuid;    creator user ID 
               gid_t          cgid;    creator group ID 
               uid_t          uid;     owner user ID 
               gid_t          gid;     owner group ID 
               unsigned short mode;    r/w permissions 
           };


*/
