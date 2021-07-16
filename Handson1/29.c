/*29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
 #include <sched.h>
 
 int main()
 {
 //int sched_getscheduler(pid_t pid);
 /*
 sched_getscheduler()  returns the current scheduling policy of the thread identified by pid.  If pid equals zero, the policy of the
       calling thread will be retrieved.
  */
pid_t process_id=getpid();
int policy=sched_getscheduler(process_id);
if(policy<0){perror("POLICY:");} 

else{
	printf("Integer value of currect policy=%d\n",policy);


	switch(policy){
		case SCHED_OTHER:
				printf("SCHED_OTHER policy\n"); break;
		case SCHED_FIFO: 	
				printf("First In First Out Policy OR SCHED_FIFO\n");break;
		case SCHED_RR:	
				printf("Round Robin Policy OR SCHED_RR\n");break;
		 default:	
		 		printf("CONFUSION HE CONFUSION\n");
	}	} 
//Let's modify the priority
/* int sched_setscheduler(pid_t pid, int policy,const struct sched_param *param);*/

struct sched_param param;
param.sched_priority = 1;

int new_policy=sched_setscheduler(process_id,SCHED_RR,&param);

if(new_policy<0){	perror("POLICY SET ERROR::");}
else{
//printf("The integer value for the changed policy=%d\n",new_policy);

	int n_policy=sched_getscheduler(process_id);
	if(n_policy<0){perror("POLICY GET ERROR:");} 
	printf("The integer value for the changed policy=%d\n",n_policy);
	switch(n_policy){
		case SCHED_OTHER:
				printf("SCHED_OTHER policy\n"); break;
		case SCHED_FIFO: 
				printf("First In First Out Policy OR SCHED_FIFO\n");break;
		case SCHED_RR:
				printf("Round Robin Policy OR SCHED_RR\n");break;
		 default:
		 		printf("CONFUSION HE CONFUSION\n");
}}
return 0;}
