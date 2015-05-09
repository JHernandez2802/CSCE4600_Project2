/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 05/01/2015                                             *
	Assignment: Project 2                                        *
	Purpose: Implement in-house version of malloc and free       *
*****************************************************************/
#ifndef PROCGEN_H
#define PROCGEN_H
//----
#include <random>
#include <fstream>
//----
static const int JOB_DONE = -1;


class
fakeJobs {
    private:
        std::random_device rd;
        int cpu_cycles;
        int pid_num;
        int mem_size;
        int job_time;

        void CpuCreation();
        void MemCreation();

    public:
        std::ofstream file;

        fakeJobs();
        fakeJobs(int);                                                          //----Constructors, accessors, and output
        int Mem();
        int Cpu();
        int ShowPid();
        int ShowJob();
        void FileOutput();
        void ProcOutput();

        int TimeCalc(int);                                                      //----Mutators and others
};

#endif
