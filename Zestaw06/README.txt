===========================================================================
Autor : Jan Zon					Ostatnia zmiana: 03.05.2021
===========================================================================
Zawartosc:
=========

Katalog Zestaw06 zawiera 8 plikow:
---------------------------------------------------------------------------

I. numer.txt plik tekstowy wykorzystywany w programie powielacz oraz prog

II. plik Makefile do kompliacji programu. Zawiera dodatkowo odpowiednie operacje 
umozliwiajace utworzenie biblioteki statycznej.

III. plik tekstowy README

IV. plik sem.c - zawiera implementacje funkcji do obslugi nazwanego semafora

V. sem.h - zawiera definicje funkcji do obslugi nazwanego semafora

VI. semuse.c - program ktory przyjmuje jeden jednoliterowy argument i przy uzyciu utworzonej biblioteki
wykonuje poszczegolne operacje na semaforze ogolnym

VII. powielacz.c - program sluzy do powielania procesow realizujacych wzajemne wykluczanie. Program tworzy i
inicjuje semafor, na koncu go usuwa.

VII. prog.c -  Program prog.c wielokrotnie w petli wchodzi do sekcji krytycznej. Liczbe iteracji otrzymuje
jako argument programu. Program rowniez odczytuje wartosc 0 zapisana przez program powielacz. NAstepnie w sekcji
krytycznej zwieksza wartosc o jeden. 
* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania i uruchamiania powyzsych programow,
a takze do czyszczenia katalogu z plikow (w naszym przypadku) z rozszerzeniem .o oraz .x

Aby skompilowac wszystkie programy nalezy uzyc komendy make
Aby skompilowac jeden wybrany program nalezy uzyc komendy make <nazwa programu>
Aby wywolac program nalezy uzyc komendy ./<nazwa programu>.x
Aby wyczyscic zawartosc katalogu (usunac zbedne pliki, w tym przypadku wszystkie
pliki z rozszerzeniem .o oraz .x), nalezy wykonac: make clean
---------------------------------------------------------------------------
