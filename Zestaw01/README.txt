===========================================================================
Autor : Jan Zon					Ostatnia zmiana: 28.03.2021
===========================================================================
Zawartosc:
=========

Katalog Zestaw01 zawira 4 programy w jezyku C:
---------------------------------------------------------------------------

I. Procinfo : Program sklada sie z 3 plikow :
- procinfo.c : zawiera definicje funkcji procinfo ktora wypisuje identyfikatory procesow.
- procinfo.h : zawiera deklaracje funkcji procinfo.
- main.c : zawiera implementacje funkcji main ktora wywoluje funkcje procinfo.

II. Kopiowanie : Program sklada sie z jednego pliku kopiuj.c
Program za pomoca bufora kopiuje zawartosc jednego pliku do drugiego.

III. Procesy.c : Program sklada sie z trzech plikow : procesy.c procinfo.h procinfo.c
Program wypisuje identyfikatory UID, GID, PID, PPID, PGID dla danego procesu.

IV. Lider.c : Program sklada sie z trzech plikow : lider.c procinfo.h procinfo.c
Jest modyfikacja programu procesy.c gdzie kazdy proces staje sie liderem swojej wlasnej grupy.

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

Pytania do zestawu:
1. Opisac dokladnie jak dziala funkcja fork()?
Funkcja fork() jest funkcja systemowa ktora duplikuje proces tworzac jego identyczny
klon. Powstaja dwa procesy, macierzysty oraz jego klon ktory nazywamy procesem potomnym
od niego. Ma identyczne dane i kod. Proces macierzysty kontynuuje dzialanie tuz po
wywolaniu fork().Proces potomny rozpoczyna swoje dzialanie tuz po wywolaniu fork().
Proces macierzysty i proces potomny roznia sie identyfikatorem PID i wartoscia
zwracana przez funkcje fork().

2. Ile powstaje procesow w zadaniu procesy i dlaczego?
Mamy proces macierzysty, po pierwszej iteracji tworzony jest
potomek macierzystego. Po drugiej iteracji tworzony jest  kolejny potomek 
macierzystego oraz potomek potomka macierzystego. W trzeciej iteracji kazdy istniejacy
proces tworzy swojego potomka. W sumie mamy 8 procesow po 3 iteracjach.

3. Ile procesow powstanie przy n-krotnym wywolaniu funkcji fork i dlaczego?
Powstaje 2^n procesow. Przy kazdej iteracji kazdy proces tworzy klon samego siebie.
Ilosc procesow zwieksza sie za kazdym razem dwukrotnie. 

4. Jak uzywajac funkcji sleep i bez odwolywania sie do funkcji wait() zapewnic
aby procesy macierzyste konczyly sie dopiero po procesach potomnych.
Mozemy w funkcji switch()  w przypadku dla procesu rodzica ustawic warunek dla ktorego
proces bedzie spal do momentu az wszystkie dzieci zdaza zakonczyc swoj proces.

5. Jaka wartosc zwraca open()?
open() zwraca deskryptor czyli identyfikator  pliku. Jest to liczba uzywana w kolejnych wywolaniach
systemowych zeby odwolac sie do otwartego pliku.


6. Jaka wartosc zwraca read() i write()?
read() zwraca liczbe odczytanych bajtow lub -1 w przypadku bledu.
write() zwraca liczbe zapisanych bajtow lub -1 w przypadku bledu.
