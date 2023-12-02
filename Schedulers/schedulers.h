//
// Created by Omar on 30/11/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
#define CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H

#include <stdio.h>
#include <malloc.h>
#include "../Models/process.h"

#define bool int
#define true 1
#define false 0

static bool neglectContextSwitching = true;


Process *firstComeFirstServe(NewProcess *newProcess, int numOfProcesses);

#endif //CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
