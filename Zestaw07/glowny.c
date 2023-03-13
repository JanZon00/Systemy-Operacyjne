#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <semaphore.h>
#include "shmem.h"
#include "sem.h"

int main(int argc, char *argv[]){

		
	if(argc != 3){
		perror("Niepoprawna skladnia. Prawidlowa: ./fifo.x <plik zrodlowy> <plik docelowy>\n");
		exit(1);
	}		
		
		int fd;
		const char* name = "/glowny_segment";
		const char* name1 = "/semafor1";
		const char* name2 = "/semafor2";
		const int size = 12;

		semCreate(name1, 12);
		semCreate(name2, 0);

		fd = shmCreate(name,size);
		
		printf("utworzono segment pamieci dzielonej o nazwie %s i rozmiarze %d\n",name,size);
		
		switch(fork())
		{
			case -1://blad podczas tworzenia procesu potomnego
				perror("Nie utworzono procesu potomnego\n");
				break;
			case 0: // proces potomny
				execv("./producent.x",argv);
				break;

			default:// proces macierzysty
				break;
		}
		sleep(1);	
		switch(fork())
		{
			case -1: perror("Nie utworzono procesu potomnego\n");
				 break;
			case 0:// proces potomny
				 execv("./konsument.x",argv);
				 break;

			default:// proces macierzysty
				 break;

		}

	wait(NULL);
	wait(NULL);
	
	close(fd);
	shm_unlink("/glowny_segment");
	semRemove(name2);
	semRemove(name1);

	return 0;
}

