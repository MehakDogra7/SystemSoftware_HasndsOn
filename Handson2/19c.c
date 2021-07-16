/*
Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
d. mknod system call
e. mkfifo library function
*/


/*
strace -c mkfifo <filename>
strace -c mknod <filename> p
*/

/*
mehak@Mehak:~/Documents/System_Software/Handson2$ rm file_19c.txt ||strace -c mkfifo file_19c.txt
rm: cannot remove 'file_19c.txt': No such file or directory
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0         7           read
  0.00    0.000000           0        10           close
  0.00    0.000000           0         8           fstat
  0.00    0.000000           0        27           mmap
  0.00    0.000000           0         9           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         2           rt_sigaction
  0.00    0.000000           0         1           rt_sigprocmask
  0.00    0.000000           0         8           pread64
  0.00    0.000000           0         2         2 access
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         1           mknod
  0.00    0.000000           0         2         2 statfs
  0.00    0.000000           0         2         1 arch_prctl
  0.00    0.000000           0         1           set_tid_address
  0.00    0.000000           0         8           openat
  0.00    0.000000           0         1           set_robust_list
  0.00    0.000000           0         1           prlimit64
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000                    95         5 total


*/

/*
mehak@Mehak:~/Documents/System_Software/Handson2$ rm file_19c.txt || strace -c mknod -p file_19c.txt 
rm: cannot remove 'file_19c.txt': No such file or directory
mknod: invalid option -- 'p'
Try 'mknod --help' for more information.
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0         9           read
  0.00    0.000000           0         2           write
  0.00    0.000000           0        12           close
  0.00    0.000000           0        10           fstat
  0.00    0.000000           0        28           mmap
  0.00    0.000000           0         9           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         2           rt_sigaction
  0.00    0.000000           0         1           rt_sigprocmask
  0.00    0.000000           0         8           pread64
  0.00    0.000000           0         2         2 access
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         2         2 statfs
  0.00    0.000000           0         2         1 arch_prctl
  0.00    0.000000           0         1           set_tid_address
  0.00    0.000000           0        17         7 openat
  0.00    0.000000           0         1           set_robust_list
  0.00    0.000000           0         1           prlimit64
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000                   112        12 total



*/

//clearly mkfifo takes less time than mknod... thus mkfifo is better...
