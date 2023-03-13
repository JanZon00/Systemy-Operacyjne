CC	:= gcc
CFLAGS	:= -Wall -O3
LDFLAGS	:= -s -lm
LDLIBS	:=

.PHONY: all clean

all: obsluga.x wysylaj.x grupa.x

obsluga.x: obsluga.o
wysylaj.x: wysylaj.o
grupa.x: grupa.o

%.x: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.o *.x
	
