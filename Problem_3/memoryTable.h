/* 
 * File:   memoryTable.h
 * Author: Li
 *
 * Created on May 8, 2015, 7:08 PM
 */

#ifndef MEMORYTABLE_H
#define	MEMORYTABLE_H
#include <iostream>
using namespace std;

class memoryTable {
public:
    memoryTable();
    memoryTable(int,long,long);
    virtual ~memoryTable();
    void display();
    long Memspace();
    bool getfree();
    void setFree(bool a);
    long getEnd();
    long getStart();
    int getId();
    void setId(int id);
    int ProcNum;
private:
    
    long StartAdd;
    long EndAdd;
    bool freeAdd;
};

#endif	/* MEMORYTABLE_H */

