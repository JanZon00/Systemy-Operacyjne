#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#define ROZMIAR 1

int main(int argc, char* argv[]){

	char buf[ROZMIAR];
	int fd1,fd2;
	int dane_sczytane = 0;
	int dane_wczytane = 0;

	printf("otwarcie pliku i zapis z potoku\n");
	fd1 = open("potok", O_RDONLY);
	if (fd1 == -1){
		perror("blad podczas otwierania pliku");
		exit(1);
	}

	fd2 = open(argv[2],O_WRONLY);
	if (fd2 == -1){
		perror("blad podczas otwierania pliku");
		exit(2);
	}

	do{	
		dane_sczytane = read(fd1,buf,ROZMIAR);
		if(dane_sczytane == -1){
			perror("read error\n");
			exit(3);
		}
		
		dane_wczytane = write(fd2,buf,dane_sczytane);
		if(dane_wczytane == -1){
			perror("write error\n");
			exit(4);
		}	

		if((dane_wczytane)>0){
			printf("odebrano i przeslano znak : %c\n",*buf);
		}



		sleep(1);
	}
	while(dane_sczytane);	

	close(fd1);
	close(fd2);
	return 0;
}
