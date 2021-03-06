/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 05/01/2015                                             *
	Assignment: Project 2                                        *
	Purpose: Implement in-house version of malloc and free       *
*****************************************************************/
#include <iostream>
#include <string>
#include <chrono>
#include "Processor.h"
//----
using namespace std;
//----
#define ClearScreen() cout << "\033[H\033[J"
static const int PROC_NUM = 100;
//----
void FileOutput(fakeJobs**, int);
void WelcomeMsg();
void EndMsg();
extern void ExecutionLoop(fakeJobs**, int);
extern void ProcessorOutput();


int
main(void) {
    auto i = 0;
	fakeJobs* process[PROC_NUM];


    ClearScreen();
	WelcomeMsg();

	cout << "Creating " << PROC_NUM << " processes...";                         //----Creation of processes
    for(; i < PROC_NUM; i += 1) {
		process[i] = new fakeJobs(i);
    }
	cout << PROC_NUM << " new processes created." << endl;
	
    cout << "Running memory simulator...";                                     //----Execute processes
    auto start = chrono::high_resolution_clock::now();
	ExecutionLoop(process, PROC_NUM);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> difference = end - start;
	cout << "Success!\n" << endl;

	cout << "According to C++'s built-in high resolution clock" << endl;
    cout << "this program took " << difference.count() << " seconds\n" << endl;

    ProcessorOutput();                                                          //----Displays which processor has which job
                                                                                //    assigned to it
    FileOutput(process, PROC_NUM);                                              //----Sends processes info to processes.txt

    EndMsg();                                                                   //----Program termination
	
	return 0;
}


void
FileOutput(fakeJobs** process, int procNum) {
    int i = 0;

    process[0]->file.open("processes.txt");                                     //----Clears the data.txt file just in case
    process[0]->FileOutput();                                                   //    "make clean" has not been run
    process[0]->file.close();
	
    for(; i < procNum; ++i) {                                                   //----Writes process info to data.txt
		process[i]->file.open("processes.txt", ios::app); 
		process[i]->FileOutput();
		process[i]->file.close();
	}

    return;
}


void
WelcomeMsg() {

	cout << "Welcome to Group 14's Memory simulator!" << endl;
	cout << "For this simulation, all processors have" << endl;
	cout << "equal speed at 2GHz. This version uses" << endl;
    cout << "malloc to give a time comparison.\n" << endl;
	cout << "Let's get started!\n" << endl;

    return;
}


void
EndMsg() {

	cout << "Thank you for using the memory simulator!\n" << endl;
	cout << "The files generated by this program for verification are:" << endl;
	cout << "processors.txt processes.txt nextJob.txt\n" << endl;
	cout << "Goodbye!" << endl;

    return;
}
