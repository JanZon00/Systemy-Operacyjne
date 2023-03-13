CC	:= gcc
CFLAGS	:= -pthread -Wall -std=c99 -pedantic
LDFLAGS	:= -s -pthread
LDLIBS	:= -L. -lshmem -lrt

.PHONY: all clean

all: libsem.a sem.o libshmem.so shmem.o producent.x konsument.x glowny.x shmuse1.x shmuse2.x

sem.o: sem.c
	$(CC) -c sem.c

libsem.a: sem.o
	ar rv libsem.a sem.o

shmem.o: shmem.c
	$(CC) -c -O -fPIC shmem.c

libshmem.so: shmem.o
	$(CC) -shared -o libshmem.so shmem.o
	
producent.x: producent.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS) -lsem

konsument.x: konsument.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS) -lsem

glowny.x: glowny.o 
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS) -lsem

%1.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%2.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

shmuse1.x: shmuse1.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS) 

shmuse2.x: shmuse2.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS) -Wl,-rpath ./

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)
lib%.a: %.o
	ar rv $@ $^

clean:
	$(RM) *.o *.x *.a *.so
	
