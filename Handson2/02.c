/*
2. Write a program to print the system resource limits. Use getrlimit system call.
*/

#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>   
#include <sys/resource.h>
#include <unistd.h>
#include <signal.h>

int main()
{

/*
		struct rlimit {
		rlim_t rlim_cur; // Soft limit 
		rlim_t rlim_max; // Hard limit (ceiling for rlim_cur) 
		};
*/

//int getrlimit(int resource, struct rlimit *rlim);
// int setrlimit(int resource, const struct rlimit *rlim);

printf("Lets fetch the system resource limits....\n");

 struct rlimit old_lim; 
  
    // Get old limits 
    if( getrlimit(RLIMIT_NOFILE, &old_lim) == 0) 
        printf("Old limits -> soft limit= %ld \t hard limit= %ld \n", old_lim.rlim_cur, old_lim.rlim_max); 
    else
        perror("System Resource Limit:"); 
      

return 0;
}

/*
	RLIMIT_NOFILE
              This  specifies  a  value  one greater than the maximum file descriptor number that can be opened by this process.  Attempts
              (open(2), pipe(2), dup(2), etc.)  to exceed this limit  yield  the  error  EMFILE.   (Historically,  this  limit  was  named
              RLIMIT_OFILE on BSD.)

*/
