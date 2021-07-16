/*
22. Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/time.h>
#include<fcntl.h>
int main()
{
	int f = mkfifo("file_22a.txt", 0644);
	int fd = open("file_22a.txt", O_NONBLOCK | O_RDONLY);
	char buffer[100];
	fd_set rfds;
        struct timeval tv;
        
	FD_ZERO(&rfds);
        FD_SET(fd, &rfds);

       tv.tv_sec = 10;
       tv.tv_usec = 0;
       int time_select = select(4, &rfds, NULL, NULL, &tv);

       if (time_select == -1)
       	perror("SELECT::");
       else if (time_select>0){
       	printf("Data is available within 10 seconds!\n");
               read(fd, buffer, sizeof(buffer));
               printf("Data: %s\n", buffer);      
       }
       else//time_select==0
               printf("No data within ten seconds.\n");
	close(fd);	

return 0;}

/*
fd = open("22_fifoFile", O_NONBLOCK|O_RDONLY);
FD_ZERO(&rfds);
FD_SET(fd, &rfds);
if(select(4, &rfds, NULL, NULL, &timeSet)){
// read the data in fd, and then print the received data
}
21b
fd = open(“22_fifoFile”, O_WRONLY);
write(fd, “Hey there”, sizeof(“Hey there”));
*/
