/*
10. Write a separate program using sigaction system call to catch the following signals.
	a. SIGSEGV
	b. SIGINT
	c. SIGFPE
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>  
#include <unistd.h>
void signal_handler(int signal_no){
	printf("Received the signal=%d\n",signal_no);
}
int main(){

//man 2 sigaction
/*
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);*/
	struct sigaction sa;
	sa.sa_handler = signal_handler;
	if(sigaction(SIGSEGV, &sa, NULL) == -1){
	perror("SIGSEGV::");}
	raise(SIGSEGV);
return 0;}


