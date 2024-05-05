//
// Created by Omar on 01/12/2023.
//

#include <stdbool.h>
#include "schedulers.h"
#include "../Collections/priorityQueue.h"
#include "../Models/process.h"
#include "../Models/ganttChart.h"

void setNeglectContextSwitching(bool value) {
    neglectContextSwitching = value;
}

char *getProcessName(Process *process) {
    char *processIDString = (char *) malloc(sizeof(char) * 10);

    itoa(process->processID, processIDString, 10);
    char *temp = (char *) malloc(sizeof(char) * 10);

    strcpy(temp, "P");
    strcat(temp, processIDString);
    strcpy(processIDString, temp);

    return processIDString;
}

int firstComeFirstServeCompare(const void *process1, const void *process2) {
    if (lowestArrivalTime(process1, process2) == 0)
        return smallerProcessID(process1, process2);

    return lowestArrivalTime(process1, process2);
}

LinkedList *
firstComeFirstServe(Process *processes, const size_t numOfProcesses, int sizeOfElement, UnitTime *waitTime) {
    PriorityQueue *processQueue = convertArrayIntoPriorityQueue(processes, numOfProcesses, sizeOfElement,
                                                                firstComeFirstServeCompare);

    UnitTime currentTime;
    if (!IS_EMPTY_PQ(processQueue))
        currentTime = ((Process *) top(processQueue))->arrivalTime;
    *waitTime = 0;

    LinkedList *ganttChartSegments = ls_new();

    while (!IS_EMPTY_PQ(processQueue)) {
        Process *process = (Process *) top(processQueue);
        pop(processQueue);

        process->responseTime = currentTime - process->arrivalTime;
        process->waitingTime = currentTime - process->arrivalTime;
        process->completionTime = currentTime + process->burstTime;
        process->turnaroundTime = process->completionTime - process->arrivalTime;

        waitTime += process->waitingTime;
        currentTime += process->burstTime;

        GanttChartSegment *segment = (GanttChartSegment *) malloc(sizeof(GanttChartSegment));

        segment->segmentName = getProcessName(process);
        segment->segmentStart = currentTime - process->burstTime;
        segment->segmentEnd = currentTime;
        ls_pushBack(ganttChartSegments, segment);
        (neglectContextSwitching) ? currentTime += 0 : ++currentTime;
    }

    return ganttChartSegments;
}

LinkedList *roundRobin(Process *processes, const size_t numOfProcesses, int sizeOfElement, UnitTime quantum) {
}

LinkedList *shortestJobFirst(Process *processes, const size_t numOfProcesses, int sizeOfElement) {

}