// File scheduler.cpp

/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 04/27/2015                                             *
	Assignment: Project 2                                        *
	Purpose: To  simulate of different scheduling disciplines to *
             allocate set of processes to available processors   *
*****************************************************************/

#include "processes.h"
#include "processor.h"
#define K (1024)

static const int GHZ = 2;
static const int EXP = 9;
static const int MEM_AMOUNT = 8;
static const int TIME_INTERVAL = 1;
static int MAX_INT = ~0;
static int MAX_BLOCK_SIZE = 1024*1024*10;


//processor *procs[5];

/** @brief           Writes processor info to procs.txt
 *
 *  @details         Writes the processor info after displaying
 *                   the info to the user
 *
 *  @param procs[]   An array of all the processors
 */
void processorOutput(processor **procs, int procNum){
	//Clears the processors.txt file just in case
	//"make clean" has not been run
	procs[0]->fp.open("processors.txt");
	procs[0]->fileOutput();

	//Displays output to user and writes to processors.txt as well
	for(int i=0;i<procNum;i++){
		// procs[i]->displayOutput();
		// procs[i]->fp.open("processors.txt",ios::app);// the output file
		// procs[i]->fileOutput();
		// procs[i]->fp.close();
	}
	procs[0]->fp.close();
}

/** @brief           Process Execution Simulator
 *
 *  @details         Calculates each how many cycles it takes for
 *                   for a job to complete and adds it to a 
 *                   cycle counter then allocates the job memory.
 *                   Then a whileloop is used as a processesor 
 *                   cycle simulator. After the job is complete, it
 *                   deallocates the memory and the cycle counter is
*                    decremented by the job cycle number. 
 *
 *  @param jobs      Array of processes (jobs)
 *  @param totalJobs Total amount of processes (jobs)
 */
void simulator(c_Proc **jobs, int totalJobs, int numProc){
	//Variables
	int jobsIterator = 0;
	int cycle=0;
	int cycleCount[numProc];
	int memArray[numProc];
	
 	processor *procs[numProc];
	//Creates the array of processors and cycleCounts
	for(int i=0;i<numProc;i++)
		procs[i] = new processor(GHZ, MEM_AMOUNT,i+1);

	//Runs until the last job has been ran
	while(jobsIterator<totalJobs){
		//Gives a job processors
		for(int i = 0; i < numProc; i++){
			//Calculates how long it will take processor to run job
			cycleCount[i] = jobs[jobsIterator]->timeCalc(GHZ,EXP);
			cycle+=cycleCount[i];
			
			//Memory array for later deallocation
			memArray[i]=jobs[jobsIterator]->mem();
			
			//Whileloop simulates processor cycle
			//If if hasn't been 50 cycles yet, wait
			while(cycle<50)
				cycle++;
				
			//Increases jobsIterator
			jobsIterator++;
			
			//Error checker
			if(jobsIterator >= totalJobs)
				break;
			
		}//end for

		//Goes through the cycleCount array
		for(int i=0; i<numProc; i++){
			//Allocates memory
			int* memory = (int*) malloc(memArray[i]);
			
			//Each turn in the while loop 
			//simulates a processor cycle
			while(cycleCount[i]!=0){
				cycleCount[i]--;
				cycle--;
			}

			//deallocates the memory
			free(memory);
		
		}//end for

	}//end while

	return;
}

