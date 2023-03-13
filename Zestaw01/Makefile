CC	:= gcc
CFLAGS	:= -Wall -O3
LDFLAGS	:= -s -lm
LDLIBS	:=

.PHONY: all clean

all: main.x kopiuj.x procesy.x lider.x

main.x: main.o procinfo.o
kopiuj.x: kopiuj.o	
procesy.x: procesy.o procinfo.o
lider.x: lider.o procinfo.o	

%.x: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.o *.x
	
