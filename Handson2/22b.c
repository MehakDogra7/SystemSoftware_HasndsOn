/*
22. Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/time.h>
#include<fcntl.h>
int main()
{
	int fd = open("file_22a.txt", O_WRONLY);
	printf("Data for Program 1: ");
	char buffer[100];
	fgets(buffer, 100, stdin);
	write(fd, buffer, sizeof(buffer));
	close(fd);
return 0;}

/*
21b
fd = open(“22_fifoFile”, O_WRONLY);
write(fd, “Hey there”, sizeof(“Hey there”))
*/
