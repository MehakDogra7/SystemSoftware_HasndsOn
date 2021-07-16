/*17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. 
Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int main(){
	int ticket_number;
	//struct ticketno ticket;
	
	//struct flock lock;
	
	int fd = open("ticket_system_17.txt", O_RDWR);
	if(fd<0){perror("Failed to open:");}
	
	ticket_number=0;
	printf("Current ticket number: %d\n", ticket_number);
	
	int wr=write(fd,&ticket_number, sizeof(ticket_number));
	if(wr<0){perror("ERROR");}
	
	close(fd);
	
	return 0;
}



