/*5. Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.*/

#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>

int main()
{
int count=1;
int fd[5];
while(1){
if(count<=5)
{
   char arr[10];
   sprintf(arr,"%d_5.txt",count);
    char file[512]="infinite";
   strcat(file,arr);
   fd[count]=creat(file,0644);
   printf("the file descriptor==%d \n",fd[count]);
   count++;
   sleep(3);
   
}
else{
   printf("5 files have been created\n");
   break;
}
}
return 0;}

/**
*mehak@Mehak:/proc/14723$ cat status
Name:	a.out
Umask:	0002
State:	S (sleeping)
Tgid:	14723
Ngid:	0
Pid:	14723
PPid:	9384
TracerPid:	0

*mehak@Mehak:/proc$ ls 14723
arch_status      environ    mountinfo      personality   statm
attr             exe        mounts         projid_map    status
autogroup        fd         mountstats     root          syscall
auxv             fdinfo     net            sched         task
cgroup           gid_map    ns             schedstat     timers
clear_refs       io         numa_maps      sessionid     timerslack_ns
cmdline          limits     oom_adj        setgroups     uid_map
comm             loginuid   oom_score      smaps         wchan
coredump_filter  map_files  oom_score_adj  smaps_rollup
cpuset           maps       pagemap        stack
cwd              mem        patch_state    stat

*mehak@Mehak:/proc$ ls | grep 14723
14928

*mehak@Mehak:/proc$ kill 14723
*mehak@Mehak:/proc$ cd 14723
bash: cd: 14723: No such file or directory
*/
