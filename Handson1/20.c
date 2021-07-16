/*20. Find out the priority of your running program. Modify the priority with nice command.*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<sys/time.h>
#include<sys/resource.h>

int main()
{
int priority=getpriority(PRIO_PROCESS,0);
//process priority==0
printf("The priority of the current process==%d\n",priority);

//Modifying the priority...
//nice - change process priority
priority=nice(15);
/*On  success,  the new nice value is returned (but see NOTES below).  On
error, -1 is returned, and errno is set appropriately.*/
if(priority<0)
{
	perror("Priority didn't change");
	}
else{
//Modified process priority==15
printf("The modified priority of the process==%d\n",priority);
}
return 0;
}
