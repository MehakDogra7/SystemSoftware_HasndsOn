/*26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
int exe=execl("26_exe.c","26_exe.c","MAI NI KHELNA... ", (char *) NULL);
if(exe<0)
{perror("execl error::");}

return 0;}
