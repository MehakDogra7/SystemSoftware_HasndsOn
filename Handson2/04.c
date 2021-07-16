/*
4. Write a program to measure how much time is taken to execute 100 getppid() system call. Use time stamp counter.
*/

#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>   
#include <sys/resource.h>
#include <unistd.h>
#include <signal.h>

int main()
{
clock_t clock_start,clock_end;

clock_start=clock();
int ppid;
clock_end=clock();

for (int i = 0; i < 100; ++i){
	ppid = getppid();}
	//printf("ppid==%d\n",ppid);} 

//printf("The process ID id ==%d\n",ppid);
//The clock() function returns an approximation of processor time used by the program.
printf("approximation of processor time befor getppid()=%f\n",(double)clock_start);
printf("approximation of processor time after getppid()=%f\n",(double)clock_end);

double time_taken=((double)clock_end-clock_start);///CLOCKS_PER_SEC;
printf("Time taken to execute the 100 getppid==%f \n",time_taken);


return 0;}
