CC=g++
CFLAGS=-std=c++0x -g -Iinclude
BIN=bin
INC=include
SRC=src
OUT=scheduler

all: main pgen proc sche
	$(CC) $(CFLAGS) $(BIN)/main.o $(BIN)/processes.o $(BIN)/processor.o $(BIN)/sche.o -o $(OUT)

clean:
	@rm -rf $(BIN)
	@rm -rf $(OUT)
	@rm -rf processes.txt
	@rm -rf processors.txt

init:
	@mkdir -p $(BIN)

pgen: init
	$(CC) -c $(CFLAGS) $(SRC)/processes.cpp -o $(BIN)/processes.o

proc: init
	$(CC) -c $(CFLAGS) $(SRC)/processor.cpp -o $(BIN)/processor.o

sche: init
	$(CC) -c $(CFLAGS) $(SRC)/scheduler.cpp -o $(BIN)/sche.o
	
main: init
	$(CC) -c $(CFLAGS) $(SRC)/main.cpp -o $(BIN)/main.o


