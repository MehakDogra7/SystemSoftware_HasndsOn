/*18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{
int fd=open("dummy_18a.txt",O_RDWR|O_CREAT|O_TRUNC,0755);
if(fd<0)
{
	perror("ERROR:");
}

   char rec1[]="This String is  ABCD\n";
   char rec2[]="This String is  MNOP\n";
   char rec3[]="This String is  pqrs\n";
   char rec4[]="This String is  wxyz\n";
  
   char rec5[]="hello this is string\n";
   
   int w1=write(fd,rec1,sizeof(rec1));
   int w2=write(fd,rec2,sizeof(rec2));
   int w3=write(fd,rec3,sizeof(rec3));
   int w4=write(fd,rec4,sizeof(rec4));

int n;

	printf("Enter the record on which lock is to be acquired::");
	scanf("%d",&n);

	if(n>0 && n<5){
		struct flock lk;
		lk.l_type = F_WRLCK;
		lk.l_whence = SEEK_SET;
		lk.l_start = (n-1)*sizeof(rec1)+1;
		lk.l_len = sizeof(rec1);
		lk.l_pid = getpid();
		printf("Before Lock - Acquiring lock.....\n");
		//printf("startng is: %ld and length is: %ld\n", lk.l_start, lk.l_len);
		
		int fl=fcntl(fd,F_SETLKW, &lk);
		if(fl<0){perror("ERROR:");}
		
		printf("Write lock applied.....\n");
		lseek(fd, ((n-1) * sizeof(rec1)), SEEK_SET);
		int w5=write(fd,rec5,sizeof(rec5));
		if(w5<0){perror("Didn't write:");}
		
		printf("Press any key to exit.\n");
		getchar();
		getchar();
		lk.l_type = F_UNLCK;
		int fl2=fcntl(fd, F_SETLKW, &lk);
		if(fl2<0){perror("ERROR $:");}
		printf("Unlocked the file.\n");
		close(fd);
}
return 0;}

