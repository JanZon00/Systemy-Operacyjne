===========================================================================
Autor : Jan Zon					Ostatnia zmiana: 18.04.2021
===========================================================================
Zawartosc:
=========

Katalog Zestaw03 zawira 4 programy w jezyku C:
---------------------------------------------------------------------------

I. obsluga.c : Program do obslugi sygnalow. Po otrzymaniu odpowiednich argumentow 
oraz odpowiedniej ich ilosci program wybiera podana w argumencie opcje. Dzieki 
funkcji pause() program czeka na sygnaly od nas. Dla podanej akcji "d" wykonuje
sie opracja domyslna dla sygnalu, dla "i" nastepuje ingorowanie sygnalu podanego jako
trzeci argument, dla "p" nastepuje przechwycenie oraz wlasna obsluga sygnalu.
Przy podaniu niewlasciwej liczby argumentow czyli roznej od 3, program wypisuje komunikat
o bledzie. 

II. wysylaj.c : Program uruchamia program obsluga.c dzieki funkcji execl w procesie potomnym
oraz wysyla do niego sygnaly poprzez funkcje kill() z procesu macierzystego. Program
przyjmuje te same argumenty jak obsluga.c oraz wypisuje komunikaty o bledzie w podobnych
przypadkach

III. grupa.c : Program tworzy proces potomny, ktory jednoczesnie staje sie liderem
grupy zawierajacej 4 procesy potomne wykonujace program obsluga.c. Proces macierzysty 
wysyla sygnaly dla calej grupy procesow potomnych po uzyskaniu identyfikatora 
dzieki funkcji getpgid(). Proces bedacy liderem grupy 4 procesow ignoruje te sygnaly 
jedynie czekajac na zakonczenie dzialania swoich potomkow.

* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania i uruchamiania powyzsych programow,
a takze do czyszczenia katalogu z plikow (w naszym przypadku) z rozszerzeniem .o oraz .x

Aby skompilowac wszystkie programy nalezy uzyc komendy make
Aby skompilowac jeden wybrany program nalezy uzyc komendy make <nazwa programu>
Aby wywolac program nalezy uzyc komendy ./<nazwa programu>.x <rodzaj akcji> <numer sygnalu>
W tym przypadku mozliwe akcje to d (wykonianie operacji domyslnej dla sygnalu), i (ignorowanie
sygnalu) oraz p (przechwycenie oraz wlasna obsluga sygnalu). Numer sygnalu to przypisana do
niego konkretna wartosc.

Aby wyczyscic zawartosc katalogu (usunac zbedne pliki, w tym przypadku wszystkie
pliki z rozszerzeniem .o oraz .x), nalezy wykonac: make clean
--------------------------------------------------------------------------------

Pytania do zestawu

1. Krotko opisac funkcje i znaczenie czterech wybranych sygnalow, w tym dwoch nieprzechwytywalnych.
- SIGKILL oraz SiGSTOP : sygnaly nieprzechwytywalne ktorych proces nie moze zignorowac. Dzieki
temu system moze zawsze usunac niepozadane procesy. SIGSTOP powoduje zatrzymanie procesu, natomiast
SIGKILL powoduje bezwarunkowe zakonczenie procesu.

- SIGCHLD - zakonczenie procesu potomnego

- SIGHUP - zakonczenie procesu sterujacego terminalem

2. Ktore sygnaly mozemy wyslac w terminalu przy uzyciu skrotow klawiszowych?
- SIGINT [Ctrl -c] - przerwanie z klawiatury
- SIGQUIT [CTRL -\] - sekwencja wyjscia z klawiatury
- SIGTSTP [CTRL -z] - sekwencja zatrzymania z klawiatury
