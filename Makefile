CC=gcc
CFLAGS=-ansi -pedantic -Wall -Og -g

all: bf clean

bf: control.o cells.o parse.o
	$(CC) control.o cells.o parse.o $(CLFAGS) -o bf

control.o: control.c

cells.o: cells.c

parse.o: parse.c

clean:
	-rm *.o