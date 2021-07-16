/*7. Write a program to copy file1 into file2 ($cp file1 file2).*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>

int main()
{
  //char file[]="dummy_7.txt";
  int fd=open("dummy_7.txt",O_RDONLY);
  char buffer[512];
  int fdread=read(fd,buffer,sizeof(buffer));
  int fd_tocopyin=open("dummy_7_copy.txt",O_CREAT|O_RDWR|O_TRUNC,0644);
  
  if (fd < 0 || fd_tocopyin < 0)
	{
		perror("File didn't open");
	}

   write(fd_tocopyin,buffer,fdread);
   
		
  close(fd);
  close(fd_tocopyin);
return 0;  
}
