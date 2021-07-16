/*6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>

int main()
{

char buffer[100];

//ssize_t write(int fd, const void *buf, size_t count);
//ssize_t and int are similar.. as ssize_t is subtype of int 
int fdread=STDIN_FILENO;
int fdwrite=STDOUT_FILENO;
int x = read(fdread, buffer, sizeof(buffer)); // stdin = 0
int y=write(fdwrite,buffer,x);

/**

value	Name	            <unistd.h> symbolic constant	<stdio.h> file stream
0	Standard input 	STDIN_FILENO				stdin
1	Standard output	STDOUT_FILENO				stdout
2	Standard error	        STDERR_FILENO				stderr
*/
	

return 0;
}
