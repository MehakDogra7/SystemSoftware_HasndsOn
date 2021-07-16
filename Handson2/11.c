/*
11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal use sigaction system call.
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>  
#include <unistd.h>

void signal_handler(int signal_no){
	printf("Received the signal=%d\n",signal_no);
}
int main()
{
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	
	if(sigaction(SIGINT, &sa, NULL) == -1) perror("sigaction()"); 
	printf("Ignoring the  signal....\n\n");
	
	sleep(4);
	printf("Lets get the signal back..\n");
	raise(SIGINT);
	sa.sa_handler = SIG_DFL;
	sa.sa_handler = signal_handler;
	if(sigaction(SIGINT, &sa, NULL) == -1) perror("sigaction()");
	raise(SIGINT);
	
return 0;}
