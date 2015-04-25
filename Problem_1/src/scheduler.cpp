// File scheduler.cpp

/*****************************************************************
	Programmer: Matthew Sherwood                 				 *
	Class: CSCE 4600                                             *
	Date: 03/17/2015                                             *
	Assignment: Project 1                                        *
	Purpose: To create and test a scheduler					 	 *
*****************************************************************/
#include "processes.h"
#include "processor.h"

static const int GHZ = 2;
static const int EXP = 9;
static const int MEM_AMOUNT = 8;
static const int TIME_INTERVAL = 1;
static int MAX_INT = ~0;

processor *procs[5];

/** @brief           Writes processor info to procs.txt
 *
 *  @details         Writes the processor info after displaying
 *                   the info to the user
 *
 *  @param procs[]   An array of all the processors
 */
void processorOutput(){
	//Clears the processors.txt file just in case
	//"make clean" has not been run 
	procs[0]->fp.open("processors.txt");
	procs[0]->fileOutput();
	
	//Displays output to user and writes to processors.txt as well
	for(int i=0;i<5;i++){
		procs[i]->displayOutput();
		procs[i]->fp.open("processors.txt",ios::app);// the output file 
		procs[i]->fileOutput();
		procs[i]->fp.close();
	}
}

/** @brief           SJF Scheduler Implementation
 *
 *  @details         Checks each processor to see if it's free
 *                   or not fist then assigns a job if it's free.
 *                   It then runs 1 cycle on each processor and
 *                   repeats the process. 
 *
 *  @param jobs      Array of processes (jobs)
 *  @param totalJobs Total ammount of processess (jobs)
 */
void schedulerLoop(c_Proc **jobs, int totalJobs){
	//Iterators for jobs and processors 
	int jobsIterator = 0;
	int procIterator = 0;
	int minProcessor = 0;

	//Creates the array of 5 processors
	for(; procIterator < 5; procIterator++){
		procs[procIterator] = new processor(GHZ, MEM_AMOUNT,procIterator+1);
	}
	
	//Stream class for file writing
	ofstream f;
	//Clears the file just in case "make clean" has not been run
	f.open("nextJob.txt");
	f<<" "<<endl;
	f.close();
	//Opens file with append flag
	f.open("nextJob.txt",ios::app);// the output file 
	
	//Runs until the last job has been ran
	while(jobsIterator<totalJobs){
		//Gives a job to free processor
		for(procIterator = 0; procIterator < 5; procIterator++){
			if( (procs[procIterator]->flagCheck() ) == false ){
				//Sets processor to busy
				procs[procIterator]->raiseFlag();
				//Gives processor next job in the list
				procs[procIterator]->getJob(jobs[jobsIterator]);
				//Increases jobsIterator to go through jobs array
				jobsIterator++;
			}//end if
		}//end for
		
		//Figures out how many cycles it takes each processor to finish the job
		//figures out which processor has the least amount of cycles completed
		for(procIterator = 0; procIterator < 5; procIterator++){
			//Calculates how many cycles it takes to complete the job assigned
			procs[procIterator]->calcCycles(GHZ,EXP);
			//Base case
			if(procIterator==0)
				minProcessor=0;
			else
			//If they're the same, the lower processor number wins
			if(procs[procIterator]->cycles() == procs[minProcessor]->cycles() )
				minProcessor=minProcessor;
			else
			//If the next processor has a smaller cycle time, it wins
			if(procs[procIterator]->cycles() < procs[minProcessor]->cycles() )
				minProcessor=procIterator;
		}
		
		//File output
		for(int i = 0; i < 5; i++){
			f<<"Processor "<<procs[i]->pNum()<<" current ";
			f<<"runtime:"<<procs[i]->cycles()<<endl;
		}
		if(jobsIterator!=totalJobs){
			f<<"Next processor that is free is ";
			f<<procs[minProcessor]->pNum()<<endl;
			f<<"The next job to be scheduled is ";
			f<<jobs[jobsIterator]->showPid()<<"\n"<<endl;
		}
		else
			f<<"All processes are complete"<<endl;
		
		//Frees up the processor with the least amount of cycles completed
		procs[minProcessor]->freeCPU();
		
	//Goes through the loop again
	}//end while

	f.close(); //closes output file;
	return;
}

