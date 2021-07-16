/*
27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled.
d. execv
e. execvp
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
//The exec family of functions replaces the current running process with a new process.
int main()
{
printf("The program to execute ls -Rl using 'execlp'...\n");
/* int execlp(const char *file, const char *arg, ...(char  *) NULL );*/
int exe= execlp("ls","ls","-Rl",(char *)NULL);
printf("%d\n",exe);
printf("Work done...\n");

return 0;
}
