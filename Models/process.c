//
// Created by Omar on 01/12/2023.
//

#include <stdio.h>
#include "process.h"
#include "table.h"

void initializeProcess(Process *process, int arrivalTime, int burstTime) {
    process->processID = nextProcessID++;
    process->arrivalTime = arrivalTime;
    process->burstTime = burstTime;
    process->completionTime = 0;
    process->turnaroundTime = 0;
    process->waitingTime = 0;
    process->responseTime = 0;
    process->priority = 0;
}

void printProcessRow(const Process *process) {
    printf("| %*d | %*d | %*d | %*d | %*d | %*d | %*d |\n",
           processInformationArray[0].stringLength, process->processID,
           processInformationArray[1].stringLength, process->burstTime,
           processInformationArray[2].stringLength, process->arrivalTime,
           processInformationArray[3].stringLength, process->responseTime,
           processInformationArray[4].stringLength, process->waitingTime,
           processInformationArray[5].stringLength, process->completionTime,
           processInformationArray[6].stringLength, process->turnaroundTime);
    printTableDivider(processInformationArray, lengthOfProcessInformationArray);
}


void printProcessTable(const Process *processes, int numberOfProcesses) {
    printTableHeader("Processes Models", processInformationArray, lengthOfProcessInformationArray);
    for (int i = 0; i < numberOfProcesses; ++i)
        printProcessRow(&processes[i]);
}

int compareByArrivalTime(const void *process1, const void *process2) {
    return ((Process *) process1)->arrivalTime - ((Process *) process2)->arrivalTime;
}

int compareByBurstTime(const void *process1, const void *process2) {
    return ((Process *) process1)->burstTime - ((Process *) process2)->burstTime;
}

int compareByRemainingTime(const void *process1, const void *process2) {
    return ((Process *) process1)->remainingTime - ((Process *) process2)->remainingTime;
}

int compareByPriority(const void *process1, const void *process2) {
    return ((Process *) process1)->priority - ((Process *) process2)->priority;
}

int compareByResponseRatio(const void *process1, const void *process2) {
    return ((Process *) process1)->responseTime - ((Process *) process2)->responseTime;
}

int compareByProcessID(const void *process1, const void *process2) {
    return ((Process *) process1)->processID - ((Process *) process2)->processID;
}