/*12. Write a program to find out the opening mode of a file. Use fcntl*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
/* F_GETFL (void)
              Return (as the function result) the file access mode and the file status
              flags; arg is ignored.
*/
int fd=open("dummy_12.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
int flag_val = fcntl(fd, F_GETFL);
if(flag_val < 0) {
	perror("flag error::");
}
printf("Opening mode of the file :: ");
if((flag_val & O_ACCMODE) == O_RDONLY) //O_ACCMODE
		printf("READ ONLY\n");

if((flag_val & O_ACCMODE) == O_WRONLY) 
		printf("WRITE ONLY\n");
	
if((flag_val & O_ACCMODE) == O_RDWR)
		printf("READ-WRITE MODE\n");
return 0;
}
