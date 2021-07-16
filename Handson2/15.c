/*
15. Write a simple program to send some data from the parent to the child process.
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pipefd[2];
    if(pipe(pipefd)<0) 
    			perror("PIPE");
    
   
   
    char writebuffer[200],readbuffer[200];
    int readbuff,writebuff;
   int child_pid =fork();
    
    
    if(child_pid > 0)//parent process
    {
    	close(pipefd[0]);
    	printf("This is the parent process...\n");
	printf("\nParent pid %d", getpid());
        printf("\nEnter message to write in pipe for the child: ");
        fgets(writebuffer, 200, stdin);
         write(pipefd[1], writebuffer, sizeof(writebuffer));
        
    }
    else//child process
    {
    	sleep(15);
    	close(pipefd[1]);
    	printf("This is the child process...\n");
        printf( "Child pid %d\n", getpid());
        //printf("\nParent Process Pid of the child %d", getppid());
         read(pipefd[0], readbuffer, sizeof(writebuffer));
        printf(" \nMessage for the child by the parent : %s ", readbuffer);
    }

return 0;}

/*
int pipefd[2];
pipe(pipefd)
int child_pid = fork();
if(child_pid > 0){
// parent process write
}else{
// child process read
}
*/
