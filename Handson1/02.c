/*
2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
*/

#include<stdio.h>
 int main()
{
for( ; ; )
{}

return 0;
}
/*cd proc/pid
   cat status
 */
/*
Name:	a.out
Umask:	0002
State:	R (running)
Tgid:	32762
Ngid:	0
Pid:	32762
PPid:	6466
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 120 131 132 1000 
NStgid:	32762
NSpid:	32762
NSpgid:	32762
NSsid:	6466
VmPeak:	    2432 kB
VmSize:	    2356 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	     580 kB
VmRSS:	     580 kB
RssAnon:	      68 kB
RssFile:	     512 kB
RssShmem:	       0 kB

*/
