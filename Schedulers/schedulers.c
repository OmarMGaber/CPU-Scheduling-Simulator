//
// Created by Omar on 01/12/2023.
//

#include "schedulers.h"
#include "../utilities.h"
#include "../Collections/priorityQueue.h"
#include "../Models/process.h"
#include "../Models/ganttChart.h"


LinkedList *firstComeFirstServe(PriorityQueue *processQueue, UnitTime *waitTime) {
    UnitTime currentTime = (neglectContextSwitching) ? ((Process *) top(processQueue))->arrivalTime : 0;
    int index = -1;
    *waitTime = (neglectContextSwitching) ? 0 : 1;

    Process *processes = (Process *) malloc(sizeof(Process) * processQueue->size);
    ENSURE_NON_NULL(processes, OUT_OF_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

    LinkedList *ganttChartSegments = createLinkedList();
    ENSURE_NON_NULL(ganttChartSegments, GANTT_CHART_ALLOCATION_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

    while (!isEmpty(processQueue)) {
        Process *process = (Process *) top(processQueue);
        pop(processQueue);

        process->responseTime = currentTime - process->arrivalTime;
        process->waitingTime = currentTime - process->arrivalTime;
        process->completionTime = currentTime + process->burstTime;
        process->turnaroundTime = process->completionTime - process->arrivalTime;

        waitTime += process->waitingTime;
        currentTime += process->burstTime;
        processes[++index] = *process;

        // add gannt chart segment
        GanttChartSegment *segment = (GanttChartSegment *) malloc(sizeof(GanttChartSegment));
        ENSURE_NON_NULL(segment, GANTT_CHART_ALLOCATION_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

        // convert process id to string
        char *processIDString = (char *) malloc(sizeof(char) * 10);
        itoa(process->processID, processIDString, 10);
        // add P to the beginning of the string
        char *temp = (char *) malloc(sizeof(char) * 10);
        strcpy(temp, "P");
strcat(temp, processIDString);
        strcpy(processIDString, temp);

        segment->segmentName = processIDString;
        segment->segmentStart = currentTime - process->burstTime;
        segment->segmentEnd = currentTime;
        pushBack(ganttChartSegments, segment);
    }

    return ganttChartSegments;
}
