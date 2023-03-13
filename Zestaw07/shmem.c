#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "shmem.h"

struct stat buf;

int shmCreate(const char* name, int size){

	int fd = shm_open(name, O_RDWR | O_CREAT | O_EXCL, 0660);
	if (fd == -1){
    		perror("shm_create failed\n");
    		exit(1);
	}
	int n = ftruncate(fd, size);
	if (n == -1){
		perror("ftruncate failed\n");
		exit(2);
	}
	return fd;
}

int shmOpen(const char* name){
	int fd = shm_open(name,O_RDWR,0);
	if (fd == -1){
	       	perror("shm_open failed\n");
	        exit(3);
	}	
	return fd;
}

void shmRm(const char* name){
	int fd = shm_unlink(name);
	if (fd == -1){
	       perror("shm_unlink failed\n");
	       exit(3);
	}	
}

void* shmMap(int fd, int size){
	char *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 
	if (ptr == (void*)-1){
	       perror("mmap failed\n");
	       exit(4);
	}
	return ptr;	
}

void shmClose(void *ptr, int fd, int size){
	int n = munmap(ptr, size);
	if (n == -1){
	       perror("munmap failed");
	       exit(5);
	}
	int m = close(fd);
	if (m == -1){
		perror("close failed");	
		exit(6);
	}	
}

int shmSize(int fd){
	int n = fstat(fd, &buf);
	if (n != 0){
		perror("fstat failed");
		exit(7);
	}	
	printf("Rozmiar pamieci wynosi %ld\n",buf.st_size);
	return fd;
}

void shmInfo(int fd){
	int n = fstat(fd, &buf);
	if (n != 0){
		perror("fstat failed");
		exit(8);
	}
	printf("Informacje o pamieci dzielonej :\n");
        printf("ID urzadzenia : %ld\n",buf.st_dev);
 	printf("Ilosc dowiazan : %ld\n",buf.st_nlink);
 	printf("ID wlasciciela pliku : %hu\n",buf.st_uid);
 	printf("ID grupy : %hu\n",buf.st_gid);

}	


