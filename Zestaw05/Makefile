CC	:= gcc
CFLAGS	:= -Wall -std=c99 -pedantic
LDFLAGS	:= -s -lm 
LDLIBS	:=

.PHONY: all clean

all: producent.x konsument.x fifo.x

producent.x: producent.o
konsument.x: konsument.o
fifo.x: fifo.o	


%.x: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.o *.x
	
