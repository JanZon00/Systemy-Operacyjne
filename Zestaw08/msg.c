#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/sem.h>
#include <mqueue.h>
#include <string.h>
#include "msg.h"

int msgCreate(const char *name){
	mqd_t mqdes;
	attr.mq_flags = 0;
	attr.mq_maxmsg = MAX_MSG;
	attr.mq_msgsize = MAX_MSG_SIZE;
	attr.mq_curmsgs = 0;

	if((mqdes = mq_open(name, O_RDONLY | O_CREAT, QUEUE_PERMISSION, &attr)) == -1){
	      	perror("msgCreate failed\n");
		exit(1);
	}
	return mqdes;	
}

int msgOpen(const char *name){
	mqd_t mqdes = mq_open(name, O_WRONLY);
	if (mqdes == -1){
	       	perror("msgOpen failed\n");
	}
	return mqdes;
}

void msgClose(const char *name){
	mqd_t mqdes = mq_open(name, O_RDWR | O_NONBLOCK);
	int rc = mq_close(mqdes);
	if (rc == -1){
	       	perror("msgClose failed\n");
	}	
}

void msgRm(const char* name){
	int rc = mq_unlink(name);
	if (rc == -1){
	       	perror("msgRm failed\n");
	}	
}

void msgSend(int msgid, komunikat *msg){
	int send = mq_send(msgid, msg, strlen(msg) + 1, 0);
	if (send == -1){
	       	perror("msgSend failed\n");
	}	
}

void msgRecv(int msgid, komunikat *msg){
	int rec = mq_receive(msgid, msg, MSG_BUFFER_SIZE, NULL);
	if (rec == -1){
	       	perror("msgRecv failed");
	}	
}

void msgInfo(int msgid){
	attr.mq_maxmsg = MAX_MSG;
	attr.mq_msgsize = MAX_MSG_SIZE;
	int n = mq_getattr(msgid, &attr);
	if (n == -1){
		perror("msgInfo failed");
	}
	printf("Maximum lenght of messages: %ld\n", attr.mq_maxmsg);
	printf("Maximum message size: %ld\n", attr.mq_msgsize);	
}	


