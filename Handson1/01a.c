/*Create the following types of a files using (i) shell command (ii) system call

a. soft link (symlink system call)
*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){

int f1=open("hello_1.txt",O_CREAT|O_WRONLY|O_TRUNC,0644);
char data[]="Hello Everyone. \n Good Morning\n";
write(f1,data,sizeof(data));

const char abc[]="hello_1.txt";
const char soft[]="./soft_link_hello_1.txt";

int sl=symlink(abc,soft);
if(sl<0){perror("SOFTLINK");}

//int soft =symlink(const char "./hi.txt", const char "./soft_link_hi.txt");
return 0;
}
