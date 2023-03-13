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

	sem_t *sem = sem_open(name, O_CREAT | O_EXCL, 0666, val);
	if (sem == NULL){
	      	perror("sem_init failed\n");
	}	
	printf("Stworzylem semafor\n");
}

void semRemove(const char *name){
	int n = sem_unlink(name);
	if (n != 0){
	       	perror("sem_unlink failed\n");
	}	
	printf("Usunalem semafor\n");
}

semid semOpen(const char *name){
	sem_t *sem = sem_open(name, 0);
	if (sem == NULL){
	       	perror("sem_init failed\n");
	}	
	printf("Uzyskalem dostep do istniejacego semafora\n");	
}

void semClose(semid *sem){
	int n = sem_close(sem);
	if (n != 0){
	       	perror("sem_close failed\n");
	}	
	printf("Zamknalem semafor\n");
}

void semP(semid *sem){
	int n = sem_wait(sem);
	if (n != 0){
	       	perror("sem_wait failed\n");
	}	
	printf("Opuscilem semafor\n");
}

void semV(semid *sem){
	int n = sem_post(sem);
	if (n != 0){
	       	perror("sem_post failed");
	}	
	printf("Podnioslem semafor\n");
}

void semInfo(semid *sem){
	int val;
	int n = sem_getvalue(sem, &val);
	if (n != 0){
		perror("sem_getvalue failed");
	}	
	printf("wartosc semafora to %d\n",val);
	printf("Wypisalem informacje o wartosci semafora\n");
}	


