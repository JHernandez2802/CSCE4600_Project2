/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 05/01/2015                                             *
	Assignment: Project 2                                        *
	Purpose: Implement in-house version of malloc and free       *
*****************************************************************/
#include <iostream>
#include "memory.h"
//----
using namespace std;


void*
MyMalloc(int requested_size) {

    if(((long)MEM_POINTER - MEM_START + requested_size) <= MEM_SIZE) {
        MEM_POINTER += requested_size;
    }
    return MEM_POINTER;
}


void*
MyFree(void* address) {

    MEM_POINTER -= ((long)address - MEM_START);
    return 0;
}
