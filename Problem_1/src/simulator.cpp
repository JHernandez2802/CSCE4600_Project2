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
 *  @details         Runs through job array and adds processes 
 *                   memory consumption to the memory array.
 *                   A while loops are used to simulate processor
 *                   cycles in order to get the next job and to run
 *                   the processes.
 *
 *  @param jobs      Array of processes (jobs)
 *  @param totalJobs Total amount of processes (jobs)
 *  @param numProc   How many processors to make
 */
bool simulator(c_Proc **jobs, int totalJobs, int numProc, float &memCount){
	//Variables
	int jobsIterator = 0;
	int memIterator = 0;
	int cycle=0;
	int minCycle;
	int procJobArray[numProc][0];
	int minProcessor;
	
	//Creates processors
 	processor *procs[numProc];
	
	//Create memory array - each bucket will contain a job
	char* memArray = (char*) malloc(sizeof(char)*totalJobs);
	
	//Creates the array of processors
	for(int i=0;i<numProc;i++)
		procs[i] = new processor(GHZ, MEM_AMOUNT,i+1);


	//Runs until the last job has been ran or we run out of memory
 	while(jobsIterator<totalJobs){
		//Gives a job processors
		for(int i = 0; i < numProc; i++){
			if( (procs[i]->flagCheck() ) == false ){
				//Sets processor to busy
				procs[i]->raiseFlag();
				
				//Adds memory count to see if we're out of memory or not 
				memCount+=jobs[jobsIterator]->mem();
				if(memCount/(1000000) > 10)
					return false;
				
				//jobs[jobsIterator]->getMem();
				
				//Adds job to the memory array
				memArray[i]=jobs[jobsIterator]->mem();
				
				//Figures out which processor has which job
				procJobArray[i][0]=jobsIterator;
				
				//Increases jobsIterator
				jobsIterator++;

				//Error checker
				if(jobsIterator >= totalJobs)
					break;
			}//end if

		}//end for
		
		//Simulates 50 cycles of running
		//jobProgress removes 50 cycles of work from the job time
		//freeCPU also frees up the memory that that process is using
		for(int i = 0; i < numProc; i++){
			if(procs[i]->jobProgress()){
				procs[i]->freeCPU();
				//jobs[procJobArray[i][0]]->freeMem();
			}
		}
		
	}//end while
	
	//Frees memory
	free(memArray);
	return true;
}

