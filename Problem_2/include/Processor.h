/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 05/01/2015                                             *
	Assignment: Project 2                                        *
	Purpose: Implement in-house version of malloc and free       *
*****************************************************************/
#ifndef PROCESSOR_H
#define PROCESSOR_H
//----
#include "Processes.h"
//----
static const int SIZE = 99;


class
processor {
    private:
        fakeJobs* job_array[SIZE];
        unsigned char* mem_pointer;
        bool finished;
        int job_time;
        int proc_num;
        int job_num;

    public:
        std::ofstream file;

        processor(int);                                                         //----Constructor, accessors, and output
        int Cycles();
        int PNum();
        bool CPUBusy();
        int JobProgress();
        bool CheckMem();
        void DisplayOutput();
        void FileOutput();

        void CalcCycles(int);                                                   //----Mutators
        void GetMem(void*);
        void GetJob(fakeJobs*);
        void ClaimCPU();
        void FreeCPU();
};
#endif
