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
    printTableHeader("Processes Table", processInformationArray, lengthOfProcessInformationArray);
    for (int i = 0; i < numberOfProcesses; ++i)
        printProcessRow(&processes[i]);
}
