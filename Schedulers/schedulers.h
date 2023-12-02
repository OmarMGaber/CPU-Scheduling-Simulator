//
// Created by Omar on 30/11/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
#define CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H

#include <stdio.h>
#include <malloc.h>
#include "../Models/process.h"

#define bool short
#define true (short)1
#define false (short)0

static bool neglectContextSwitching = true;

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
