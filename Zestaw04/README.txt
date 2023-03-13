===========================================================================
Autor : Jan Zon					Ostatnia zmiana: 03.05.2021
===========================================================================
Zawartosc:
=========

Katalog Zestaw04 zawiera 5 plikow:
---------------------------------------------------------------------------

I. magazynt.txt, schowek.txt - pliki tekstowe wykorzystywane w programie glownym

II. plik Makefile do kompliacji programu

III. plik tekstowy README

IV. plik prodkons.c zawierajacy program napisany w jezyku c. Program sluzacy 
zademonstrowaniu dzialania potokow nienazwanych. Program pobiera z linii wywolania
2 argumenty. Plik zawierajacy tekst oraz plik do ktorego owy tekst zostanie przeslany
przy uzyciu potoku nienazwanego. W przypadku blednej liczby argumentow program
informuje nas o bledzie. Program sklada sie z trzech funkcji. Funkcji glownej main
oraz dwoch funkcji : producent ktora pobiera bajty z pliku tekstowego magazyn.txt,
nastepnie umieszcza je w potoku oraz konsument ktora pobiera dane z potoku i przesyla
je do pliku schowek.txt. W funkcji main przy uzyciu funkcji fork tworzymy proces potomny
procesu macierzystego. Nastepnie w procesie macierzystym wywolujemy funkcje producent
a w procesie potomnym funkcje konsument. Na koncu znajduje sie funkcja wait ktora powoduje
ze proces macierzysty czeka na proces potomny oraz zamkniete zostaja deskryptory plikow.

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
