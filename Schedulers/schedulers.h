//
// Created by Omar on 30/11/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
#define CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H

#include <stdio.h>
#include <malloc.h>
#include "../Models/process.h"
#include "../Collections/priorityQueue.h"
#include "../utilities.h"
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


static int neglectContextSwitching = 1;

//void printGanttChart(const Process *processes, int numberOfProcesses);

LinkedList* firstComeFirstServe(PriorityQueue *processQueue, UnitTime *waitTime);

void shortestJobFirst(PriorityQueue *processQueue);

void shortestRemainingTimeFirst(PriorityQueue *processQueue);

void roundRobin(PriorityQueue *processQueue, UnitTime quantum);

void highestResponseRatioNext(PriorityQueue *processQueue);

void longestJobFirst(PriorityQueue *processQueue);

void multilevelQueueScheduling(PriorityQueue *processQueue);

void multilevelFeedbackQueueScheduling(PriorityQueue *processQueue);

void priorityScheduling(PriorityQueue *processQueue);

#endif //CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
