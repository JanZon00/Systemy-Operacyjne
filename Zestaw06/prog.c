#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <unistd.h>
#include "sem.h"

int main(int argc, char* argv[])
{
	int dane_sczytane;
	int dane_wczytane;
	int sekcje = atoi(argv[3]);
	int value;
	int buf;
	int sk = 0;

	sem_t *semid = sem_open("/semafor",0);
	sem_getvalue(semid,&value);
	
	for(int i=0;i<sekcje;i++){
		int fd1 = open("numer.txt",O_RDONLY,0666);
	
		printf("PID : %d, przed SK, semafor : %d\n",getpid(),value);
	
		sem_wait(semid);
		dane_sczytane = read(fd1,&buf,sizeof(int));
		if(dane_sczytane == -1){
			perror("blad przy wczytywaniu danych");
			return -1;
		}
		close(fd1);
	
		printf("\tPID : %d, odczytano numer: %d, SK = %d\n",getpid(),buf,sk);	
		usleep(((rand() % 5) +1)*1000000);
		buf+=1;
		int fd2 = open("numer.txt",O_WRONLY,0666);
	
		dane_wczytane = write(fd2,&buf,sizeof(int));
		if(dane_wczytane == -1){
			perror("blad przy wczytywaniu danych");
			return -1;	
		}
		close(fd2);
		sem_post(semid);
		sleep(2);
		printf("PID : %d, po SK, semafor : %d\n",getpid(),value);
		sk+=1;
	}
	sleep(1);
}
