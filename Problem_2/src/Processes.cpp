/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 05/01/2015                                             *
	Assignment: Project 2                                        *
	Purpose: Implement in-house version of malloc and free       *
*****************************************************************/
#include <iostream>
#include "Processes.h"
//----
using namespace std;


fakeJobs::fakeJobs() {

    cpu_cycles = 0;
    pid_num = 0;
    mem_size = 0;
    job_time = 0;
}


fakeJobs::fakeJobs(int x) {

	pid_num = x + 1;
	CpuCreation();
	MemCreation();	
}


void
fakeJobs::ProcOutput() {

	cout << "PID number: " << pid_num << endl;
	cout << "CPU cycles: " << cpu_cycles << endl;
	cout << "Memory size: " << mem_size << "Kb" << endl;

    return;
}


void
fakeJobs::FileOutput() {

	file << endl;
	file << "PID number: " << pid_num << endl;
	file << "CPU cycles: " << cpu_cycles << endl;
	file << "Memory size: " << mem_size << "Kb" << endl;

    return;
}


void
fakeJobs::CpuCreation() {
    mt19937 gen(rd());                                                          //----Mersenne Twister 19937 generator
    uniform_int_distribution<int> cycle_dist(10, 75);                           //----Produces and sets CPU cycle base from 10-50


    cpu_cycles = cycle_dist(rd);
    while(cpu_cycles < 10 || cpu_cycles > 75) {                                 //----Error checking to make sure our base values
        cpu_cycles = cycle_dist(rd);                                            //    stay within the pre-determined range
    }

    return;
}


void
fakeJobs::MemCreation() {
    mt19937 gen(rd());                                                          //----Mersenne Twister 19937 generator
    normal_distribution<> distribution(1000, 1000);                             //----Produces according to a normal distribution
                                                                                //    with a mean of 1000(1Kb) and a deviation
                                                                                //    of 1000
	mem_size=distribution(rd);
    while(mem_size <= 1 || mem_size > 2000) {                                   //----Error checking to make sure our values stay
		mem_size = distribution(rd);                                            //    within the pre-determined range
    }

    return;
}


int
fakeJobs::Mem() {
	return mem_size;
}


int
fakeJobs::Cpu() {
	return cpu_cycles;
}


int
fakeJobs::ShowPid() {
	return pid_num;
}


int
fakeJobs::ShowJob() {
    return job_time;
}


int
fakeJobs::TimeCalc(int time_interval) {
    int negative_diff = 0;

    job_time -= time_interval;
    if(job_time < 0) {                                                          //----Calculates cycles needed to complete job
        negative_diff -= job_time;
		job_time = JOB_DONE;

        return negative_diff;
    }

    return job_time;
}
