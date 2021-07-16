/*
27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
printf("The program to execute ls -Rl using 'execvp'...\n");
/* int execvp(const char *pathname, char *const argv[]);*/

char *const arg[]={"ls","-Rl",NULL};
int exe= execvp("ls",arg);
printf("%d\n",exe);
printf("Work done...\n");

return 0;
}
