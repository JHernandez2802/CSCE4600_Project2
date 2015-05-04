CC=g++
CFLAGS=-std=c++0x -g -Iinclude
BIN=bin
INC=include
SRC=src
OUT=simulator

all: main pgen proc sim
	$(CC) $(CFLAGS) $(BIN)/main.o $(BIN)/processes.o $(BIN)/processor.o $(BIN)/sim.o -o $(OUT)

clean:
	@rm -rf $(BIN)
	@rm -rf $(OUT)
	@rm -rf *.txt

init:
	@mkdir -p $(BIN)

pgen: init
	$(CC) -c $(CFLAGS) $(SRC)/processes.cpp -o $(BIN)/processes.o

proc: init
	$(CC) -c $(CFLAGS) $(SRC)/processor.cpp -o $(BIN)/processor.o

sim: init
	$(CC) -c $(CFLAGS) $(SRC)/simulator.cpp -o $(BIN)/sim.o
	
main: init
	$(CC) -c $(CFLAGS) $(SRC)/main.cpp -o $(BIN)/main.o


