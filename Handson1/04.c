/*4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  //const char file="Hello_4.txt";
  int f1=open("Hello_4.txt",O_CREAT|O_EXCL,0644);
  if(f1<0)
     perror("ERROR:");
  else
     printf("File is created congratulations! \n");
return 0;
}
