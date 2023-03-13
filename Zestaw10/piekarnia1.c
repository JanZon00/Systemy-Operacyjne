#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#define WATKI 6


volatile int wybieranie[WATKI];
volatile int numery[WATKI];

pthread_t th[WATKI];
int licznik1, licznik2, licznik3, licznik4, licznik5, licznik6;
int licznik_globalny = 0;
int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
int g = 0, h = 0, i = 0, j = 0, k = 0, l = 0;
int y = 20, x = 50, u = 1;

char komunikat[4][40] = {"\033[33mczekam\033[m", "\033[34mw sekcji krytycznej\033[m", "\033[32mza sekcja krytyczna\033[m", "\033[31mzakonczono\033[m"};

void pozycja(unsigned x, unsigned y){
	printf("\033[%d;%dH", y, x);
}

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
   
	   int ilosc = 0;
	   int iteracja = 0;

	   printf("\033c");
	   printf("Watek 1:\nWatek 2:\nWatek 3:\nWatek 4:\nWatek 5:\nWatek 6:");
	   if(ilosc = 1){
	      if(iteracja == 0 || iteracja == 1){
	         g = 1;
	         licznik1 = licznik_globalny;
			   licznik1++;
	         pozycja(x, a);
	         printf("licznik : %d\n", licznik1);
			   licznik_globalny = licznik1;
	      }
		else g = 3;
	   }
	   else if(ilosc = 2){
	      if(iteracja == 0 || iteracja == 1){
	         h = 1;
	         licznik2 = licznik_globalny;
			   licznik2++;
	         pozycja(x, b);
	         printf("licznik : %d\n", licznik2);
			   licznik_globalny = licznik2;
	      }
	      else h = 3;
	   }
	   else if(ilosc = 3){
	      if(iteracja == 0 || iteracja == 1){
	         i = 1;
	         licznik3 = licznik_globalny;
			   licznik3++;
	         pozycja(x, c);
	         printf("licznik : %d\n", licznik3);
			   licznik_globalny = licznik3;
	      }
	      else i = 3;
	   }
	   else if(ilosc = 4){
	      if(iteracja == 0 || iteracja == 1){
	         j = 1;
	         licznik4 = licznik_globalny;
			   licznik4++;
	         pozycja(x, d);
	         printf("licznik : %d\n", licznik4);
			   licznik_globalny = licznik4;
	      }
	      else j = 3;
	   }	
	   else if(ilosc = 5){
	      if(iteracja == 0 || iteracja == 1){
	         k = 1;
	         licznik5 = licznik_globalny;
			   licznik5++;
	         pozycja(x, e);
	         printf("licznik : %d\n", licznik5);
			   licznik_globalny = licznik5;
	      }
	      else k = 3;
	   }	
	   else{
	      if(iteracja == 0 || iteracja == 1){
	         l = 1;
	         licznik6 = licznik_globalny;
			   licznik6++;
	         pozycja(x, f);
	         printf("licznik : %d\n", licznik6);
			   licznik_globalny = licznik6;
	      }
	      else l = 3;
	   }
	
	   pozycja(y, a); printf("%s\n", komunikat[g]);
		pozycja(y, b); printf("%s\n", komunikat[h]);
		pozycja(y, c); printf("%s\n", komunikat[i]);
		pozycja(y, d); printf("%s\n", komunikat[j]);
		pozycja(y, e); printf("%s\n", komunikat[k]);
		pozycja(y, f); printf("%s\n", komunikat[l]);
	
		g = 0, h = 0, i = 0, j = 0, k = 0, l = 0;
	   a++, b++, c++, d++, e++, f++;

	   if(a == 7) a = 1;
	   if(b == 7) b = 1;
	   if(c == 7) c = 1;
	   if(d == 7) d = 1;
	   if(e == 7) e = 1;
	   if(f == 7) f = 1;
	
	   ilosc++;
	   iteracja++;

}

void* sekcja(void* arg){

         int m;
	      long watek = (long)arg;
		   for( m = 0; m<3; m++){

			lock(watek);
			sleep(1);

			sekcja_krytyczna(watek);

			sleep(1);
			unlock(watek);
		 
			printf("\033[%d;%dH\033[2K", y ,u);
			pozycja(y, u);
		   printf("%s\n", komunikat[2]);
	
			u++;
			if(u == 7) u = 1;
		}
		
	return NULL;
}

int main(void)
{	
   
	printf("\033c");

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
	printf("\033c");
	printf("Watek 1:\nWatek 2:\nWatek 3:\nWatek 4:\nWatek 5:\nWatek 6:");
	pozycja(x, f);
	printf("licznik : %d\n", licznik_globalny);
	pozycja(y, 1); printf("%s\n", komunikat[3]);
	pozycja(y, 2); printf("%s\n", komunikat[3]);
	pozycja(y, 3); printf("%s\n", komunikat[3]);
	pozycja(y, 4); printf("%s\n", komunikat[3]);
	pozycja(y, 5); printf("%s\n", komunikat[3]);
	pozycja(y, 6); printf("%s\n", komunikat[3]);
	printf("\nlicznik globalny : %d\n", licznik_globalny);
	return 0;
}


