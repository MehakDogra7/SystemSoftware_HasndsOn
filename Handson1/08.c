/*8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>

int main()
{int i;
int fd1=open("dummy_8.txt",O_RDONLY);
char buffer;
int fdwrite=STDOUT_FILENO;// fdwrite=1;
int fd_read;
//for(i=0;i<sizeof(fd1_read);i++){
//if(buffer[i] == '\n') getchar();
//else printf("%c", buffer[i]);
//}
while(fd_read=read(fd1,&buffer,1)){
	if(buffer=='\n'){
	printf("\n*********\n");
	}
	else{
	write(fdwrite,&buffer,fd_read);
	}
}
//int y=write(fdwrite,buffer,fd1_read);

close(fd1);
printf("BYE BYE!!!!!! \n");
return 0;
}
