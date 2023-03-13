===========================================================================
Autor : Jan Zon					Ostatnia zmiana: 31.05.2021
===========================================================================
Zawartosc:
=========

Katalog Zestaw06 zawiera 13 plikow:
---------------------------------------------------------------------------

I. plik Makefile do kompliacji programu. Zawiera dodatkowo odpowiednie operacje 
umozliwiajace utworzenie biblioteki statycznej oraz dynamicznej.

II. plik tekstowy README

III. magazyn.txt oraz schowek.txt - wykorzystywane w programie producenta oraz konsumenta do transportu danych

IV. sem.c zawiera implementacje funkcji do obslugi nazwanego semafora

V. sem.h - zawiera definicje funkcji do obslugi nazwanego semafora

VI. smmem.c - zawiera implementacje funkcji do obslugi pamieci dzielonej

VII. shmem.h - zawiera definicje funkcji do obslugi pamieci dzielonej

VI. shmuse1.x oraz shmuse2.x - sluza do demonstracji dzialania pamieci dzielonej. Wpisujac jednoliterowy argument 
oznaczajacy konkretna opcje oraz podajac rozmiar bufora mozemy utworzyc obszar pamieci dzielonej, zapisac
do niego wiadomosc, odczytac ja i wypisac oraz ostatecznie usunac obiekt pamieci dzielonej

VII. producent.c konsument.c - odczytuje wiadomosc zapisana w magazynie. Przy pomocy bufora cyklicznego oraz semaforow nazwanych, nastepuje synchronizacja z konsumentem ktory odbiera dane i zapisuje je w schowku

* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania i uruchamiania powyzsych programow,
a takze do czyszczenia katalogu z plikow (w naszym przypadku) z rozszerzeniem .o .x .a .so

Aby skompilowac wszystkie programy nalezy uzyc komendy make
Aby skompilowac jeden wybrany program nalezy uzyc komendy make <nazwa programu>
Aby wywolac program nalezy uzyc komendy ./<nazwa programu>.x
Aby wyczyscic zawartosc katalogu, nalezy wykonac: make clean
---------------------------------------------------------------------------
