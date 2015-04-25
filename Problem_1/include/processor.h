// File processor.h

/*****************************************************************
	Programmer: Juan Hernandez, Matthew Sherwood                 *
	Class: CSCE 4600                                             *
	Date: 03/17/2015                                             *
	Assignment: Project 1                                        *
	Purpose: To create and test a scheduler					 	 *
*****************************************************************/
#ifndef PROCESSOR
#define PROCESSOR

using namespace std;

#include <iostream>
#include <random>
#include "processes.h"

static const int SIZE = 99;

class processor{
	private: //Private variables
		c_Proc* jobArray[SIZE];
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
		void calcCycles(int GHZ, int EXP);
		void getJob(c_Proc* job);
		void raiseFlag();
		void freeCPU();
}; //end class declaration
#endif
