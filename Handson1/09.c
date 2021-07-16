/*9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
int main()
{
// man 2 stat
int fd1=open("dummy_9.txt",O_RDONLY|O_TRUNC |O_CREAT);
//int buf=10;
//int whence= SEEK_END;
//int seek=lseek(fd1,buf,whence);

struct stat buf;
struct  timespec;
char buffer[100];
int stat_return=stat("dummy_9.txt",&buf);

if (fd1<0) {
               perror("File not Found");
              
           }
if (stat_return<0) {
               perror("ERROR::");
               
           }


printf("I-node number:            %ld\n", buf.st_ino);
printf("Hardlinks of the file== %ld\n",buf.st_nlink);
printf("USER ID of the file=%u\n",buf.st_uid);
printf("Group ID of the file=%d\n",buf.st_gid);
printf("File size:   %ld bytes\n",buf.st_size);
printf("Block size of the file==%ld\n",buf.st_blksize);
printf("Blocks allocated:  %ld\n",buf.st_blocks);
printf("Last file access:         %ld\n", buf.st_atime);
printf("Last file modification:   %ld\n", buf.st_mtime);
printf("Time of file creation:    %ld\n", buf.st_ctime);

return 0;
       }
       
/*
printf("Link count:               %ld\n", (long) sb.st_nlink);
printf("Ownership:                UID=%ld   GID=%ld\n",(long) sb.st_uid, (long) sb.st_gid);
printf("Preferred I/O block size: %ld bytes\n",(long) sb.st_blksize);
printf("Last status change:       %s", ctime(&sb.st_ctime));
*/
