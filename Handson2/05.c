/*
5. Write a program to print the system limitation of
	a. maximum length of the arguments to the exec family of functions.
	b. maximum number of simultaneous process per user id.
	c. number of clock ticks (jiffy) per second.
	d. maximum number of open files
	e. size of a page
	f. total number of pages in the physical memory
	g. number of currently available pages in the physical memory.
*/
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>   
#include <sys/resource.h>
#include <unistd.h>
#include <signal.h>
//man sysconf
int main()
{
//long sysconf(int name);

long val;
//5a
/*ARG_MAX - _SC_ARG_MAX
              The maximum length of the arguments to the exec(3) family of functions.  Must not be less than _POSIX_ARG_MAX (4096).
*/
    if((val = sysconf(_SC_ARG_MAX)) == -1) perror("sysconf");
    else printf("Maximum length of the arguments to the exec family of functions: %ld\n", val);
 
//5b
/*CHILD_MAX - _SC_CHILD_MAX
              The maximum number of simultaneous processes per user ID.
*/ 
    if((val = sysconf(_SC_CHILD_MAX)) == -1) perror("sysconf");
    else printf("Maximum number of simultaneous process per user ID: %ld\n", val);

//5c
/*clock ticks - _SC_CLK_TCK
              The number of clock ticks per second.  The corresponding variable is obsolete.  It was of course called CLK_TCK.
*/
    if((val = sysconf(_SC_CLK_TCK)) == -1) perror("sysconf");
    else printf("Number of clock ticks (jiffy) per second.: %ld\n", val);
   
//5d
/*OPEN_MAX - _SC_OPEN_MAX
              The maximum number of files that a process can have open at any time.
*/
    if((val = sysconf(_SC_OPEN_MAX)) == -1) perror("sysconf");
    else printf("Maximum number of open files: %ld\n", val);
    
//5e
/*PAGESIZE - _SC_PAGESIZE
              Size of a page in bytes.  Must not be less than 1.
*/
    if((val = sysconf(_SC_PAGESIZE)) == -1) perror("sysconf");
    else printf("Size of a page: %ld\n", val);
    
//5f
/*_SC_PHYS_PAGES
              The number of pages of physical memory.  Note that it is possible for the product of this value and the value  of  _SC_PAGE‐
              SIZE to overflow.
*/
    if((val = sysconf(_SC_PHYS_PAGES)) == -1) perror("sysconf");
    else printf("Total number of pages in the physical memory: %ld\n", val);
    
//5g
/*_SC_AVPHYS_PAGES
              The number of currently available pages of physical memory.
*/    
    if((val = sysconf(_SC_AVPHYS_PAGES)) == -1) perror("sysconf");
    else printf("Number of currently available pages in the physical memory: %ld\n", val);
    


return 0;}
