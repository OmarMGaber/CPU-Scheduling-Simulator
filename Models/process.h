//
// Created by Omar on 30/11/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_PROCESS_H
#define CPU_SCHEDULING_SIMULATOR_PROCESS_H

#include <malloc.h>
#include "table.h"

typedef int UnitTime;
typedef int Priority;

static int nextProcessID = 1; // A static global variable that automatic assign a new process its id incrementally.

// Process tableInformation array
static tableInformation processInformationArray[] = {
        {"Process ID", 10},
        {"Burst Time", 11},
        {"Arrival Time", 13},
        {"Response Time", 15},
        {"Waiting Time", 14},
        {"Completion Time", 17},
        {"Turnaround Time", 17},
};
static int lengthOfProcessInformationArray = sizeof(processInformationArray) / sizeof(processInformationArray[0]);

typedef struct {
    int processID;
    Priority priority;
    UnitTime burstTime;
    UnitTime arrivalTime;
    UnitTime responseTime;
    UnitTime waitingTime;
    UnitTime turnaroundTime;
    UnitTime completionTime;
    UnitTime remainingTime;
} Process;

void initializeProcess(Process *process, int arrivalTime, int burstTime);

void printProcessRow(const Process *process);

void printProcessTable(const Process *processes, int numberOfProcesses);

int lowestArrivalTime(const void *process1, const void *process2);

int lowestBurstTime(const void *process1, const void *process2);

int lowestRemainingTime(const void *process1, const void *process2);

int lowestPriority(const void *process1, const void *process2);

int lowestResponseRatio(const void *process1, const void *process2);

int smallerProcessID(const void *process1, const void *process2);

int greaterProcessID(const void *process1, const void *process2);

int greaterArrivalTime(const void *process1, const void *process2);

int greaterBurstTime(const void *process1, const void *process2);

int greaterRemainingTime(const void *process1, const void *process2);

int higherPriority(const void *process1, const void *process2);

int higherResponseRatio(const void *process1, const void *process2);

#endif //CPU_SCHEDULING_SIMULATOR_PROCESS_H
