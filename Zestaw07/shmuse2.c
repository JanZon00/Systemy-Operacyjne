#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/mman.h>
#include "shmem.h"


int main(int argc, char* argv[])
{

	if(argc != 3){
		perror("Niepoprawna skladnia. Poprawnie ./shmuse1.c <operacja> <rozmiar>\n");
		exit(1);
	}
	const char name[] = "/shared_memory";
	int size = atoi(argv[2]);
	char* ptr1;
	char* ptr2;
	char* ptr3;
	int fd1,fd2, fd3;
	char str[size];
	char operation = argv[1][0];

	switch(operation)
	{
		case 'c':	
			printf("tworze segment pamieci dzielonej o nazwie %s i rozmiarze %d\n",name,size);
			shmCreate(name, size);
			printf("tworzenie powiodlo sie\n");	
			break;
	
		case 'd':
		
			printf("usuwam segment pamieci dzielonej\n");
			
			shmRm(name);
			break;
		

		case 'r':
			
			printf("wypisuje zawartosc pamieci dzielonej na standardowe wyjscie\n");
			fd2 = shmOpen(name);
			ptr2 = shmMap(fd2, size);

		       	printf("TEKST : %s\n", ptr2);	
			munmap(ptr2, size);
			break;
		

		case 'w':
		
			fd1 = shmOpen(name);
			ptr1 = shmMap(fd1, size);
			printf("Podak dowolny tekst\n");
			scanf("%s", str);
			if(strlen(str) > size){
				printf("wiadomosc za dluga\n");
				exit(1);
			}

			strcpy(ptr1, str);
			printf("pomyslnie zapisano do pamiedzi dzielonej\n");
			munmap(ptr1, size);	
			break;
		

		case 'i':
			
			printf("wypisuje informacje o pamieci dzielonej\n");
			fd3 = shmOpen(name);
			ptr3 = shmMap(fd3, size);
			printf("nazwa segmentu = %s, adres = %p\n", name, ptr3);
			shmSize(fd3);
			shmInfo(fd3);
			munmap(ptr3, size);
			break;
		

		default:
		
			printf("Niepoprawny argument\n");
			break;
		
	}
	return 0;
}

