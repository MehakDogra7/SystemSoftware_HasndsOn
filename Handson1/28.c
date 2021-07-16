/*28. Write a program to get maximum and minimum real time priority.*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
 #include <sched.h>

int main()
{
int min_priority,max_priority;
min_priority=sched_get_priority_min(SCHED_FIFO);
max_priority=sched_get_priority_max(SCHED_FIFO);

if(min_priority<0 ||max_priority<0 )
     perror("Priority::");
else{
	printf("The maximum priority in the FIRST IN FIRST OUT scheme is %d\n",max_priority);
	printf("The minimum priority in the FIRST IN FIRST OUT scheme is %d\n",min_priority);
}
min_priority=sched_get_priority_min(SCHED_RR);
max_priority=sched_get_priority_max(SCHED_RR);

if(min_priority<0 ||max_priority<0 )
     perror("Priority::");
else{
	printf("The maximum priority in the ROUND ROBIN scheme is %d\n",max_priority);
	printf("The minimum priority in the ROUND ROBIN scheme is %d\n",min_priority);
}

return 0;}
/*The maximum priority in the FIRST COME FIRST SERVE scheme is 99
The minimum priority in the FIRST COME FIRST SERVE scheme is 1
The maximum priority in the ROUND ROBIN scheme is 99
The minimum priority in the ROUND ROBIN scheme is 1
*/
