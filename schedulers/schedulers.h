//
// Created by Omar on 30/11/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
#define CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H

#include <stdio.h>
#include <malloc.h>
#include "../Models/process.h"
#include "../Collections/priorityQueue.h"
#include "../Collections/linkedList.h"

typedef enum {
    FirstComeFirstServe = 1,
    ShortestJobFirst,
    ShortestRemainingTimeFirst,
    PriorityScheduling,
    RoundRobin,
    HighestResponseRatioNext,
    LongestJobFirst,
    MultilevelQueueScheduling,

    NumberOfSchedulingAlgorithms
} SchedulingAlgorithm;


static bool neglectContextSwitching = false;

void setNeglectContextSwitching(bool value);

LinkedList *firstComeFirstServe(Process *processes, size_t numOfProcesses, int sizeOfElement, UnitTime *waitTime);

LinkedList *shortestJobFirst(Process *processes, size_t numOfProcesses, int sizeOfElement);

LinkedList *shortestRemainingTimeFirst(Process *processes, size_t numOfProcesses, int sizeOfElement);

LinkedList *roundRobin(Process *processes, size_t numOfProcesses, int sizeOfElement, UnitTime quantum);

LinkedList *highestResponseRatioNext(Process *processes, size_t numOfProcesses, int sizeOfElement);

LinkedList *longestJobFirst(Process *processes, size_t numOfProcesses, int sizeOfElement);

LinkedList *multilevelQueueScheduling(Process *processes, size_t numOfProcesses, int sizeOfElement);

LinkedList *multilevelFeedbackQueueScheduling(Process *processes, size_t numOfProcesses, int sizeOfElement);

LinkedList *priorityScheduling(Process *processes, size_t numOfProcesses, int sizeOfElement);

#endif //CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
