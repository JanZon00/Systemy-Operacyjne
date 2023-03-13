#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

void potomek(char* operation,char* sig){
   for(int i=0;i<4;i++){
	switch(fork()){
		case -1: //blad podczas tworzenia procesu potomnego
			perror("Nie utworzono procesu potomnego\n");
			break;
		case 0:// proces potomny
			printf("WNUK: PID = %d, PPID = %d, PGID = %d\n",getpid(),getppid(),getpgrp());

			execl("./obsluga.x","./obsluga.x",operation,sig,(char*)NULL);
			
			break;
		
		case 1://proces macierzysty
			sleep(3);
			wait(NULL);
			break;	
	}	
    }
}	

int main(int argc,char* argv[])
{
	
	if (argc != 3){
		perror("Niepoprawna skladnia. Poprawnie: ./grupa.x <akcja> <numer sygnalu>\n");
		exit(1);
	}	
	int pid;
	char operation = argv[1][0];
	int sig = atoi (argv[2]);

	printf("Otrzymano operacje %c oraz sygnal %d\n",operation,sig);
	
		switch(pid = fork())
		{
			case-1: // blad podczas tworzenia procesu potomnego
				perror("Nie utworzono procesu potomnego");
				return -1;
			
			case 0: // proces potomny
				signal(sig,SIG_IGN);
				setpgid(0,0);
				printf("POTOMEK: PID = %d, PPID = %d, PGID = %d\n",getpid(),getppid(),getpgrp());

				potomek(argv[1],argv[2]);
				break;

			default:// proces macierzysty
				sleep(3);
				kill(0,0);
				printf("Wysylanie sygnalu %d do grupy procesow o pgid =  %d\n",sig,getpgid(pid));
				kill(getpgid(pid),sig); 
				break;
		}
	while(wait(NULL)!=-1);

	return 0;
}

