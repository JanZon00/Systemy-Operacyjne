CC	:= gcc
CFLAGS	:= -Wall -std=c99 -pedantic
LDFLAGS	:= -s -lm 
LDLIBS	:=

.PHONY: all clean

all: prodkons.x

prodkons.x: prodkons.o

%.x: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.o *.x
	
