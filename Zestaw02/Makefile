CC	:= gcc
CFLAGS	:= -Wall -O3
LDFLAGS	:= -s -lm
LDLIBS	:=

.PHONY: all clean

all: drzewko1.x drzewko2.x potomny.x macierzysty.x zombi.x orphan.x execute.x

kopiuj.x: kopiuj.o
drzewko1.x: drzewko1.o procinfo.o
drzewko2.x: drzewko2.o procinfo.o
potomny.x: potomny.o procinfo.o	
macierzysty.x: macierzysty.o procinfo.o	
zombi.x: zombi.o procinfo.o
orphan.x: orphan.o procinfo.o
execute.x: execute.o procinfo.o	

%.x: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.o *.x
	
