/*19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<time.h>

int main()
{
clock_t clock_start,clock_end;

clock_start=clock();
int pid = getpid();
clock_end=clock();

printf("The process ID id ==%d\n",pid);
//The clock() function returns an approximation of processor time used by the program.
printf("approximation of processor time befor getpid()=%f\n",(double)clock_start);
printf("approximation of processor time after getpid()=%f\n",(double)clock_end);

double time_taken=((double)clock_end-clock_start)/CLOCKS_PER_SEC;
printf("Time taken to execute the getpid==%f \n",time_taken);

return 0;}
