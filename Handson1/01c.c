/*Create the following types of a files using (i) shell command (ii) system call

c. FIFO (mkfifo Library Function or mknod system call)
*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

 int main()
 {
 const char file[]="./hello_1_c.txt";
 	int f2=mkfifo(file,0644);
 	
 	if(f2==0)
 	printf("FIFO file created\n");
 	else
 	perror("FIFO failed because");
 return 0;
 }
