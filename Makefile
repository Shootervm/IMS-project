CFLAGS=-g -O2 -Wall -std=c++11
PFLAGS=-lsimlib -lm

CC = g++

all: project

project: main.cpp
	$(CC) $(CFLAGS) -o $@ main.cpp $(PFLAGS)

run:
	echo "TODO: run simulations"

clean:
	rm -f main *.out
