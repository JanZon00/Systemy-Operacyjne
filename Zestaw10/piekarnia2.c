#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#define WATKI 4

volatile int wybieranie[WATKI];
volatile int numery[WATKI];
volatile int licznik = 0;

pthread_t th[WATKI];

void lock(int watek){
   
	wybieranie[watek] = 1;

	int max_numer = 0;

	for(int w = 0; w < WATKI; w++){

		int numer = numery[w];
		max_numer = numer > max_numer ? numer : max_numer;
	}

	numery[watek] = max_numer + 1;

	wybieranie[watek] = 0;

	
	for (int watek2 = 0; watek2 < WATKI; watek2++){

		while(wybieranie[watek2]){
		}
      
		while(numery[watek2] != 0 && (numery[watek2] < numery[watek] || (numery[watek2] == numery[watek] && watek2 < watek))) {
		}
	}	
}

void unlock(int watek){

	numery[watek] = 0;
}

void sekcja_krytyczna(int watek){
   
	licznik = licznik + 1;
	printf("licznik : %d\n", licznik);
	printf("\033c");

}

void* sekcja(void* arg){

	      long watek = (long)arg;
		   for( int i = 0; i<100; i++){

			lock(watek);

			sekcja_krytyczna(watek);

			unlock(watek);

		}
		
	return NULL;
}

int main(void)
{	

	for(int n = 0; n< WATKI; n++) {
		if(pthread_create(&(th[n]), NULL, &sekcja, (void*)((long)n)) != 0){
			perror("pthread_create failed\n");
			return 1;
		}
	}

	for(int n = 0; n<WATKI; n++){

		if(pthread_join(th[n], NULL) != 0){
			perror("pthread_join failed\n");
			return 1;
		}
	}
	printf("\nlicznik globalny : %d\n", licznik);
	return 0;
}

