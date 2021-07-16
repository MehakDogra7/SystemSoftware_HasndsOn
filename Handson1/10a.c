/*10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.*/


//10a.c
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
int main()
{
int f1=open("dummy_10.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
//char buffer[50];
printf("File descriptor== %d\n",f1);
char buffer[]="Hello IIITB...\n Its amazing to be here."; 
write(f1,buffer,10);
printf("*****Moving the pointer by 10 Bytes*****\n");
off_t seek=lseek(f1,20,SEEK_CUR);
write(f1,buffer,10);
printf("value returned by lseek== %ld\n",seek);
return 0;
}



//10b.c
// to check the octal and other formats of the file::
//on terminal run the command::

// od -c dummy_10.txt
