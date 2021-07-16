/*
12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>  
#include <unistd.h>

int main()

{
pid_t process_id=fork();
/*parent finishes execution and exits while the child process is still executing and is called an orphan process now.*/
if(process_id==-1)
{
	perror("Child not created");
}
else if(process_id==0)
{
	
	printf("Child process is here....\n");
	printf("Process ID of the child==%d\n",getpid());
	printf("Parent ID of the child before parent is Killed==%d\n",getppid());
	sleep(2);
	if(kill(getppid(), SIGKILL) == -1) perror("kill()");
	sleep(5);
	
	printf("Killed....\nParent ID of the child after the parent process is killed==%d\n",getppid());
	
}
else{
	printf("Parent process is here....\n");
	printf("Process ID of the parent==%d\n",getpid());
	sleep(20);
	
}

return 0;
}

/*
fork();
// parent process, put parent in sleep
// child process
// check parent pid before kill , print your ppid
kill(parent_pid, SIGKILL); //getppid()
// sleep for few seconds for kill effect
// check parent pid after kill //getppid()
*/
