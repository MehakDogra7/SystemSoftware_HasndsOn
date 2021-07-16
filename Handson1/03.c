/*3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//int creat(const char *pathname, mode_t mode);

int main()
{
int f1=open("hello_3.txt",O_TRUNC,0644);
//printf("%d\n",f1);
if(f1<0){
  const char file[]="Hello_3.txt";
  int f1=creat(file,0644);
  printf("The file descriptor value=%d\n",f1);
  
  if(f1!=-1)
    printf("File is created successfully\n");
  else
    perror(""); 
return 0;
}}
