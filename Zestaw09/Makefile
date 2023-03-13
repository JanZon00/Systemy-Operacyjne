CC	:= gcc
CFLAGS	:= -std=c99 -Wall -pthread
LDFLAGS	:= -pthread
LDLIBS	:=

.PHONY: all clean

all: wykluczanie.x

wykluczanie.x: wykluczanie.o

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.o *.x
	
