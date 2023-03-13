#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/sem.h>
#include "sem.h"

int main(int argc, char* argv[])
{

	if(argc!= 2){
		perror("Niepoprawna skladnia. Poprawnie ./semuse.c <operacja>\n");
		exit(1);
	}

	const char* name = "/semafor";
	sem_t *semid = sem_open(name, O_CREAT | O_EXCL, 0666, 2);
	if (semid == NULL){
		perror("sem_open failed\n");
	}
	printf("Stworzylem semafor\n");	

	char operation = argv[1][0];

	switch(operation)
	{
		case 'i':
		{	
			printf("inicjuje semafor i wypisuje o nim informacje\n");
			semOpen(name);	
			break;
		}

		case 'r':
		{
			printf("usuwam semafor\n");
			semRemove(name);
			break;
		}

		case 'p':
		{	
			printf("opuszczam semafor\n");
			semP(semid);

			break;
		}

		case 'v':
		{
			printf("podnosze semafor\n");
			semV(semid);
			break;
		}

		case 'q':
		{	
			printf("wypisuje informacje o semaforze\n");
			semInfo(semid);
			break;
		}

		default:
		{
			printf("Niepoprawny argument\n");
			break;
		}
	}
	sem_unlink(name);
	sem_close(semid);
	return 0;
}

