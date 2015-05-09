// File memory.cpp

/*****************************************************************
	Programmer: Matthew Sherwood, Li Zhang, Juan Hernandez       *
	Class: CSCE 4600                                             *
	Date: 04/27/2015                                             *
	Assignment: Project 2                                        *
	Purpose: To  simulate of different scheduling disciplines to *
             allocate set of processes to available processors   *
*****************************************************************/


#include "processes.h"
#include "memoryTable.h"
#include <vector>
int INTERVAL=50;//every 50 cycle, process arrive
static int MEM_SIZE;                               
static unsigned char *MEMORY_POOL;
static unsigned char *MEM_POINTER;
static long MEM_START ;
c_Proc** Proccess;
void re_malloc(c_Proc* p);
void my_malloc(c_Proc* p);
vector<memoryTable*> memorylist;
vector<memoryTable*> tmplist;
int check(c_Proc* p){//free space or not
    int position=-1;
    int space;
    for(int i=0;i<memorylist.size();i++){
        if((memorylist.at(i)->Memspace()>=p->mem())&&(memorylist.at(i)->getfree())){
            space=memorylist.at(i)->Memspace();
            position=i;
            break;
        }       
    }
    for(int i=position;i<memorylist.size();i++){
        if((memorylist.at(i)->Memspace()>=p->mem())&&(memorylist.at(i)->getfree()))
            if(memorylist.at(i)->Memspace()<space){
                space=memorylist.at(i)->Memspace();
                position=i;
            }
    }
    return position;
        
}
void compact(){
    
//    memoryTable* newtable=new memoryTable(-1,(long)MEM_POINTER,(long)(MEM_POINTER+MEM_SIZE*sizeof(char)));
//    newtable->setFree(true);
//    tmplist.push_back(newtable);//initail memTlb
//    for(int i=0;i<memorylist.size();i++){
//        if(memorylist.at(i)->ProcNum>0){
//            
//        }           
//    }
//    memorylist.clear();
//    memorylist=tmplist;
}
void re_malloc(c_Proc* p){
    int position=check(p);
    if(position!=-1){//can malloc
        long MEM_END=(long)(tmplist.at(position)->getStart()+p->mem()*sizeof(char));//size of memory
        memoryTable* newtable=new memoryTable(p->pid(),memorylist.at(position)->getStart(),MEM_END);//new block of request
        memoryTable* newtable2=new memoryTable(-1,MEM_END+1,memorylist.at(position)->getEnd());//new block from 
        memorylist.at(position)->setId(-2);
        newtable2->setFree(true);
        memorylist.push_back(newtable);
        memorylist.push_back(newtable2);
    }
}
void my_malloc(c_Proc* p){//using best fit
    int position=check(p);
    if(position!=-1){//can malloc
        long MEM_END=(long)(memorylist.at(position)->getStart()+p->mem()*sizeof(char));//size of memory
        memoryTable* newtable=new memoryTable(p->pid(),memorylist.at(position)->getStart(),MEM_END);//new block of request
        memoryTable* newtable2=new memoryTable(-1,MEM_END+1,memorylist.at(position)->getEnd());//new block from 
        memorylist.at(position)->setId(-2);
        newtable2->setFree(true);
        memorylist.push_back(newtable);
        memorylist.push_back(newtable2);
    }
    else//can not malloc
    {
        cout<<"not enough place"<<endl;
    }
}
void my_free(c_Proc* P){
    int id=P->pid();
    int position;
    for(int i=0;i<memorylist.size();i++){
        if(memorylist.at(i)->getId()==id){
            position=i;
            break;
        }      
    }
    memorylist.at(position)->setFree(true);
    memorylist.at(position)->setId(-1);
    compact();
    
}
void simulator(c_Proc** Proc,int total,int space){
    int number=total;//total number of processes
    int INTERVAL=50;//every 50 cycle, process arrive
    Proccess=Proc;
    MEM_SIZE = space;                               
    MEMORY_POOL = (unsigned char*)malloc(MEM_SIZE*sizeof(char));//
    MEM_POINTER = MEMORY_POOL;//pointer to start of memory
    MEM_START = (long)MEMORY_POOL;//long int represent address
    memoryTable* newtable=new memoryTable(-1,(long)MEM_POINTER,(long)(MEM_POINTER+MEM_SIZE*sizeof(char)));
    newtable->setFree(true);
    memorylist.push_back(newtable);//initail memTlb
    for(int i=0;i<total;i++){
        my_malloc(Proccess[i]); 
        
    }
    //my_free(Proccess[]);
    for(int i=0;i<memorylist.size();i++)
        memorylist.at(i)->display();
}


