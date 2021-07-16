/* 	Write a program to simulate online ticket reservation. 
	Implement write lock
	Write a program to open a file, store a ticket number and exit. 
	Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print
	the new ticket number then close the file. 	*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
//#include "ticket_system_17.txt"

int main(){
	
	int t = 0;
	int fd = open("ticket_system_17.txt",  O_RDWR);
	
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	
	int fcn=fcntl(fd, F_SETLKW, &lock);
	if(fcn<0){perror("FCNTL::");}
	
	
	int ticket_number;
	int read_file=read(fd,&ticket_number,sizeof(ticket_number));
	//printf("%d\n",read_file);
	
	ticket_number++;
	
	//off_t lseek(int fd, off_t offset, int whence);// 
	off_t seek=lseek(fd,0,SEEK_SET);
	int wr=write(fd, &ticket_number, sizeof(ticket_number));
	
	printf("Incremented successfully.\n");
	printf("New ticket number: %d\n", ticket_number);
	
	sleep(10);
	
	lock.l_type = F_UNLCK;
	int fl=fcntl(fd, F_SETLKW, &lock);
	if(fl<0){perror("ERROR:");}
	close(fd);
	return 0;
	 
}

