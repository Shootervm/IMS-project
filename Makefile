
CC=g++
CFLAGS=-g -O2 -Wall -std=c++11
LDFLAGS=-lsimlib -lm
SOURCES=main.cpp customer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=project

all:
	$(CC) $(CFLAGS) $(LDFLAGS) customer.cpp simulation.cpp main.cpp -o $(EXECUTABLE)

run:
	echo "TODO: run simulations"

clean:
	rm -f project *.o*

