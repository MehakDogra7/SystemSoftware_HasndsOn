/*25. Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
int main()
{
int n=3;
int child1_id,child2_id,child3_id, status;
int i;
int time=5;
child1_id=fork();
if(child1_id<0)
	 {	perror("Child not created");}
    if(child1_id == 0){
    printf("This is the child 1 with the process id=%d and parent process id=%d\n",getpid(),getppid());
        sleep(time);
    }
    else{//parent of child1
		child2_id = fork();
		if(child2_id<0)
		 {	perror("Child not created");}
		if(child2_id == 0){
		printf("This is the child 2 with the process id=%d and parent process id=%d\n",getpid(),getppid());
		    sleep(time+10);
		}
		else{//parent of child2
			    child3_id = fork();
			    if(child3_id<0)
				 {	perror("Child not created");}
			    if(child3_id == 0){
			    printf("This is the child 3 with the process id=%d and parent process id=%d\n",getpid(),getppid());
				sleep(time);
			    }
		}

    }

pid_t waitID = waitpid(child2_id, &status, 0);
/*WIFEXITED(wstatus)
              returns true if the child terminated normally, that is, by calling exit(3) or _exit(2), or by returning from main().*/
if(WIFEXITED(status))
	{
		printf("child with waitID==%d, terminated with exit status==%d\n",waitID, WEXITSTATUS(status));
	}

return 0;}
//pid_t waitpid(pid_t pid, int *wstatus, int options);
/*     used to wait for state changes in a child of the calling process, and obtain information about the
       child whose state has changed.  A state change is considered to be: the child terminated; the child was stopped by a signal; or the
       child was resumed by a signal.  In the case of a terminated child, performing a wait allows the system to release the resources as‐
       sociated with the child; if a wait is not performed, then the terminated child remains in a "zombie" state */
       
   /*The waitpid() system call suspends execution of the calling thread until a child specified by pid argument has changed  state.   By
       default,  waitpid()  waits only for terminated children, but this behavior is modifiable via the options argument, as described be‐
       low.
	*/
