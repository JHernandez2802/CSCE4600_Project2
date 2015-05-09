/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 05/01/2015                                             *
	Assignment: Project 2                                        *
	Purpose: Implement in-house version of malloc and free       *
*****************************************************************/
#include "Memory.h"
//----
using namespace std;
//----
std::vector<unsigned char*> MEM_ASSIGNMENT;
int partition_sizes[4] {8, 8, 4, 2};
auto MEM_SIZE_RD = MEM_SIZE / 10000;


void*
MyMalloc(int requested_size) {                                                  //----Best fit fixed partition scheme
    auto partition = 0;
    auto partition_empty = false;
    auto i = (long)0;


    for(; (partition != requested_size) && (i < 3); i += 1) {                   //----See which partition the memory needs
        partition = requested_size % (MEM_SIZE_RD / partition_sizes[i]);
    }

    partition_empty = MEM_ASSIGNMENT.at(i);
    if(partition_empty) {                                                       //----Check for open partition
        *MEM_ASSIGNMENT[i] = '1';
        return (void *)(i + 1);                                                 //----Have to compensate for vector starting at 0
    }
    else {
        return 0;
    }
}


void*
MyFree(void* fake_address) {
    auto free_partition = (long)fake_address;

    *MEM_ASSIGNMENT[free_partition - 1] = '0';                                  //----Have to compensate for vector starting at 0
    return 0;
}


void
InitMemory() {
    unsigned char *partition_start = nullptr;
    auto i = 1;


    partition_start = (MEMORY_POOL + (MEM_SIZE_RD / partition_sizes[0]));
    MEM_ASSIGNMENT.push_back(partition_start);
    for(; i < 4; i += 1) {
        partition_start = (MEMORY_POOL + (MEM_SIZE_RD / partition_sizes[i]));
        MEM_ASSIGNMENT.push_back(partition_start);
    }
    partition_start = nullptr;

    return;
}
