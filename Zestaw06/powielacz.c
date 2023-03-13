#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <unistd.h>
#include "sem.h"

const char* name = "/semafor";

void usuwam_semafor(void){
	semRemove(name);
	printf("usunieto semafor\n");
}	

int main(int argc, char* argv[])
{
	if(argc!= 4){
		perror("Niepoprawna skladnia. Poprawnie ./powielacz.x ./prog.x <liczba procesow> <liczba sekcji krytycznych>\n");
		exit(1);
	}
	

	sem_t *semid = sem_open(name, O_CREAT | O_EXCL, 0666, 1);
	if (semid == NULL){
		perror("sem_open failed\n");
		exit(2);
	}

	int procesy = atoi(argv[2]);
	int sekcje = atoi(argv[3]);
	int dane_sczytane;
	int dane_wczytane;
	int buf = 0;
	int value;
	sem_getvalue(semid,&value);

	printf("otrzymano %d procesow oraz %d sekcji krytycznych\n",procesy,sekcje);
	printf("Utworzono semafor : %s o wartosci %d\n",name,value);

	
	int fd1 = open("numer.txt",O_CREAT | O_WRONLY, 0666);

	if(fd1 == -1){
		perror("Blad otwarcia pliku zrodlowego");
		exit(3);
	}

	dane_wczytane = write(fd1,&buf,sizeof(int));
	if(dane_wczytane == -1){
		perror("blad przy wczytywaniu danych");
		exit(4);
	}
	printf("zapisano liczbe %d\n",buf);
		
	for(int i=0;i<procesy;i++){
		switch(fork())
		{
			case -1: perror("Nie utworzono procesu potomnego\n");
				break;
	
			case 0://proces potomny
				 execv("./prog.x",argv);
			 	break;
			default://proces macierzysty
				sleep(1);
				 break;
		}
	}
	while(wait(NULL)!=-1);

	int fd2 = open("numer.txt",O_RDONLY,0664);

	if(fd2 == -1){
		perror("Blad otwarcia pliku zrodlowego");
		exit(5);
	}
	
	dane_sczytane = read(fd2,&buf,sizeof(int));
	if(dane_sczytane == -1){
		perror("blad przy wczytywaniu danych");
		exit(6);;
	}	
	printf("Wartosc oczekiwana : %d, wartosc koncowa : %d\n",procesy*sekcje,buf);
	close(fd1);
	close(fd2);
	atexit(usuwam_semafor);
	sem_close(semid);

	return 0;
}
