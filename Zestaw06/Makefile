CC	:= gcc
CFLAGS	:= -pthread -Wall -std=c99 -pedantic
LDFLAGS	:= -s -lm -pthread
LDLIBS	:= -L. -lsem -lrt

.PHONY: all clean

all: libsem.a sem.o semuse.x prog.x powielacz.x

sem.o: sem.c
	$(CC) $(CFLAGS) -c sem.c

libsem.a: sem.o
	ar rv libsem.a sem.o	

semuse.x: semuse.o libsem.a
	$(CC) $(CFLAGS) -pthread -L. semuse.c -o semuse.x -lrt -lsem
	
prog.x: prog.o libsem.a

powielacz.x: powielacz.o libsem.a


%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)
lib%.a: %.o
	ar rv $@ $^	

clean:
	$(RM) *.o *.x *.a
	
