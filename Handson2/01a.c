/*
1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
*/

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void no_use_fxn()
{
	static int count = 1;
	printf("Timer expired %d times.\n", count++);
}

int main()
{
// int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);

	
	
	struct itimerval  timer;
	
	timer.it_value.tv_sec = 2;
	timer.it_value.tv_usec = 5;
	timer.it_interval = timer.it_value;
	printf("Let the time begin\n");
	int set_time=setitimer(ITIMER_REAL,&timer, NULL);
	if( set_time== -1)
	{
		perror("setitimer()");
	}
	while(1)
	{
		//no_use_fxn();
	};
return 0;
}
// output::: Alarm clock

/*
       ITIMER_REAL    This  timer counts down in real (i.e., wall clock) time.
                      At each expiration, a SIGALRM signal is generated.

*/
/*
 struct itimerval {
               struct timeval it_interval; // Interval for periodic timer 
               struct timeval it_value;    // Time until next expiration 
           };

           struct timeval {
               time_t      tv_sec;         // seconds 
               suseconds_t tv_usec;        // microseconds 
           };

*/
