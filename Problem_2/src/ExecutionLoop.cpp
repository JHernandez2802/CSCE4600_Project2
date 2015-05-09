/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 05/01/2015                                             *
	Assignment: Project 2                                        *
	Purpose: Implement in-house version of malloc and free       *
*****************************************************************/
#include <queue>
#include "Processor.h"
//----
using namespace std;
//----
static const int TIME_INTERVAL = 50;
static const int PROCESSORS = 1;
//----
extern void* MyMalloc(int);
//----
processor *procs[PROCESSORS];


void
ExecutionLoop(fakeJobs **jobs, int total_jobs) {
	auto jobs_i = 0;
	auto proc_i = 0;
    auto file_i = 0;
	ofstream schedule_file;


	for(; proc_i < PROCESSORS; proc_i += 1) {                                   //----Creates the array of 5 processors
		procs[proc_i] = new processor(proc_i);
	}
	
	schedule_file.open("nextJob.txt");                                          //----Clears the file just in case "make clean"
	schedule_file << " " << endl;                                               //    has not been run
	schedule_file.close();
	schedule_file.open("nextJob.txt", ios::app);                                //----Opens file with append flag 
	
    while(jobs_i < total_jobs) {

        for(proc_i = 0; proc_i < PROCESSORS; proc_i += 1) {                     //----Gives a job to free processor

            if(procs[proc_i]->CPUBusy() == false) {
                procs[proc_i]->GetMem(MyMalloc(jobs[jobs_i]->Mem()));           //----Checks for enough memory
                if(procs[proc_i]->CheckMem()) {
                    procs[proc_i]->GetJob(jobs[jobs_i]);                        //----If enough memory, take job
                    procs[proc_i]->ClaimCPU();
                    jobs_i += 1;                                                //----Increases jobs_i to go through jobs array
                }
            }

        }

        for(proc_i = 0; proc_i < PROCESSORS; proc_i += 1) {                     //----Simulates 50 cycles of processor work

            procs[proc_i]->CalcCycles(TIME_INTERVAL);                           //----Calculates remaining process time
            if(procs[proc_i]->JobProgress() == JOB_DONE) {
                procs[proc_i]->FreeCPU();
            }

        }

        for(file_i = 0; file_i < PROCESSORS; file_i += 1) {                      //----File output
            schedule_file << "Processor " << procs[file_i]->PNum() << " current ";
            schedule_file << "runtime: " << procs[file_i]->Cycles() << endl;
        }
        if(jobs_i != total_jobs) {
            schedule_file << "The next job to be scheduled is ";
            schedule_file << jobs[jobs_i]->ShowPid() << "\n" << endl;
        }
        else {
            schedule_file << "All processes are complete" << endl;
        }
    }

	schedule_file.close();                                                      //----Closes output file;

	return;
}


void
ProcessorOutput() {
    int i = 0;

    procs[0]->file.open("processors.txt");                                      //----Clears the processors.txt file just in case
    procs[0]->FileOutput();                 	                                //    "make clean" has not been run

    for(; i < PROCESSORS; i += 1) {                                             //----Displays output to user and writes to
        procs[i]->DisplayOutput();                                              //    processors.txt as well
        procs[i]->file.open("processors.txt", ios::app);                        //----The output file 
        procs[i]->FileOutput();
        procs[i]->file.close();
    }

    for(i = 0; i < PROCESSORS; i += 1) {                                        //----Deletes processors since we're done using
        delete procs[i];                                                        //    them
    }

    return;
}

