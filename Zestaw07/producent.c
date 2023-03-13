#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <semaphore.h>
#include <sys/mman.h>
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
	char buf_magazyn[ROZMIAR];
	int i, fd1, fd2;
	struct cykliczny *ptr;
	int value1, value2;
	int dane_sczytane = 0;

	semid s1 = semOpen(name1);
	semid s2 = semOpen(name2);
	
	printf("P : otwarcie pliku i zapis do segmentu\n");
	fd1 = shmOpen("/glowny_segment");

	fd2 = open(argv[1],O_RDONLY);
	if(fd2 == -1){
		perror("open error\n");
		exit(1);
	}
	printf("P : otwarto kolejke oraz magazyn\n");
	
	ptr = (void *)shmMap(fd1,ROZMIAR); 

	do{
	sleep(1);
	dane_sczytane = read(fd2,buf_magazyn,ROZMIAR);
	if(dane_sczytane == -1){
		perror("read error\n");
		exit(2);
	}
	else if(dane_sczytane == 0){
		strcpy(ptr->buf, "\0");
		exit(3);
	}
	else{
	printf("P : przeczytano i wyslano znak : %s\n",buf_magazyn);
	
	semP(&s1);
	sem_getvalue(&s1, &value1);
	printf("semafor1 : %d\n", value1);

	bufor = buf_magazyn[i];
	i++;
	
	ptr->buf[ptr->end] = bufor;
	ptr->end++;
	if(ptr->end == ptr->size){
		ptr->end = 0;
		ptr->size++;
	}

	printf("pomyslnie zapisano do pamieci dzielonej\n");
	sem_getvalue(&s2, &value2);
	printf("semafor2 : %d\n", value2);
	semV(&s2);
	}
	}
	while(dane_sczytane);

	munmap(ptr, ROZMIAR);
	close (fd1);
	close (fd2);
	semClose(&s1);
	semClose(&s2);
	return 0;
}
