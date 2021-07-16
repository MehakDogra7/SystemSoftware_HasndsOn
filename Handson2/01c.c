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
	struct itimerval  timer;
	
	timer.it_value.tv_sec = 2;
	timer.it_value.tv_usec = 100;
	timer.it_interval = timer.it_value;
	int set_time=setitimer(ITIMER_PROF,&timer, NULL);
	if( set_time== -1)
	{
		perror("setitimer()");
	}
	while(1)
	{
		//no_use_fxn();
	};
	
return 0;}

//output::::  Profiling timer expired

/*
       ITIMER_PROF    This  timer  counts  down  against the total (i.e., both
                      user and system) CPU time consumed by the process.  (The
                      measurement includes CPU time consumed by all threads in
                      the process.)  At each expiration, a SIGPROF  signal  is
                      generated.
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
