/*22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
int fd1=open("dummy_22.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
if(fd1<0){
        perror("FILE DIDN'T OPEN");
        }
else {
        pid_t process_id=fork(); 
        if(process_id==-1)
                       {
                        perror("No child process is created::\n");
                        }
        else if(process_id==0)
        {
        	int wr=write(fd1,"Baby process...\n\n",15);
        	if(wr<0)
        	{	perror("write failed in child process\n");
        		}
        	else{
        		printf("Child process is written with the data...\n");
        	}sleep(2);
        }
        else
        {
        	int wrp=write(fd1,"Parent process...\n\n",17);
        	if(wrp<0)
        	{	perror("Write failed in parent process\n");
        		}
        	else{
        		printf("Parent process is written with the data...\n");
        	}
        }   
   }  

return 0;
}
