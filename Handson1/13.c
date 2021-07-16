/*13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
/*int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);*/
int fd_open =open("dummy_13.c",O_RDWR|O_CREAT|O_TRUNC,0644); // opened a file
printf("File descriptor of the file== %d\n",fd_open);


fd_set readfd;
struct timeval time;
int return_val;

FD_ZERO(&readfd);
FD_SET(0,&readfd);

time.tv_sec=10;  
time.tv_usec=0;  

return_val=select(fd_open,&readfd,NULL, NULL, &time);

if(return_val<0)
{
	perror("Error in select::");
}
else if(return_val)
{	char data[512];
		int i;
		for (i = 0; i < 511; ++i)
		{
			scanf("%c", &data[i]);
			if(data[i] == '\n') break;
		}
		data[i] = '\0';
	printf("DATA is available now...\n");
	printf("Data: %s\n", data);
}
else
{
	printf("NO data is available...\n");
}

return 0;
}

