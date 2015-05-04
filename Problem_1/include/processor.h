// File processor.h

/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 04/27/2015                                             *
	Assignment: Project 2                                        *
	Purpose: To  simulate of different scheduling disciplines to *
             allocate set of processes to available processors   *
*****************************************************************/

#ifndef PROCESSOR
#define PROCESSOR

using namespace std;

#include <iostream>
#include <random>
#include "processes.h"

static const int SIZE = 50;

class processor{
	private: //Private variables
		signed long long int speed;
		bool finished;
		int jobTime;
		int procNum;
		int jobNum;
		int mem;
	public: //Output file components
		ofstream fp;
	public: //Constructor, accessors, and output
		processor(int, int, int);
		signed long long int procSpeed();
		int memAmount();
		int cycles();
		int pNum();
		bool flagCheck();
		void displayOutput();
		void fileOutput();
	public: //mutators
		void calcCycles(int GHZ, int EXP, c_Proc* job);
		void getJob(c_Proc* job);
		void raiseFlag();
		void freeCPU();
}; //end class declaration
#endif
