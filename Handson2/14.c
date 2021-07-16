/*
14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>  
#include <unistd.h>

int main()
{

    int pipefd[2];
    if(pipe(pipefd)<0)
    		{perror("PIPE::");}
    		
    		
    char writebuffer[200],readbuffer[200];
    printf("Enter message in pipe from pipe[1] : ");
    fgets(writebuffer, 100, stdin);
    int writebuff=write(pipefd[1], writebuffer, sizeof(writebuffer));
    if(writebuff<0)
    		{perror("WRITE::");}
    int readbuff=read(pipefd[0], readbuffer, writebuff);
    if(readbuff<0)
    		{perror("READ::");}
    printf("Message read from the pipe from pipe[0]: %s ", readbuffer);

return 0;
}

/*

write(pipefd[1], msg, sizeof(msg));
read(pipefd[0], buff, sizeof(msg));
*/
