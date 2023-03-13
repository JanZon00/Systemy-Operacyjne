===========================================================================
Autor : Jan Zon					Ostatnia zmiana: 03.05.2021
===========================================================================
Zawartosc:
=========

Katalog Zestaw05 zawiera 7 plikow: 
---------------------------------------------------------------------------

I. magazyn.txt, schowek.txt - pliki tekstowy wykorzystywane w pozostalych programach

II. plik Makefile do kompilacji programow

III. plik tekstowy README

IV. Plik producent.c oraz konsument.c. Kazdy z nich pobiera z argumentow wywolania
odpowiedni plik tekstowy. Pierwszy z nich otwiera potok. Nastepnie otwiera plik
tekstowy magazyn.txt z ktorego pobiera bajty i zapisuje je do potoku nazwanego.
Drugi program rowniez otwiera potok oraz plik tekstowy do zapisu, nastepnie
odczytuje zapisane wczesniej bajty w potoku i zapisuje je do pliku tekstowego
schowek.txt.

V. fifo.c - program tworzy potok nazwany. Nastepnie przy uzyciu funkcji fork oraz
switch dwukrotnie tworzy procesy potomne w ktorych wywoluje programy producent oraz
konsument przy uzyciu funkcji execv(). Program rowniez posiada funkcje atexit 
ktora sluzy do usuwania potoku.



* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania i uruchamiania powyzsych programow,
a takze do czyszczenia katalogu z plikow (w naszym przypadku) z rozszerzeniem .o oraz .x

Aby skompilowac wszystkie programy nalezy uzyc komendy make
Aby skompilowac jeden wybrany program nalezy uzyc komendy make <nazwa programu>
Aby wywolac program nalezy uzyc komendy ./<nazwa programu>.x
Aby wyczyscic zawartosc katalogu (usunac zbedne pliki, w tym przypadku wszystkie
pliki z rozszerzeniem .o oraz .x), nalezy wykonac: make clean
--------------------------------------------------------------------------------
