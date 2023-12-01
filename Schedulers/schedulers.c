//
// Created by Omar on 01/12/2023.
//

#include <stdio.h>
#include "../process.h"


Process *firstComeFirstServe(NewProcess *newProcess, int numOfProcesses) {
    UnitTime currentTime = 0, waitTime = 0;
    Process *processes = malloc(sizeof(Process) * numOfProcesses);

    for (int i = 0; i < numOfProcesses; i++) {
        processes[i].arrivalTime = newProcess[i].arrivalTime;
        processes[i].processID = newProcess[i].processID;
        processes[i].burstTime = newProcess[i].burstTime;

        processes[i].responseTime = currentTime;
        processes[i].waitingTime = currentTime;

        currentTime += processes[i].burstTime;
        processes[i].turnaroundTime = currentTime;
        processes[i].completionTime = currentTime;
        waitTime += processes[i].waitingTime;
    }

    return processes;
}

