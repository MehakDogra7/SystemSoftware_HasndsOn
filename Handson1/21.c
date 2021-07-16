/*21. Write a program, call fork and print the parent and child process id.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{

    //pid_t getpid(void);
    //pid_t getpid(void);
    pid_t process_id = fork();
    
    /*On success, the PID of the child process is returned in the parent, and
       0  is returned in the child.  On failure, -1 is returned in the parent,
       no child process is created, and errno is set appropriately.*/
	if (process_id == -1)
	{
		perror("fork()");
	}
	else if(process_id == 0)
	{
		printf("Child's Process ID== %d\nAND its parent process id=%d\n", getpid(),getppid());
		//getpid() returns the process ID (PID) of the calling process.
	}
	else
	{
		printf("Parent's Process ID== %d\n\n", getpid());
	}
return 0;
}
