/*14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
struct stat stat_file;
//int fd1=open("dummy_14a.txt",O_RDONLY|O_CREAT|O_TRUNC,0644);
//int a=lstat("dummy_14a.txt", &stat_file);
//printf("File Type:: %d\n",a);


//14 a) Input is taken from the command line() 
    
    if(argc != 2){
        exit(EXIT_FAILURE);
    }
    if(lstat(argv[1], &stat_file) == -1){
        perror("lstat: ");
        exit(EXIT_FAILURE);
    }
    
// 14 b) tells the type of file
    printf("File type of the given file is\n");
    switch (stat_file.st_mode & __S_IFMT) {
        case __S_IFBLK:  
            printf("block device\n");
            break;
        case __S_IFCHR:  
            printf("character device\n");
            break;
        case __S_IFDIR:
            printf("directory\n");
            break;
        case __S_IFIFO:
            printf("FIFO/pipe\n");
            break;
        case __S_IFLNK:
            printf("symlink\n");
            break;
        case __S_IFSOCK: 
            printf("socket\n");
            break;
        default:
            printf("Regular file\n");
            break;
    }
    return 0;
}
