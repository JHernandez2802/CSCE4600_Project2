CC=g++
CFLAGS=-std=c++0x -Iinclude -Wall
BIN=bin
INC=include
SRC=src
OUT=MemoryTest

all: main memory processes processor execution_loop
	$(CC) $(CFLAGS) $(BIN)/Memory.o $(BIN)/Main.o $(BIN)/Processes.o $(BIN)/Processor.o $(BIN)/ExecutionLoop.o -o $(OUT)

malloc: main_mal processes processor_mal execution_loop_mal
	$(CC) $(CFLAGS) $(BIN)/MainMal.o $(BIN)/Processes.o $(BIN)/ProcessorMal.o $(BIN)/ExecutionLoopMal.o -o $(OUT)

clean:
	@rm -rf $(BIN)
	@rm -rf $(OUT)
	@rm -rf processes.txt
	@rm -rf processors.txt
	@rm -rf nextJob.txt

init:
	@mkdir -p $(BIN)

memory: init
	$(CC) -c $(CFLAGS) $(SRC)/Memory.cpp -o $(BIN)/Memory.o

processes: init
	$(CC) -c $(CFLAGS) $(SRC)/Processes.cpp -o $(BIN)/Processes.o

processor: init
	$(CC) -c $(CFLAGS) $(SRC)/Processor.cpp -o $(BIN)/Processor.o

execution_loop: init
	$(CC) -c $(CFLAGS) $(SRC)/ExecutionLoop.cpp -o $(BIN)/ExecutionLoop.o
	
main: init
	$(CC) -c $(CFLAGS) $(SRC)/Main.cpp -o $(BIN)/Main.o

processor_mal: init
	$(CC) -c $(CFLAGS) $(SRC)/ProcessorMal.cpp -o $(BIN)/ProcessorMal.o

execution_loop_mal: init
	$(CC) -c $(CFLAGS) $(SRC)/ExecutionLoopMal.cpp -o $(BIN)/ExecutionLoopMal.o
	
main_mal: init
	$(CC) -c $(CFLAGS) $(SRC)/MainMal.cpp -o $(BIN)/MainMal.o

