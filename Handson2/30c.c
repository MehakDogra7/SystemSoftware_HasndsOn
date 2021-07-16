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
  
  /*void *shmat(int shmid, const void *shmaddr, int shmflg);
       int shmdt(const void *shmaddr);*/
  
  ptr=shmat(shmid,0,0);  
  printf("value :%s\n",ptr);
  
  printf("Detaching from shared memory\n");
  int shm=shmdt(ptr); 
  if(shm<0){perror("Detachment ERROR::");}
  else {
  	printf("the id of attached memory is  %d\n",shm);
  	printf("value :%s\n",ptr);//once detached it will give the segmentation fault....
  	}
  

  return 0;
}
