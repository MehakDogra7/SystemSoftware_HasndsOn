/*
	17. Write a program to execute ls -l | wc.
			a. use dup
			b. use dup2
			c. use fcntl
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
//ls -l | wc.
int pipe1[2];
	if(pipe(pipe1)<0){perror("PIPE");}
	int child_pid=fork();
	if(child_pid<0){perror("Child not created::");}
	else if(child_pid==0)
	{
		close(1);   // close STDOUT, dup pipe[1], close rest and execl command
		close(pipe1[0]);
		printf("This is the child process...\n");
		if(dup(pipe1[1]) == -1) 
				{perror("dup()");}
		
		if(execl("/bin/ls", "ls", "-l",  NULL) == -1)
				{perror("execl()");	}	
	}
	else
	{
		close(0);   //close STDIN, dup pipe[0], close rest and execl command	
		close(pipe1[1]);	
		printf("This is the parent process...\n");
		if(dup(pipe1[0]) == -1)
				{ perror("dup()");}
		if(execl("/usr/bin/wc", "wc",  NULL) == -1)
				{ perror("execlp()");}
	}

return 0;}
/*
int pipe1[2];
pipe(pipe1);
int child_pid = fork();
if(child_pid == 0){
// close STDOUT, dup pipe[1], close rest and execl command
}else{
// close STDIN, dup pipe[0], close rest and execl command
}
*/
