#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/sem.h>
#include "sem.h"

semid semCreate(const char *name, int val){

	semid *sem = sem_open(name, O_CREAT | O_EXCL, 0664, val);
	if (sem == NULL){
	      	perror("sem_init failed\n");
	}
	return *sem;	
}

void semRemove(const char *name){
	int n = sem_unlink(name);
	if (n != 0){
	       	perror("sem_unlink failed\n");
	}	
}

semid semOpen(const char *name){
	semid *sem = sem_open(name, 0);
	if (sem == NULL){
	       	perror("sem_init failed\n");
	}
	return *sem;	
}

void semClose(semid *sem){
	int n = sem_close(sem);
	if (n != 0){
	       	perror("sem_close failed\n");
	}	
}

void semP(semid *sem){
	int n = sem_wait(sem);
	if (n != 0){
	       	perror("sem_wait failed\n");
	}	
}

void semV(semid *sem){
	int n = sem_post(sem);
	if (n != 0){
	       	perror("sem_post failed");
	}	
}

void semInfo(semid *sem){
	int val;
	int n = sem_getvalue(sem, &val);
	if (n != 0){
		perror("sem_getvalue failed");
	}	
	printf("wartosc semafora to %d\n",val);
}	


