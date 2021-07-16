/*
23. Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    //if((open("file_23.txt",O_RDONLY))==-1){
   		 mkfifo("file_23.txt", 0644);
    long max_files =sysconf(_SC_OPEN_MAX);
    long max_pipes =pathconf("file_23.txt", _PC_PIPE_BUF);
    printf("Maximum files within a process:%ld \nSize of the pipe :%ld\n", max_files, max_pipes);

return 0;}
/*
Maximum files within a process:1024 
Size of the pipe :4096
*/
