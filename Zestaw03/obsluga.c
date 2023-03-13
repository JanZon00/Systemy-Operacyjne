#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>


void handler(int sig){
	printf("otzymano sygnal %d\n",sig);
}

int main(int argc,char* argv[])
{	
	if(argc!= 3){
		perror("Niepoprawna skladnia. Poprawnie: ./obsluga.x <akcja> <numer sygnalu>\n");
		exit(1);
	}
	
	printf("PID: %d, PPID: %d, PGID: %d\n",getpid(),getppid(),getpgrp());
	
	char operation = argv[1][0];
	int sig = atoi (argv[2]);

	switch(operation)
	{

		case 'd':
			printf("wykonywanie operacji domyslnej dla sygnalu\n");
		{
			if(signal(sig,SIG_DFL)==SIG_ERR){
				perror("Nie otrzymano sygnalu\n");
				exit(2);
			}
			pause();
			break;
		}

		case 'i':
			printf("ignorowanie sygnalu\n");
		{
			if(signal(sig,SIG_IGN)==SIG_ERR){
				perror("Nie otrzymano sygnalu\n");
				exit(3);
			}
			pause();
			break;
		}

		case 'p':
			printf("przechwycenie i wlasna obsluga sygnalu\n");
		{
			if(signal(sig,handler)==SIG_ERR){
				perror("nie otrzymano sygnalu");
				exit(4);
			}
			pause();
			break;
		}
		default:
		{
			printf("niepoprawny argument\n");
			break;
		}	
	}

	return 0;
}	
