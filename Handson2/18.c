/*
18. Write a program to find out total number of directories on the pwd execute ls -l | grep ^d | wc ? Use only dup2.
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
//ls -l | grep ^d | wc
	int pipe1[2],pipe2[2];
	if(pipe(pipe1)<0  || pipe(pipe2)<0){perror("PIPE");}
	
	int child_pid=fork();
	if(child_pid<0)
		{perror("FORK");}
	else if(child_pid==0)
	{
		// close STDOUT, dup2(pipe1[1],1), close rest and execl
		close(1);
		close(pipe1[0]);
		printf("This is the child process...\n");
		if(dup2(pipe1[1],1)<0)
				{perror("DUP2");}
		if(execl("/bin/ls","ls","-l",NULL)<0)
				{perror("ECECL()1::");}
	}
	else
	{
		int child_pid2=fork();
		if(child_pid2<0){perror("FORK");}
		
		
		else if(child_pid2==0)
		{
		// close STDIN, dup2(pipe1[0],0), close STDOUT,
			close(0);
			close(pipe1[1]);
			close(pipe2[0]);
			if(dup2(pipe1[0],0)<0)
					{perror("DUP2");}
			if(dup2(pipe2[1],1)<0){perror("DUP2");}
			if(execl("/usr/bin/grep","grep","^d",NULL)<0)
			          {perror("Execl()2::");}
		}
		else{
		 // close STDIN, dup2(pipe2[0],0) close rest and execl
			close(0);
			close(pipe2[1]);
			close(pipe1[1]);
			if(dup2(pipe2[0],0)<0)
				{perror("DUP2");}
			if(execl("/usr/bin/wc","wc",NULL)<0)
			{
				perror("EXECL()3");
			}
			
		}
		
	}

return 0;}

