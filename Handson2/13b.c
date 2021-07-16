/*
    13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
	will send the signal (using kill system call). Find out whether the first program is able to catch
	the signal or not.
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
void signal_handler(int signal_no){
}
int main()
{
pid_t pid;
	printf("Enter the pid of the code...\n");
	scanf("The pid =%d\n",&pid);
	
	kill(pid, SIGSTOP);
	sleep(10);
	
return 0;
}

