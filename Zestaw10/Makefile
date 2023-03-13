CC	:= gcc
CFLAGS	:= -std=c99 -Wall -pthread
LDFLAGS	:= -pthread
LDLIBS	:=

.PHONY: all clean

all: piekarnia1.x piekarnia2.x
	
piekarnia1.x: piekarnia1.o
piekarnia2.x: piekarnia2.o

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.o *.x
	
