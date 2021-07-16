/*Create the following types of a files using (i) shell command (ii) system call

b. hard link (link system call)
*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int ac,char const *a[])
{
   int f2=open("Hello_1_b.txt",O_CREAT|O_WRONLY|O_TRUNC,0644);
   char text[]="hi all\nthis is the second part of question 1\n";
   write(f2,text,sizeof(text));
  const char file[]="Hello_1_b.txt";
  const char hard[]="hard_link_Hello_2.txt";
  
  int hl=link(file,hard);
 //int link(const char *oldpath, const char *newpath);
 if(hl<0)perror("Not created::");
return 0;
}
