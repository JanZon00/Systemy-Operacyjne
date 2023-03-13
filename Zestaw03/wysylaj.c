#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc,char* argv[])
{	
	
	if(argc != 3){
		perror("Niepoprawna skladnia. Poprawnie: ./wysylaj.x <akcja> <numer sygnalu>\n");
		exit(1);
	}	

	char operation = argv[1][0];
	int sig = atoi(argv[2]);
	int pid;
	
	printf("otrzymano operacje : %c oraz sygnal %d\n",operation,sig);
	
		switch(pid = fork())
		{
			case-1: // blad podczas tworzenia procesu potomnego
				perror("Nie utworzono procesu potomnego");
				break;
			
			case 0: // proces potomny
				execl("./obsluga.x","./obsluga.x",argv[1],argv[2],(char*) NULL );
				break;

			default:// proces macierzysty
				if(kill(0,0)!=0){
					printf("Potomek nie istnieje");
				}
				sleep(2);
				printf("Wysylanie sygnalu %d do procesu o pid = %d\n",sig, pid);

				kill (pid,sig);
				wait(NULL);
				break;
		}

	return 0;
}

