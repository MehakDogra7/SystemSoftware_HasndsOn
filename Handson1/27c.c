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
 char *const envp[]={"PATH=C:\\TEST", NULL};
printf("The program to execute ls -Rl using 'execle'...\n");
/* int execle(const char *pathname, const char *arg, ..., (char *) NULL, char *const envp[] )*/
int exe= execle("/bin/ls","ls","-Rl",NULL,envp);
printf("%d\n",exe);
printf("Work done...\n");

return 0;
}
