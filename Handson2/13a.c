/*
13.    Write two programs: first program is waiting to catch SIGSTOP signal, the second program
	will send the signal (using kill system call). Find out whether the first program is able to catch
	the signal or not.
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>  
#include <unistd.h>
void signal_handler(int signal_no){
	if(signal_no == SIGSTOP)
		printf("Caught SIGSTOP signal.\n");
}
int main()
{
	pid_t pid=getpid();
	printf("pid of the process: %d\n", pid);
	
	sleep(20);
	if(signal(SIGSTOP, &signal_handler) == SIG_ERR){
		perror("Signal::");
		printf("cannot catch SIGSTOP signal...\n");
		}
	
return 0;}

//This example will prove that SIDSTOP and SIGKILL signal cannot be caught...

//Its their property, they can neither be ignored nor be caught
