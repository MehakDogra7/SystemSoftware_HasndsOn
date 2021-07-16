/*23. Write a program to create a Zombie state of the running program.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
/*A child process always first becomes a zombie before being removed from the process table. The parent process reads the exit status of the child process which reaps off the child process entry from the process table.*/
pid_t process_id=fork();
if(process_id<0)
{
     perror("Failed to create the child process.\n");
}
else if(process_id==0)
{
	
	printf("Child Process says HELLO!!!!!\n");
	printf("process ID of the child=%d\n",getpid());
	printf("Parent process ID of the child=%d\n",getppid());
	exit(0);
	//child process exits while the parent process is sleeping for 20 sec
	//it ended but it still have the entryin process table
}
else
{
	sleep(20);
	printf("Parent process says BYE!!!\n");
	printf("process ID of the parent=%d\n",getpid());
}

return 0;
}
