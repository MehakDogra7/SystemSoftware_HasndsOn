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
int fd=open("dummy_11c.txt",O_CREAT|O_WRONLY|O_TRUNC,0644);
char buf[]="Good morning Palampur...\nI will miss you the most when I will leave...\n";
/*F_DUPFD (int)
              Duplicate the file descriptor fd  using  the  lowest-numbered  available
              file  descriptor  greater  than or equal to arg.  This is different from
              dup2(2), which uses exactly the file descriptor specified.

              On success, the new file descriptor is returned.
*/
int fd_duplicate_3=fcntl(fd, F_DUPFD,10);
printf("File descriptor of file==%d\n",fd);
printf("Duplicated File descriptor==%d\n",fd_duplicate_3);
		if(fd<0)
		{
			perror("File not duplicated::");
		}
int wr_original=write(fd,buf,sizeof(buf));
		if(wr_original<0){
			perror("write failed::");
		}
char buf_dup[]="This is the duplicated data...\nGetting printed into the original...\n";
int wr_duplicate=write(fd_duplicate_3,buf_dup,sizeof(buf_dup));
		if(wr_duplicate<0){
			perror("write failed::");
		}
return 0;}
