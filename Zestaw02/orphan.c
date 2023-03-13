#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "procinfo.h"

int main(int argc,const char* argv[])
{
	int pokolenie = 0;

	printf("%d. ",pokolenie); //proces glowny
	procinfo(argv[0]);

	for(int i=0; i<1; i++)
	{
		switch(fork())
		{
			case-1: // blad podczas tworzenia procesu potomnego
				perror("Nie utworzono procesu potomnego");
				return -1;
			
			case 0: // proces potomny
				pokolenie+=1;
				printf("%d. ",pokolenie);
				procinfo("Proces Potomny");
				sleep(2);
				break;

			default:// proces macierzysty
				exit(1);
				break;
		}
	}
	return 0;
}

