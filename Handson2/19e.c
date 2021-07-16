/*
19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
 {
 
 //int mkfifo(const char *pathname, mode_t mode);

 const char file[]="file_19e.txt";
 	int f2=mkfifo(file,0644);
 	
 	if(f2==0)
 	printf("FIFO file created\n");
 	else
 	perror("FIFO failed because");
 return 0;
 }
