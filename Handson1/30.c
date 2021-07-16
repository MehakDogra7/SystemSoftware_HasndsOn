/*30. Write a program to run a script at a specific time using a Daemon process.*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
 int main()
 {
 //A daemon process is a process which runs in background and has no controlling terminal.
 time_t currenttime;
 struct tm *time_detail;
 
 pid_t child_id=fork();
 if(child_id<0){
 	perror("Child didn't create:\n");}
 else if(child_id==0)
 {
 	printf("This is the child process with parent process id=%d\n",getppid());
 	int set=setsid();//running in new session
 		if(set<0)   perror("SETSID");
 	chdir("/");//changed to root directory
 	umask(0);
 	//sleep(10);
 	int hour=00;
 	int min=5;//0 to 59
 	for(;;)
 		{
 		time(&currenttime);
 		time_detail=localtime(&currenttime);
 		printf("current time and date=%s\n",asctime(time_detail));
 		if(hour== time_detail->tm_hour && min==time_detail->tm_min){
 			printf("ENDING\n");
 			exit(0);
 		}
 		else{
 			printf("DAEMON process is running...\n");
 			sleep(60);
 		}
 	
 	}
 	
 }
 else{
 	printf("This is the parent process with id=%d\n",getpid());
 	
 }
 
 return 0;
 }
 
 //to break the loop
 /*
 	ps aux|grep a.out
 	kill -9 <pid>
 	
 	// to kill the daemon processes
 */
 /*
 to print the name of the terminal connected to standard input -> ?on tty
 */
