#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define ROZMIAR 1024

int main(int argc, char* argv[])
{
	if(argc != 3){
		perror("Niepoprawna skladnia. Prawidlowa skladnia: ./kopiuj.x <plik zrodlowy> <plik docelowy>\n");
		exit(1);
	}

	int fd1 = open(argv[1], O_RDONLY); //deskryptor pliku zrodlowego
	if(fd1 == -1){
	       	perror("Blad otwarcia pliku zrodlowego");
		return -1;
	}

	int fd2 = open(argv[2], O_WRONLY); // deskryptor pliku docelowego
	if(fd2 == -1){
	       	printf("Blad otwarcia pliku docelowego");
		return -1;
	}

		char* buf; //bufor, dynamiczna alokacja pamieci
		buf = malloc(ROZMIAR * sizeof(*buf));

		int dane_sczytane = 0;
		int dane_wczytane = 0;

	do{
		dane_sczytane = read(fd1, buf, ROZMIAR );// zapis danych do bufora
		if(dane_sczytane == -1){
			perror("blad przy sczytywaniu danych");
			return -1;
		}	

		dane_wczytane = write(fd2, buf, dane_sczytane);// wczytanie danych z bufora do pliku docelowego
		if(dane_wczytane == -1){
			perror("blad przy wczytywaniu danych");
			return -1;
		}	


	} while (dane_sczytane);
	
	printf("Kopiowanie zakonczone sukcesem\n");
	close(fd1);
	close(fd2);
	free(buf);

	return 0;
}


