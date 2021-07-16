/*24. Write a program to create an orphan process.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
pid_t process_id=fork();
/*parent finishes execution and exits while the child process is still executing and is called an orphan process now.*/
if(process_id==-1)
{
	perror("Child not created");
}
else if(process_id==0)
{
	
	printf("Child process is here....\n");
	printf("Process ID of the child==%d\n",getpid());
	printf("Parent ID of the child before parent is terminated==%d\n",getppid());
	sleep(20);
	printf("Parent ID of the child after the parent process is terminated==%d\n",getppid());
	
}
else{
	printf("Parent process is here....\n");
	printf("Process ID of the parent==%d\n",getpid());
	sleep(2);
	
}


return 0;
}
