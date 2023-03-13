PYTANIA DO ZESTAWU:

1. Ile teraz powstaje procesow w zadaniu 2. i dlaczego?
Powstana 4 procesy. Funkcja execv() zastepuje obraz aktualnego procesu
obrazem nowego procesu. Powstanie proces macierzysty oraz 3 procesy
potomne poniewaz nasza funkcja wywoluje sie 3 razy.

2. Ile procesow powstanie przy n-krotnym wywolaniu funkcji fork-exec jak w zadaniu 2. i dlaczego?
powstanie n+1 procesow. Powstanie tyle procesow potomnych glownego procesu ile wywolan funkcji.
Kazdy z tych procesow potomnych nie wywola swoich potomnych.

3. Co robi funkcja execl()? Czym sie rozni od funkcji execv()?
Zarowno funkcja execl() jak i execv() zastepuja obraz aktualnego procesu obrazem nowego procesu.
Nie zwracaja nic przy sukcesie oraz -1 przy niepowodzeniu. Dla kazdej funkcji pierwszy argument 
wskazuje na nazwe pliku powiazana z wykonywanym plikiem. Execv przyjmuje rowniez
parametr tablicy wskaznikow. Koniec tablicy jest wskazywany przez NULL. Execl przyjmuje
liste argumentow udostepnianych wykonywanemu programowi. Lista argumentow jest zakonczona 
wskaznikiem (char*) NULL.


4. Jaka role pelni proces init lub systemd?
Adoptuje procesy sieroty nadajac im PPID = 1

5. Co to sa procesy zombi?
Procesy ktore sie zakonczyly lecz na nie nikt nie czekal. Nie zajmuja pamieci. Zajmuja jedynie
miejsce w systemowej tabeli procesow.

6. Co to sa procesy osierocone?
Procesy ktorych rodzic zakonczyl swoje dzialanie przed nimi.
