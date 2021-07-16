/*
32. Write a program to implement semaphore to protect any critical
section.
		a. rewrite the ticket number creation program using semaphore
		b. protect shared memory from concurrent write access
		c. protect multiple pseudo resources ( may be two) using counting
		semaphore
		d. remove the created semaphore
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/shm.h>
union semun{
    int value;
    struct semid_ds *buf;
    unsigned short int *array;
};
int main() {

    union semun arg;

    int key=ftok(".", 123);

	struct ticket_st
	{
	    int ticket_number;
	}db;

    int semid = semget(key, 1, 0);
    if(semid == -1){
    	semid = semget(key, 1, IPC_CREAT|0644);    
        arg.value = 2;
        semctl(semid, 0, SETVAL, arg);
    }


    struct sembuf buf = {0,-1,0};
    if (semop(semid, &buf, 1) == -1) {
        perror("semop");
        exit(0);
    }
    /*1 for binary else >1 for Counting Semaphore */
    printf("before Entering into the critical section..\n");
    printf("Waiting for the unlock...\n");
    int fd = open("record.txt", O_CREAT|O_EXCL|O_RDWR, 0644);
    if(fd!=-1){
    	db.ticket_number = 0;
    	write(fd, &db, sizeof(db));
    }
    close(fd);

	fd = open("record.txt", O_RDWR);
    printf("In the critical section.\n");
    printf("******************************************\n");

   	int count = read(fd, &db, sizeof(db));
	if(count == -1)
	{
		perror("read()");
		exit(EXIT_FAILURE);
	}
	
	db.ticket_number++;

	lseek(fd, 0L, SEEK_SET);
	int wr=write(fd, &db, sizeof(db));
	if(wr<0){perror("WRITE");}
	
	printf("New ticket number: %d\n", db.ticket_number);
	close(fd);

    buf.sem_op=1;
    semop(semid, &buf, 1);
	printf("Write opeation successful...\n");
    printf("Press any key to exit the lock.\n");
	getchar();//getchar();
	printf("*********************************\n");
	printf("You are out.. have a nice day\n");
	return 0;	
    
}

