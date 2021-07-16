/*
16. Write a program to send and receive data from parent to child vice versa. Use two way communication.
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pipe_parent[2];// from parent to child
    int pipe_child[2];// from parent to child
    if(pipe(pipe_parent)<0 || pipe(pipe_child)<0) 
    			perror("PIPE");
    
    char writebuffer_parent[200],readbuffer_parent[200],writebuffer_child[200],readbuffer_child[200];
    int readbuff,writebuff;
   int child_pid =fork();
    if(child_pid > 0)
    {
    	close(pipe_parent[0]);//reading end of pipe_parent is closed
    	close(pipe_child[1]);//close the writing end of the child pipe
    	
    	printf("This is the parent process...\n");
	printf("\nParent pid %d", getpid());
        printf("\nEnter message to write in pipe for the child: ");
        fgets(writebuffer_parent, 200, stdin);
         write(pipe_parent[1], writebuffer_parent, sizeof(writebuffer_parent));
         //sleep(8);
         
         //printf("Let's see the msg from child to me if any...\n");
        //let parent read any msg from the child...
         read(pipe_child[0],readbuffer_child,sizeof(writebuffer_child));
         printf("Child sent me this msg::%s\n",readbuffer_child);
        
    }
    else
    {
    	sleep(15);
    	close(pipe_parent[1]);//close the writing end of the parent pipe
    	close(pipe_child[0]);//close the reading end of the child pipe
    	
    	printf("\nThis is the child process...\n");
        printf( "\nChild pid %d\n", getpid());
        printf("\nParent Process Pid of the child %d", getppid());
         read(pipe_parent[0], readbuffer_parent, sizeof(writebuffer_parent));
        printf(" \nParent says : %s ", readbuffer_parent);
        //sleep(3);
        //lets write the msg to the parents
        printf("\nEnter message to write in pipe for the parent: ");
        fgets(writebuffer_child, 200, stdin);
        write(pipe_child[1],writebuffer_child,sizeof(writebuffer_child));
        printf("got the message..\n");
    }

return 0;}

/*
int pipe1[2], pipe2[2];
pipe(pipe1);
pipe(pipe2);
int child_pid = fork();
if(child_pid > 0){
// close read1 and close write2, parent process write1
// read from read2
}else{
// close read2 and write1, child process read1
// write from write2
}
*/
