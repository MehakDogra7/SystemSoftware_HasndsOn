/*16. Write a program to perform mandatory locking.
a. Implement write lock
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() 
{
	struct flock lock;
	int fd= open("dummy_16a.txt", O_RDWR|O_CREAT|O_TRUNC,0644);
		lock.l_type = F_WRLCK; //Write Lock
		lock.l_whence = SEEK_SET; // offset base is start of the file
		lock.l_start = 0;
		lock.l_len = 0;
		lock.l_pid = getpid();
	
	printf("Write Lock Mode:(Acquiring Lock)\n");
	int file = fcntl(fd, F_SETLKW, &lock);
	//int fcntl(int fd, int cmd, ... /* arg */ );
/*fcntl() can take an optional third argument.  Whether or not this argument is required is determined by cmd.  The required argument
       type is indicated in parentheses after each cmd name */
	if(file<0)
	{
		perror("FCNTL::\n");
	}
	printf("Inside the Critical Section:\n");
	printf("Press any key to unlock:\n");
	//printf("Value of lock: %d\n",ret);
	
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("Unlocked!\n");
	printf("Lock released!\n");
return 0;
}
