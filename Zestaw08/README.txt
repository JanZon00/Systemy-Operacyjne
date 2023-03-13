===========================================================================
Autor : Jan Zon					Ostatnia zmiana: 30.05.2021
===========================================================================
Zawartosc:
=========

Katalog Zestaw08 zawiera 6 plikow:
---------------------------------------------------------------------------

I. plik Makefile do kompliacji programow. Zawiera dodatkowo odpowiednie operacje 
umozliwiajace utworzenie biblioteki statycznej(libmsg.a) oraz dynamicznej (libmsg.so).

II. plik tekstowy README

III. plik msg.c - zawiera implementacje funkcji do obslugi kolejek komunikatow standardu POSIX

IV. plik msg.h - zawiera definicje funkcji do obslugi kolejek komunikatow standardu POSIX

V. plik serwer.c - dziala w korelacji z programem klient. Tworzy kolejke, nastepnie czeka na polecenie
od klienta. Otrzymuje pid procesu oraz dzialanie matematyczne jako string. Zamienia dzialanie na liczby,
dokonuje odpowiedniego dzialania na dwoch otrzymanych cyfrach w zaleznosci od otrzymanego znaku +,-,* lub /.
Wysyla gotowy wynik z powrotem do klienta ktory wypisuje wynik na ekranie. 

VI. plik klient.c - pobiera od uzytkownika 2 cyfry oraz znak w kolejnosci: cyfra, znak, cyfra. Dane zapisuje
w buforze ktory wysyla do otwartej kolejki. Nastepnie odczytuje wynik dzialania od serwera.

Program dziala dla wielu klientow. Program tworzy osobne kolejki w zaleznosci od numeru pid procesu klienta.

Program nalezy zakonczyc sygnalem SIGINT tj. ctrl-c z klawiatury.

* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania i uruchamiania powyzsych programow,
a takze do czyszczenia katalogu z plikow (w naszym przypadku) z rozszerzeniem .o .x .a .so

Aby skompilowac wszystkie programy nalezy uzyc komendy make
Aby skompilowac jeden wybrany program nalezy uzyc komendy make <nazwa programu>
Aby wywolac program nalezy uzyc komendy ./<nazwa programu>.x
Aby usunac zbedne pliki nalezy wykonac: make clean
---------------------------------------------------------------------------
