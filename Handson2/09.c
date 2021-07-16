/*
9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>  
#include <unistd.h>
#include <pthread.h>
void my_handler(int sig){
	printf("%d\n",sig);
}
int main()
{
	printf("catching the signal..\n");
   signal(SIGINT,SIG_IGN);   //SIG_IGN is the system call to ignore the signals
   signal(SIGQUIT,SIG_IGN);
   signal(SIGTSTP,SIG_IGN);
   sleep(3);
   printf("Caught the signal..\n");
   printf("Lets ignore it...\n\n");
   printf("Ignoring SIGINT\n");
   sleep(8);
   printf("\n\nNo SIGINT within 3 seconds\n");
   
   signal(SIGINT,SIG_DFL);//SIG_DFL is the system call to get it to the proper default functioning
   signal(SIGQUIT,SIG_DFL);
   signal(SIGTSTP,SIG_DFL);
   printf("\n\nDefault\n");
   sleep(5);
   printf("\nNo SIGINT within 3 seconds\n");
return 0;}

/*
● Ctrl + C - SIGINT
● Ctrl + \ - SIGQUIT
● Ctrl + Z - SIGTSTP

*/
