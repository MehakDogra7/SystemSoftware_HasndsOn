/*
	Program to implement Mandatory Locking
	b) Read Lock
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>



int main() {
	struct flock lock;
	int fd= open("dummy_16b.txt", O_RDWR|O_CREAT|O_TRUNC,0644);
	lock.l_type = F_RDLCK; //Read Lock
	lock.l_whence = SEEK_SET;  // offset base is start of the file
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	
	printf("Acquiring Read Lock:\n");
	int file_read = fcntl(fd, F_SETLKW, &lock);
	//int fcntl(int fd, int cmd, ... /* arg */ );
/*fcntl() can take an optional third argument.  Whether or not this argument is required is determined by cmd.  The required argument
       type is indicated in parentheses after each cmd name */
       if(file_read<0)
	{
		perror("FCNTL::");
	}
	printf("Inside the Critical Section\nAcquired READ lock.:\n");
	printf("Press any key to unlock:\n");
	
	getchar();
	printf("Unlocked!\n");
	lock.l_type = F_UNLCK;
	int release=fcntl(fd, F_SETLK, &lock);
	if(release<0){perror("LOCK NOT RELEASED:");}
	printf("Lock released!\n ");
	return 0;
}
