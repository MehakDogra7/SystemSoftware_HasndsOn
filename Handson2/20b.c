/*
20. Write two programs so that both can communicate by FIFO -Use one way communication.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

void main()
{
    int fd_read = open("file_20.txt", O_RDONLY);
    char read_buffer[200];
    read(fd_read, read_buffer, sizeof(read_buffer));
    printf("Message Received :%s", read_buffer);

}

/*
Create two processes, where in 20a you create a pipe using mknod or mkfifo and then
open that file in write only mode while writing some data to it. While in 20b you open the
same pipe in read only mode and read that written stuff here
*/
