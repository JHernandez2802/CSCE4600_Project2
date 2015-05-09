// File processes.cpp

/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 04/27/2015                                             *
	Assignment: Project 2                                        *
	Purpose: To  simulate of different scheduling disciplines to *
             allocate set of processes to available processors   *
*****************************************************************/

#include "processes.h"

c_Proc::c_Proc(){
	pidNum = 0;
	run = false;
}

c_Proc::c_Proc(int x){
	pidNum=x+1;
	cyclesCreation();
	memCreation();
	run=false;
}

void c_Proc::jobOutput(){
	cout<<"PID number:"<<pidNum<<endl;
	cout<<"CPU cycles:"<<cpuCycles<<endl;
	cout<<"Scientific notation:"<<base<<"x10^"<<exponent<<endl;
	cout<<"Memory size:"<<memSize<<"Bytes"<<endl;
}

void c_Proc::fileOutput(){
	f<<endl;
	f<<"PID number:"<<pidNum<<endl;
	f<<"CPU cycles:"<<cpuCycles<<endl;
	f<<"Scientific notation:"<<base<<"x10^"<<exponent<<endl;
	//f<<"Job time:"<<jobTime<<endl;
	f<<"Memory size:"<<memSize<<"Bytes"<<endl;
}

void c_Proc::memCreation(){
	//Mersenne Twister 19937 generator
	mt19937 gen(rd());

	//Produces according to a normal distribution
	//with a mean of 125000 bytes and a deviation of 50000
	normal_distribution<> distribution(125000,50000);
	memSize=distribution(rd);

	//Error checking to make sure our values stay
	//within the pre-determined range
	while(memSize<=1 || memSize >200000)
		memSize=distribution(rd);
	
	memory = (char*) malloc(memSize);
}

void c_Proc::cyclesCreation(){
	//Mersenne Twister 19937 generator
	mt19937 gen(rd());

	//Produces and sets CPU cycle base from 10-50
	uniform_int_distribution<int> distribution(10,50);
	cpuCycles=distribution(rd);

	//Error checking to make sure our base values
	//stay within the pre-determined range
	while(base<10 || base>50)
		base=distribution(rd);

	//Produces and sets CPU cycle exponent from 6 to 12
	uniform_int_distribution<int> eDistribution(6,12);
	exponent=eDistribution(rd);

	//Error checking to make sure our values stay
	//within the pre-determined range
	while(exponent<6 || exponent>12)
		exponent=eDistribution(rd);

	cpuCycles=base*pow(10,exponent);
}

int c_Proc::mem(){
	return memSize;
}

int c_Proc::cpu(){
	return cpuCycles;
}

int c_Proc::pid(){
	return pidNum;
}

void c_Proc::getMem(){
	memory = (char*) malloc(memSize);
}

char* c_Proc::showMem(){
	return memory;
}

void c_Proc::freeMem(){
	free(memory);
}

/** @brief           Calculates how many cycles to complete this job
*
*   @details         Uses the processor speed in GHz in order to calculate
*                    how many cycles to take. Calculates by dividing the
*                    job cycle time by the processor speed. The exponents
*                    are subtracted to know which power to raise 10 to and
*                    the bases are subtracted to know what to multiply by.
*                    If the processor exponent is greater than the process
*                    exponent, it will only take 1 cycle to finish the job.
*
*   @param GHZ       Processor speed in GHz
*   @param EXP       Exponent for cycle time (2GHz = 2*10^9 cycles/second)
*/
int c_Proc::timeCalc(int GHZ, int EXP){
	//Variables used in cycle calculation
	int mul = exponent-EXP;
	double div = base/GHZ;

	//Calculates how many cycles it takes to complete
	if(EXP > exponent)
		return jobTime=1;
	else
	if(EXP == exponent)
		return jobTime=div;
	else
		return jobTime=div*pow(10,mul);
}

bool c_Proc::hasRan(){
	return run;
}

void c_Proc::ran(){
	run=true;
}
