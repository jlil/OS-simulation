#ifndef JOB_H
#define JOB_H

#include<iostream>
using namespace std;

// Job Class
//Contains all the information about a specific job.
class Job {
private:
    long  number;
    long  priority;
    long  size;
    long  maxCpu;
    long  currentTime;
    long  enteredTime;
    long  ioLeft;
    long  location;
    bool  inMemory;
    bool  latched;
    bool  blocked;
    bool  kill;
    bool  inCpu;


public:
    //Constructor with no parameters sets the job Number number to -1
    Job() {
        number = -1;
        priority=0;
        location=0;
        size=0;
        enteredTime=0;
        maxCpu=0;
        ioLeft=0;
        inMemory=false;
        latched = false;
        blocked = false;
        kill = false;
        inCpu=false;

    }
    //Constructor receives five parameters from the p[] and sets them accordignly.
    Job(long number, long priority, long size, long maxCpu, long enteredTime) {
        this->number=number;
        this->priority=priority;
        this->size=size;
        this->maxCpu=maxCpu;
        this->enteredTime=enteredTime;

        currentTime=maxCpu;
        ioLeft=0;
        inMemory=false;
        latched = false;
        blocked = false;
        kill = false;
        inCpu=false;
    }

    // functions used to retrieve and set values for private variables
    bool isKilled() {
        return kill;
    }

    void setKilled(bool kill) {
        this->kill = kill;
    }


    bool isBlocked() {
        return blocked;
    }

    void setBlocked(bool blocked) {
        this->blocked = blocked;
    }
    bool isInMemory() {
        return inMemory;
    }

    void setInMemory(bool inMemory) {
        this->inMemory = inMemory;
    }

    bool isLatched() {
        return latched;
    }

    void setLatched(bool latched) {
        this->latched = latched;
    }

    long getLocation() {
        return location;
    }

    void setLocation(long location) {
        this->location = location;
    }

    long getNumber() {
        return number;
    }

    void setNumber(long number) {
        this->number = number;
    }

    long getPriority() {
        return priority;
    }

    void setPriority(long priority) {
        this->priority = priority;
    }

    long getEnteredTime() {
        return enteredTime;
    }

    void setEnteredTime(long enteredTime ) {
        this->enteredTime = enteredTime;
    }

    long getSize() {
        return size;
    }

    void setSize(long size) {
        this->size = size;
    }

    long getMaxCpu() {
        return maxCpu;
    }

    void setMaxCpu(long maxCpu) {
        this->maxCpu = maxCpu;
    }

    long getCurrentTime() {
        return currentTime;
    }

    void setCurrentTime(long currentTime) {
        this->currentTime = currentTime;
    }

    long getIoLeft() {
        return ioLeft;
    }

    void setIoLeft(long ioLeft) {
        this->ioLeft = ioLeft;
    }

    bool IsInCpu() {
        return inCpu;
    }

    void setInCpu(bool inCpu) {
        this->inCpu= inCpu;
    }

    // print various job info(used for debugging)
    void printInfo() {

        cout<<endl;
        cout<<"Number :"<<number<<endl;
        cout<<"Size: "<<size<<endl;
        cout<<"Priority: "<<priority<<endl;
        cout<<"Entered Time: "<<enteredTime<<endl;
        cout<<"Location: "<<location<<endl;
        cout<<"Blocked: "<<blocked<<endl;
        cout<<"Max CPU Time: "<<maxCpu<<endl;
        cout<<"I/O LEFT: "<<ioLeft<<endl;
        cout<<endl;
    }
};

#endif
