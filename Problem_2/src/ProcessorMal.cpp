/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 05/01/2015                                             *
	Assignment: Project 2                                        *
	Purpose: Implement in-house version of malloc and free       *
*****************************************************************/
#include <iostream>
#include "Processor.h"
//----
using namespace std;


processor::processor(int z) {
    int i = 0;

    for(; i < SIZE; i++) {
		job_array[i] = new fakeJobs();
    }
	proc_num = z;
	job_time = 0;
	job_num = 0;
	finished = false;
}


int
processor::Cycles() {
	return job_time;
}


int
processor::PNum() {
	return proc_num;
}


bool
processor::CPUBusy() {
	return finished;
}


int
processor::JobProgress() {
    return job_array[job_num]->ShowJob();
}

bool
processor::CheckMem() {

    if(mem_pointer) {
        return true;
    }
    return false;
}


void
processor::ClaimCPU() {
	finished = true;
    return;
}


void
processor::FreeCPU() {
    finished = false;
    free((void *)mem_pointer);
    return;
}


void
processor::CalcCycles(int time_interval) {
	job_time += (job_array[job_num]->TimeCalc(time_interval));
    return;
}


void
processor::GetMem(void *malloc_address) {
    mem_pointer = (unsigned char*)malloc_address;
    return;
}


void
processor::DisplayOutput() {

    cout << "Processor " << proc_num << endl;
    cout << "Average Wait Time: " << job_time / job_num << endl;
    cout << "Total Run Time: " << job_time << endl;
    cout << "Job Count: " << job_num << "\n" << endl;
	
    return;
}


void
processor::FileOutput() {
    int i = 0;

	file << "Processor " << proc_num << endl;
	file << "Average Wait Time: " << job_time / job_num << endl;
	file << "Total Run Time: " << job_time << endl;
	file << "Job Count: " << job_num << endl;
	
	file << "The jobs completed are as follows: " << endl;
	for(;i < job_num; i++) {

        if((i + 1) == job_num) {
			file << job_array[i]->ShowPid() << endl;
        }
        else if((i + 1) % 20 == 0) {
			file << endl;
        }
        else {
			file << job_array[i]->ShowPid() << ", ";
        }

	}	
	file<<endl;

    return;
}


void
processor::GetJob(fakeJobs* job) {

    job_num += 1;
    job_array[job_num] = job;

    return;
}
