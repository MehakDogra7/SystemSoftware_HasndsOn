/*
	24. Write a program to create a message queue and print the key and message queue id.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int main()
{
    key_t key = ftok(".", 67);
    int msg_id = msgget(key, IPC_CREAT|IPC_EXCL|0744);
    if(msg_id == -1)
    {
        printf("ERROR");
        exit(0);
    }
    printf("Message queue identifier %d for key==:%d\n", msg_id,key);
return 0;}

/*
key = ftok(".", 67);
msgid = msgget(key, IPC_CREAT|IPC_EXCL|0744);
*/

//queue numbering always continues from the next number. the same number won't be assigned again until the system is not turned off
