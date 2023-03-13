#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <mqueue.h>
#include <string.h>
#include <signal.h>
#include "msg.h"

void msg_Close_Rm(int sig){
	msgClose(NAME);
	msgRm(NAME);
	printf("Usunieto kolejke\n");
	exit(1);
}

int main(int argc, char *argv[]){

	char in_buffer [MSG_BUFFER_SIZE];
	char out_buffer [MSG_BUFFER_SIZE];
	char pid [MSG_BUFFER_SIZE];
	mqd_t qd_serwer, qd_klient;

	for(;;){
	
	printf("Otwarto kolejke, czekam na klienta\n");
	
	if(signal(SIGINT, msg_Close_Rm) == SIG_ERR){
		exit(1);
	}

	qd_serwer = msgCreate(NAME);

	msgRecv(qd_serwer, in_buffer);

	msgRecv(qd_serwer, pid);
		
	printf("Otrzymano PID = %s oraz dzialanie %s\n",pid, in_buffer);

	qd_klient = msgOpen(pid);
		
		double wynik;
		double liczba1 = atoi(&in_buffer[0]);
		char znak = in_buffer[1];
		double liczba2 = atoi(&in_buffer[2]);
		
		double dodawanie = liczba1 + liczba2;
		double odejmowanie = liczba1 - liczba2;
		double dzielenie = liczba1/liczba2;	
		double mnozenie = liczba1*liczba2;
		if(znak == '+') wynik = dodawanie;
		if(znak == '-') wynik = odejmowanie;
		if(znak == '*') wynik = mnozenie;
		if(znak == '/') wynik = dzielenie;
		
		sprintf(out_buffer, "%.0lf", wynik);

	msgSend(qd_klient, out_buffer);
		
	printf("odpowiedz wyslana do klienta\n");
	close(qd_serwer);
	close(qd_klient);
	}
	return 0;
}

