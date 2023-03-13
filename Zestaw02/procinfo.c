#include <stdio.h>
#include "procinfo.h"
#include <sys/types.h>
#include <unistd.h>

int procinfo(const char* name){
	printf("%s = %s, UID: %d, GID: %d, PID: %d, PPID: %d, PGID: %d\n","name",name, getuid(),
	getgid(), getpid(), getppid(), getpgrp());

	return 0;	
}

