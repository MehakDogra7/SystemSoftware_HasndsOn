/*
27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
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
printf("The program to execute ls -Rl using 'execl'...\n");
/* int execl(const char *pathname, const char *arg, ...(char  *) NULL );*/
int exe= execl("/bin/ls","ls","-Rl",(char *)NULL);
printf("%d\n",exe);
printf("Work done...\n");

return 0;
}
                   
/*
       ┌──────────────────────────────┬───────────────┬─────────────┐
       │Interface                     │ Attribute     │ Value       │
       ├──────────────────────────────┼───────────────┼─────────────┤
       │execl(), execle(), execv()    │ Thread safety │ MT-Safe     │
       ├──────────────────────────────┼───────────────┼─────────────┤
       │execlp(), execvp(), execvpe() │ Thread safety │ MT-Safe env │
       └──────────────────────────────┴───────────────┴─────────────┘
*/
