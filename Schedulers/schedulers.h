//
// Created by Omar on 30/11/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
#define CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H

#include <stdio.h>
#include <malloc.h>
#include "../Models/process.h"
#include "../utilities.h"


// scheduler exit codes and messages
#define OUT_OF_MEMORY_ERROR_MESSAGE "Out of memory."
#define FirstComeFirstServe_EXIT_CODE (-201)
#define ShortestJobFirst_EXIT_CODE (-202)
#define ShortestRemainingTimeFirst_EXIT_CODE (-203)
#define RoundRobin_EXIT_CODE (-204)
#define HighestResponseRatioNext_EXIT_CODE (-205)
#define LongestJobFirst_EXIT_CODE (-206)
#define MultilevelQueueScheduling_EXIT_CODE (-207)
#define MultilevelFeedbackQueueScheduling_EXIT_CODE (-208)
#define PriorityScheduling_EXIT_CODE (-209)

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

void printGanttChart(const Process *processes, int numberOfProcesses);

Process *firstComeFirstServe(NewProcess *newProcess, int numOfProcesses, UnitTime *waitTime);

Process *shortestJobFirst(NewProcess *newProcess, int numOfProcesses);

Process *shortestRemainingTimeFirst(NewProcess *newProcess, int numOfProcesses);

Process *roundRobin(NewProcess *newProcess, int numOfProcesses, UnitTime quantum);

Process *highestResponseRatioNext(NewProcess *newProcess, int numOfProcesses);

Process *longestJobFirst(NewProcess *newProcess, int numOfProcesses);

Process *multilevelQueueScheduling(NewProcess *newProcess, int numOfProcesses);

Process *multilevelFeedbackQueueScheduling(NewProcess *newProcess, int numOfProcesses);

Process *priorityScheduling(NewProcess *newProcess, int numOfProcesses);

#endif //CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
