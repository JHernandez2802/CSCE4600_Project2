// File processes.h

/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 03/17/2015                                             *
	Assignment: Homework 2 - Program 3                           *
	Purpose: To simulate process generation                      *
             Processors are all identical in this case           * 
*****************************************************************/

#ifndef PROCGEN
#define PROCGEN

using namespace std;

#include <iostream>
#include <fstream>
#include <random>

class c_Proc{
	private: //Private variables and functions
		random_device rd;
		signed long long int cpuCycles;
		int pidNum;
		int memSize;
		int jobTime;
		bool run;
		void cpuCreation();
		void memCreation();
	public: //Output file components and display
		ofstream f;
		void fileOutput();
		void procOutput();
	public: //Constructors and accessors
		c_Proc(int x); //constructor
		c_Proc();
		int base;
		int exponent;
		int mem();
		int cpu();
		int showPid();
	public: //mutators and others
		int timeCalc(int GHZ, int EXP);
		bool hasRan();
		void ran();
}; //end class declaration
#endif
