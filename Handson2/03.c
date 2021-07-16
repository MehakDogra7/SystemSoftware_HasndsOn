/*
3. Write a program to set (any one) system resource limit. Use setrlimit system call.
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
// int setrlimit(int resource, const struct rlimit *rlim);
/*
		struct rlimit {
		rlim_t rlim_cur; // Soft limit 
		rlim_t rlim_max; // Hard limit (ceiling for rlim_cur) 
		};
*/
struct rlimit old_lim, lim, new_lim; 

    int limit=getrlimit(RLIMIT_NOFILE, &old_lim);
   printf("Old limits of the system resources-> soft limit= %ld \t hard limit= %ld \n\n\n", old_lim.rlim_cur, old_lim.rlim_max);
   
    printf("Lets change the system resource limits...\n\n");
    printf("-------------------------------------------------------------------------------------\n\n");
   
   
    // Set new value 
    lim.rlim_cur = 10; 
    lim.rlim_max = 10000; 
  
    // Set limits 
    if(setrlimit(RLIMIT_NOFILE, &lim) == -1) 
        perror("SetLimit"); 
      
    // Get new limits 
    int get_limit=getrlimit(RLIMIT_NOFILE, &new_lim);
    if( get_limit < 0) 
        perror("GetLimit");
        
    printf("New limits set for current resouce limit -> soft limit= %ld \t hard limit= %ld \n", new_lim.rlim_cur,old_lim.rlim_max);    
    printf("New limits set for Max resouce limit -> soft limit= %ld \t hard limit= %ld \n", old_lim.rlim_cur,new_lim.rlim_max); 

return 0;
}
