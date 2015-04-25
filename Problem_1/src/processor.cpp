// File processor.cpp

/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 03/17/2015                                             *
	Assignment: Homework 2 - Program 3                           *
	Purpose: To simulate process generation                      *
             Processors are all identical in this case           * 
*****************************************************************/

#include "processor.h"

processor::processor(int x, int y, int z){
	for(int i=0;i<SIZE;i++)
		jobArray[i] = new c_Proc();
	speed   = x*pow(10,9);
	mem     = y;
	procNum = z;
	jobTime = 0;
	jobNum  = 0;
	finished = false;
}

signed long long int processor::procSpeed(){
	return speed;
}

int processor::memAmount(){
	return mem;
}

int processor::cycles(){
	return jobTime;
}

int processor::pNum(){
	return procNum;
}

bool processor::flagCheck(){
	return finished;
}

void processor::raiseFlag(){
	finished = true;
}

void processor::freeCPU(){
	finished = false;
}

/** @brief           Figures out how many cycles to complete job 
*
*   @details         Adds how many cycles it'll take to jobTime
*
*   @param GHZ       Processor speed in GHz 
*   @param EXP       Exponent for cycle time (2GHz = 2*10^9 cycles/second)
*/
void processor::calcCycles(int GHZ, int EXP){
	jobTime += ( jobArray[jobNum-1]->timeCalc(GHZ,EXP) );
}

/** @brief           Displays processor job info
*
*   @details         Displays how many jobs, how many cycles,
*                    and the PID of the jobs each processor complete
*/
void processor::displayOutput(){
	cout<<"Processor "<<procNum<<endl;
	cout<<"Average Wait Time:"<<jobTime/jobNum<<endl;
	cout<<"Total Run Time:"<<jobTime<<endl;
	cout<<"Job Count:"<<jobNum<<"\n"<<endl;
	
	/*
	cout<<"The jobs completed are as follows:"<<endl;
	for(int i=0;i<jobNum;i++){
		if((i+1)==jobNum)
			cout<<jobArray[i]->showPid()<<endl;
		else
			cout<<jobArray[i]->showPid()<<", ";
		if( (i+1)%20 == 0)
			cout<<endl;
	}	
	*/
}

/** @brief           Outputs processor job info to a text file
*
*   @details         Sends output to processorInfo.txt to verify manually
*/
void processor::fileOutput(){
	fp<<"Processor "<<procNum<<endl;
	fp<<"Average Wait Time:"<<jobTime/jobNum<<endl;
	fp<<"Total Run Time:"<<jobTime<<endl;
	fp<<"Job Count:"<<jobNum<<endl;
	
	fp<<"The jobs completed are as follows:"<<endl;
	for(int i=0;i<jobNum;i++){
		if((i+1)==jobNum)
			fp<<jobArray[i]->showPid()<<endl;
		else
			fp<<jobArray[i]->showPid()<<", ";
		if( (i+1)%20 == 0 )
			fp<<endl;
	}	
	
	fp<<endl;
}

/** @brief           Gives processor a job
*
*   @details         Sets an processor array entry equal to the job
*                    assigned to the processor
*/
void processor::getJob(c_Proc* job){
	jobArray[jobNum]=job;
	jobNum++;
}