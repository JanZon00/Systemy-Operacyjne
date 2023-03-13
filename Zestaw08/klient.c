#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <mqueue.h>
#include <signal.h>
#include "msg.h"

char name2[10];

void msg_Close_Rm(int sig){
	msgClose(name2);
	msgRm(name2);
	printf("Usunieto kolejke\n");
	exit(1);
}

int main(int argc, char *argv[]){

	int liczba1;
	int liczba2;
	char znak[10];

	char msg [MSG_BUFFER_SIZE];
	char in_buffer [MSG_BUFFER_SIZE];
	mqd_t qd_serwer, qd_klient;

	for(;;){

	printf("Podaj dzialanie matematyczne\n");
	if(signal(SIGINT, msg_Close_Rm) == SIG_ERR){
		exit(1);
	}	
	scanf("%d""%s""%d",&liczba1, znak, &liczba2);
	sprintf (msg,"%d%s%d", liczba1, znak, liczba2);

	sprintf (name2, "/%d", getpid());

	qd_klient = msgCreate(name2);
	qd_serwer = msgOpen(NAME);
		
	printf("Wysylam dzialanie %s\n",msg);

	msgSend(qd_serwer, msg);

	msgSend(qd_serwer, name2);

	msgRecv(qd_klient, in_buffer);

	printf("Otrzymano wynik: %s\n\n",in_buffer);

	close(qd_serwer);
	close(qd_klient);
	}
	return 0;
}	

