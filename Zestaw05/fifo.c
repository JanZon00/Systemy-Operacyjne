#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

void usuwam_potok(void){
	unlink("potok");
	printf("usunieto potok\n");
}

int main(int argc, char *argv[]){

	
	if(argc != 3){
		perror("Niepoprawna skladnia. Prawidlowa: ./fifo.x <plik zrodlowy> <plik docelowy>\n");
		exit(1);
	}	

	const char potok[] = "potok";
	
	if(mkfifo(potok,0777)==-1)
	{
		printf("Utworzenie potoku niemozliwe\n");
		return -1;
	}
	
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

	atexit(usuwam_potok);		
	return 0;
}

