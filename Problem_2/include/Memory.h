/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 05/01/2015                                             *
	Assignment: Project 2                                        *
	Purpose: Implement in-house version of malloc and free       *
*****************************************************************/
#ifndef MEMORY_H
#define MEMORY_H
//----
#include <cstdlib>
#include <vector>
//----
static const int MEM_SIZE = 1024 * 8 * 1000 * 10;                               //----(Kb * 8) * 1000 = MB) * 10 = 10 MB
//----
static unsigned char *MEMORY_POOL = (unsigned char*)malloc(MEM_SIZE);

#endif
