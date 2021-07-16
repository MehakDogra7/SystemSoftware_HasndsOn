/*
30. Write a program to create a shared memory.
	a. write some data to the shared memory
	b. attach with O_RDONLY and check whether you are able to overwrite.
	c. detach the shared memory
	d. remove the shared memory
*/
#include<stdio.h>
#include<sys/shm.h>

//int shmget(key_t key, size_t size, int shmflg);
int main()
{
  char *ptr;
  int key=ftok(".",10);
  printf("Message ID: %d\n",key);
  int shmid=shmget(key,1024,IPC_CREAT|0744);  
  
  ptr=shmat(shmid,0,0);  
  
  printf("Enter to write in shared memory :\n");
  scanf("%s[^ \n]",ptr); 
  printf("The data entered ==%s\n",ptr); 

return 0;}
