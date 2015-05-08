// File processes.h

/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 04/27/2015                                             *
	Assignment: Project 2                                        *
	Purpose: To  simulate of different scheduling disciplines to *
             allocate set of processes to available processors   *
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
		int memSize; //in bytes
		int jobTime;
		char* memory;
		bool run;
		void cyclesCreation();
		void memCreation();
	public: //Output file components and display
		ofstream f;
		void fileOutput();
		void jobOutput();
	public: //Constructors and accessors
		c_Proc(int x); //constructor
		c_Proc();
		int base;
		int exponent;
		int mem();
		int cpu();
		int pid();
		void getMem();
		char* showMem();
		void freeMem();
	public: //mutators and others
		int timeCalc(int GHZ, int EXP);
		bool hasRan();
		void ran();
}; //end class declaration
#endif
