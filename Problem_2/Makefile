CC=g++
CFLAGS=-std=c++0x -g -Iinclude -Wall
BIN=bin
INC=include
SRC=src
OUT=scheduler

all: main memory processes processor scheduler
	$(CC) $(CFLAGS) $(BIN)/memory.o $(BIN)/main.o $(BIN)/processes.o $(BIN)/processor.o $(BIN)/scheduler.o -o $(OUT)

clean:
	@rm -rf $(BIN)
	@rm -rf $(OUT)
	@rm -rf processes.txt
	@rm -rf processors.txt
	@rm -rf nextJob.txt

init:
	@mkdir -p $(BIN)

memory: init
	$(CC) -c $(CFLAGS) $(SRC)/memory.cpp -o $(BIN)/memory.o

processes: init
	$(CC) -c $(CFLAGS) $(SRC)/processes.cpp -o $(BIN)/processes.o

processor: init
	$(CC) -c $(CFLAGS) $(SRC)/processor.cpp -o $(BIN)/processor.o

scheduler: init
	$(CC) -c $(CFLAGS) $(SRC)/scheduler.cpp -o $(BIN)/scheduler.o
	
main: init
	$(CC) -c $(CFLAGS) $(SRC)/main.cpp -o $(BIN)/main.o


