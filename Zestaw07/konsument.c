#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <fcntl.h>
#include "shmem.h"
#include "sem.h"

#define ROZMIAR 1

typedef struct cykliczny
	{
		int size;
		int beg;
		int end;
		char buf[ROZMIAR];
	}cykliczny;	


int main(int argc, char* argv[]){

	const char* name1 = "/semafor1";
	const char* name2 = "/semafor2";

	char bufor;
	char buf_schowek[ROZMIAR];
	int i, fd1, fd2;
	int value1, value2;
	struct cykliczny *ptr;
	int dane_wczytane = 0;

	semid s1 = semOpen(name1);
	semid s2 = semOpen(name2);

	printf("K : otwarcie pliku i zapis z segmentu\n");
	fd1 = shmOpen("/glowny_segment");

	fd2 = open(argv[2],O_WRONLY);
	if(fd2 == -1){
		perror("open error\n");
		exit(1);
	}
	printf("K : otwarto kolejke oraz schowek\n");
	exit(1);
	ptr = (void *)shmMap(fd1,ROZMIAR);
	
	do{
	
	semP(&s2);
	sem_getvalue(&s2, &value2);
	printf("semafor2 : %d\n", value2);

	bufor = ptr->buf[ptr->beg];
	ptr->beg++;
	if(ptr->beg == ptr->size){
		ptr->beg = 0;
		ptr->size--;
	}

	printf("otrzymano : %c\n", bufor);
	buf_schowek[i] = bufor;
	i++;

	dane_wczytane = write(fd2,buf_schowek,ROZMIAR);
	if(dane_wczytane == -1){
		perror("write error\n");
		exit(4);
	}
	
	printf("pomyslnie zapisano do schowka\n");
	sem_getvalue(&s1, &value1);
	printf("semafor1 : %d\n", value1);
	semV(&s1);
	}
	while(dane_wczytane);

	munmap(ptr, ROZMIAR);
	close(fd1);
	close(fd2);
	semClose(&s1);
	semClose(&s2);
	
	return 0;
}
