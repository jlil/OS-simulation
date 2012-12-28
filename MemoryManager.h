#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include<iostream>
#include <vector>
using namespace std;

class MemoryManager {
private:
    long mem[100];  // mem array works as the memory
                    // table. Each new job added to
                    // memory has its size put
                    // in the array location
                    // that it was swapped in

public:
        //constructor
    MemoryManager() {
        for(long i=0; i<100; i++) {
            mem[i]=0;
        }
    }
        //Clears the mem table
    void clear() {
        for(int i=0; i<100; i++)
            mem[i]=0;
    }
        //Gets the size of the job and sets
        //that its size in where it is stored in mem
    void setJob(long index,vector<Job> jobsList) {
        mem[jobsList[index].getLocation()]=jobsList[index].getSize();

    }
    //removes job from mem
    void eraseJob(long location) {
        mem[location]=0;
    }
        //Gets the size of the job and sets
        //that its size in where it is stored in mem
    void setTable(vector<Job> jobsList, long index,long i) {
        mem[i]= jobsList[index].getSize();
    }

    //Takes the length of the job that wants to be put in memory
    //And looks if it can fit in memory if not then
    //it returns 100
    long MemTable(long joblen) {

        long i,temp;
        bool pass=false;
        for(i=0; i<100; i++) {
            if(i==0) {
                if(mem[i]!=0)
                    i=i+mem[i];
                else {
                    for(temp=1; temp<joblen; temp++) {
                        if(mem[i+temp]!=0) {
                            i=i+temp+mem[i+temp];
                            pass=false;
                            break;
                        } else pass=true;

                    }
                    if(pass) return i;
                }
            }
            while(mem[i]!=0)
                i = i + mem[i];
            if(mem[i]==0) {
                if((i+joblen)<100) {
                    for(temp=1; temp<joblen; temp++) {
                        if(mem[i+temp]!=0) {
                            i=i+temp+mem[i+temp];
                            pass=false;
                            while(mem[i]!=0)
                                i = i + mem[i];
                            break;
                        } else pass=true;
                    }
                    if(pass) return i;
                } else if(i+joblen>=100) return 100;
            }
        }
    }

    //Looks for the job by the job number
    //Returns the job index
    long findJob(vector<Job> jobsList,long jobNum) {
        for(long i=0; i<=jobsList.size(); i++)
            if(jobsList[i].getNumber()==jobNum)
                return i ;
    }


};

#endif
