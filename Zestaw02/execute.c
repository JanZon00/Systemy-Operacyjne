#include <stdio.h>
#include <unistd.h>
#include "procinfo.h"

int main(int argc,const char* argv[])
{
	printf("Pierwszy Komunikat\n");
	execl("./potomny.x",argv[0],(char*) NULL );

	printf("Drugi Komunikat\n");

	return 0;
}

