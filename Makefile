CFLAGS=-g -O2 -Wall
PFLAGS=-lsimlib -lm

CC = g++

all: project

project: main.cpp
	$(CC) $(CFLAGS) -o $@ main.cpp $(PFLAGS)

run:
	echo "TODO: run simulations"

clean:
	rm -f main *.out
