#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#define ROZMIAR 1

char buf[ROZMIAR];

int fd[2];
int fd3,fd4;
int dane_sczytane = 0;
int dane_wczytane = 0;

void producent(){
	
		fd3 = open("magazyn.txt",O_RDONLY);
	do{
		dane_sczytane = read(fd3,buf,ROZMIAR);
		if(dane_sczytane == -1){
			perror("read error\n");
			exit(1);
		}
		
		dane_wczytane = write(fd[1],buf,dane_sczytane);
		if(dane_wczytane == -1){
			perror("write error\n");
			exit(2);
		}
		
		if((dane_sczytane)>0){
		printf("M:wyslalem znak: %c\n",*buf);
		}
		sleep(1);
	}
	while(dane_sczytane);	
}

void konsument(){
		fd4 = open("schowek.txt",O_WRONLY);
	do{
		dane_sczytane = read(fd[0],buf,ROZMIAR);
		if(dane_sczytane == -1){
			perror("read error\n");
			exit(3);
		}

		dane_wczytane = write(fd4,buf,dane_sczytane);
		if(dane_wczytane == -1){
			perror("write error\n");
			exit(4);
		}
		
		if((dane_sczytane)>0){
		printf("P:zapisalem znak: %c\n",*buf);
		}
		sleep(1);
	}
	while(dane_sczytane);
}


int main(int argc, char* argv[]){


	if(argc != 3){
		perror("Niepoprawna skladnia. Prawidlowa: ./prodkons.x <plik zrodlowy> <plik docelowy>\n");
		exit(1);
	}

	if (pipe(fd) == -1){
		printf("wystapil problem podczas otwierania potoku\n");
	}
	
	switch (fork())
	{
		case -1: //blad podczas tworzenia procesu potomnego
			perror("Nie utworzono procesu potomnego");
			break;
	
		case 0: //proces potomny
			close(fd[1]);
			printf("otwarcie pliku do odczytu\n");
			konsument();
			close(fd[0]);
			close(fd4);
			break;

		default://proces macierzysty
			close(fd[0]);
			printf("otwarcie pliku do zapisu\n");
			producent();
			close(fd[1]);
			close(fd3);
			printf("M:przesylanie zakonczone\n");
			break;
			
	}
	wait(NULL);
	return 0;
}


