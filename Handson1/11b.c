/*11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int fd=open("dummy_11b.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
//int dup2(int oldfd, int newfd);
// If the file descriptor newfd was previously  open, it is silently closed before being reused.
int fd_duplicate_2=dup2(fd,10);
printf("The value of the original file descriptor ==%d\n",fd);
printf("The value of the duplicate file descriptor ==%d\n",fd_duplicate_2); //size will be 10 only
char buffer[]="A b C d E f G h\nI j K \nl M n O p \nQ r S t U v \nW x Y z\n";

int wr=write(fd,buffer,sizeof(buffer));

int wr_dup=write(fd_duplicate_2,"This is the content from \nduplicated descriptor\n",50);

return 0;
}
