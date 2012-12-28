#ifndef CPUSCHEDULER_H
#define CPUSCHEDULER_H
#include <iostream>
#include <vector>
using namespace std;
bool cpuOnTrace=false;

// cpuScheduler
// Class used to schedule the next best job from memory
// returns the index of the job that is to run
// Algorithm: SRT
class cpuScheduler {

public:

    long schedule(vector<Job> jobsList) {

        // default set to -1 (indicates job is not found)
        long index = -1, i, minTime=10000000;

        for(i=0; i<jobsList.size(); i++) {
            // first checks that conditions for proper dispatching apply
            if(jobsList[i].isInMemory() && jobsList[i].getMaxCpu()!=0 && !jobsList[i].isKilled() && !jobsList[i].isBlocked()) {
                // then looks for the job with the shortest remaining time left.
                if(jobsList[i].getMaxCpu() < minTime ) {
                    minTime = jobsList[i].getMaxCpu();
                    index = i;
                }
            }
        }

        return index;
    }

};
#endif




