/* 
 * File:   memoryTable.cpp
 * Author: Li
 * 
 * Created on May 8, 2015, 7:08 PM
 */

#include "memoryTable.h"

memoryTable::memoryTable() {
    ProcNum=0;
    StartAdd=0;
    EndAdd=0;
    freeAdd=false;
}

memoryTable::memoryTable(int x,long y,long z) {
    ProcNum=x;
    StartAdd=y;
    EndAdd=z;
    freeAdd=false;
}
void memoryTable::display(){
    cout<<ProcNum<<endl;
    cout<<StartAdd<<endl;
    cout<<EndAdd<<endl;
    cout<<freeAdd<<endl;
    
}
memoryTable::~memoryTable() {
}

long memoryTable::Memspace(){
    return (EndAdd-StartAdd);
}
bool memoryTable::getfree(){
    return freeAdd;
}
void memoryTable::setFree(bool a){
    freeAdd=a;
}
long memoryTable::getEnd(){
    return EndAdd;
}
long memoryTable::getStart(){
    return StartAdd;
}
int memoryTable::getId(){
    return ProcNum;
}
void memoryTable::setId(int id){
    ProcNum=id;
}