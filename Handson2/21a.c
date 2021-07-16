/*
	Write two programs so that both can communicate by FIFO -Use two way communication.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
	char buffer_read[100], buffer_write[100];
	
	int fd_write = open("file_21_1", O_WRONLY);
	if(fd_write<0 ){
		int file1 = mkfifo("file_21_1", 0644);
		if(file1<0 ){perror("MKFIFO()");}
		}
	
	int fd_read = open("file_21_2", O_RDONLY);
	if(fd_read<0){ 
		int file2 = mkfifo("file_21_2", 0644);
		if(file2<0){perror("MKFIFO()");}
		}
	
	printf("Enter the message for Program 2:");  
	fgets(buffer_write, 100, stdin);                           
	write(fd_write, buffer_write, sizeof(buffer_write));
	
	read(fd_read, buffer_read, sizeof(buffer_read));      
	printf("Program 2 says: %s",buffer_read);
	
	
	close(fd_read);
	close(fd_write);
return 0;	
}
/*
mkfifo("21a_fifoFile",
S_IWGRP|S_IRGRP|S_IRUSR|S_IWUSR|S_IROTH);
mkfifo("21b_fifoFile",
S_IWGRP|S_IRGRP|S_IRUSR|S_IWUSR|S_IROTH);
fdw = open("21a_fifoFile", O_WRONLY);
fdr = open("21b_fifoFile", O_RDONLY);
write(fdw, buff_w, sizeof(buff_w));
read(fdr, buff_r, sizeof(buff_r));
*/
