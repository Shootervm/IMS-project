# IMS project 2015 - 07 Menza
# authors: xmalin26 & xmasek15

CC=g++
CFLAGS=-g -O2 -Wall -std=c++11
LDFLAGS=-lsimlib -lm
SOURCES=main.cpp customer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=project

all:
	$(CC) $(CFLAGS) $(LDFLAGS) customer.cpp data.cpp generator.cpp main.cpp -o $(EXECUTABLE)
	$(CC) $(CFLAGS) -DE_PEAK $(LDFLAGS) customer.cpp data.cpp generator.cpp main.cpp -o $(EXECUTABLE)_peak
	$(CC) $(CFLAGS) -DE_OPENING $(LDFLAGS) customer.cpp data.cpp generator.cpp main.cpp -o $(EXECUTABLE)_opening
	$(CC) $(CFLAGS) -DE_CLOSING $(LDFLAGS) customer.cpp data.cpp generator.cpp main.cpp -o $(EXECUTABLE)_closing
	$(CC) $(CFLAGS) -DE_NORMAL $(LDFLAGS) customer.cpp data.cpp generator.cpp main.cpp -o $(EXECUTABLE)_normal

run:
	@echo "Running experiments"
	@rm -rf ./experiments
	@mkdir experiments 2>/dev/null
	./$(EXECUTABLE) > ./experiments/typical.output
	./$(EXECUTABLE)_opening > ./experiments/opening.output
	./$(EXECUTABLE)_normal > ./experiments/normal.output
	./$(EXECUTABLE)_peak > ./experiments/peak.output
	./$(EXECUTABLE)_closing > ./experiments/closing.output

clean:
	@rm -rf $(EXECUTABLE)* *.o* ./experiments
