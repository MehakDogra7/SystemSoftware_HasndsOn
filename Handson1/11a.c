/*11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
int main()
{
int fd1=open("dummy_11a.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
int fd_duplicate=dup(fd1);
if(fd_duplicate<0)
{
	perror("File not duplicated::");
}

printf("The value of the original file descriptor ==%d\n",fd1);
printf("The value of the duplicate file descriptor ==%d\n",fd_duplicate);
char buf[]="Hello World...\nThis is a new life...\nHow is this life going on!!!\n";
int wr=write(fd1,buf,sizeof(buf));

int fd_read=write(fd_duplicate,"My name is DUMMY FILE 11\n",25);
//I am able to edit the file dummy_11a.txt usind the duplicated file descriptor fd_duplicate
return 0;
}
