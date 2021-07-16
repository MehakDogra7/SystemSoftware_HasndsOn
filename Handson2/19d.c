/*
19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
d. mknod system call
e. mkfifo library function
*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
//d. mknod system call
    int val=mknod("file_19d.txt", S_IFIFO|0666, 0);
    if(val == -1)
        perror("MKNOD FAILED::");
    else printf("FIFO File Created Successfully\n");
    return 0;
}
