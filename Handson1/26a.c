/*26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
printf("The program to execute the executable program...\n");
int exe= execl("26_exe.c","26_exe.c",(char *)NULL);
if(exe<0)perror("EXECUTABLE FILE NOT FOUND::");
printf("%d\n",exe);
/*
we created a file named hello_world.c
then we created its executable file using the command "gcc hello_world.c -o 26_exe.c"
then after the executable file is created we pass the executable file to the execl command
this is done to run the hello_world.c using its executable file in other file named 26a.c
*/

return 0;}
