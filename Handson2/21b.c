/*
	Write two programs so that both can communicate by FIFO -Use one two communication.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int agrc, int const argv[]){
	
	
	char buffer_read[100], buffer_write[100];
	
	int fd_read = open("file_21_1", O_RDONLY);
	int fd_write = open("file_21_2", O_WRONLY);
	if(fd_read<0 || fd_write<0){perror("File didn't open");}
	
	if(read(fd_read, buffer_read, sizeof(buffer_read))<0) perror("READ");              
	printf("PRogram 1 says: %s",buffer_read);
	
	printf("Enter the message for Program 1:");  
	fgets(buffer_write, 100, stdin);                          
	if(write(fd_write, buffer_write, sizeof(buffer_write))<0)perror("Write");  
	
	close(fd_read);
	close(fd_write);
	
	return 0;
}

