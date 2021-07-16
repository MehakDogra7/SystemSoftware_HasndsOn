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
  
  ptr=shmat(shmid,(void *)0,0);
  printf("Before removing the ID of shared memory=%d\n",shmid);
  printf("Before removing the data in shared memory=%s\n",ptr);
  
  printf("Detaching from shared memory\n");
  int shm=shmdt(ptr); 
  if(shm<0){perror("Detachment ERROR::");}
  else {
  	printf("the id of attached memory is  %d\n",shm);
  	//printf("value :%s\n",ptr);//once detached it will give the segmentation fault....
  	}
  
  printf("Removing the shared memory\n");
  int rmv=shmctl(shmid,IPC_RMID,NULL);
  printf("The value removed==%d\n",rmv);
  //printf("after removing the ID of shared memory=%d\n",shmid);
  //printf("After removing the data in shared memory=%s\n",ptr);
    
return 0;}

/*
Message ID: 167907563
Before removing the ID of shared memory=589827
Before removing the data in shared memory=IIITB
Detaching from shared memory
the id of attached memory is  0
Removing from shared memory
The value removed==0

*/
  
