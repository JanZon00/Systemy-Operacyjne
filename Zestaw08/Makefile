CC	:= gcc
CFLAGS	:= -pthread -Wall -std=c99 -pedantic
LDFLAGS	:= -s -pthread
LDLIBS	:= -L. -lmsg -lrt

.PHONY: all clean

all: libmsg.a libmsg.so msg.o serwer.x klient.x

libmsg.a: msg.o
	ar rv libmsg.a msg.o

msg.o: msg.c
	$(CC) -c -O -fPIC msg.c

libmsg.so: msg.o
	$(CC) -shared -o libmsg.so msg.o

serwer.x: serwer.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS) -lmsg

klient.x: klient.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS) -lmsg

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)
lib%.a: %.o
	ar rv $@ $^

clean:
	$(RM) *.o *.x *.a *.so
	
