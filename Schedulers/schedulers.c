//
// Created by Omar on 01/12/2023.
//

#include "schedulers.h"
#include "../Models/process.h"

void printGanttChart(const Process *processes, int numberOfProcesses) {}

Process *firstComeFirstServe(NewProcess *newProcess, int numOfProcesses, UnitTime *waitTime) {
    UnitTime currentTime = (neglectContextSwitching) ? newProcess[0].arrivalTime : 0;
    *waitTime = (neglectContextSwitching) ? 0 : 1;

    Process *processes = malloc(sizeof(Process) * numOfProcesses);
    if (processes == NULL) {
        printf(OUT_OF_MEMORY_ERROR_MESSAGE);
        exit(FirstComeFirstServe_EXIT_CODE);
    }

    for (int i = 0; i < numOfProcesses; i++) {
        processes[i].arrivalTime = newProcess[i].arrivalTime;
        processes[i].processID = newProcess[i].processID;
        processes[i].burstTime = newProcess[i].burstTime;

        processes[i].responseTime = currentTime;
        processes[i].waitingTime = currentTime;

        currentTime += processes[i].burstTime;
        processes[i].turnaroundTime = currentTime;
        processes[i].completionTime = currentTime;
        *waitTime += processes[i].waitingTime;
    }

    printf("waitTime: %d\n", *waitTime);
    return processes;
}
