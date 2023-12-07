#include <stdio.h>
#include <string.h>
#include "Models/process.h"
#include "utilities.h"
#include "Collections/priorityQueue.h"
#include "Schedulers/schedulers.h"
#include "Models/ganttChart.h"
#include "Collections/linkedList.h"


char *toStringProcess(void *element) {
    Process *ptr = (Process *) element;
    char *string = (char *) malloc(sizeof(char) * 100);
    ENSURE_NON_NULL(string, OUT_OF_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

    sprintf(string, "\nProcess ID: %d, Arrival Time: %d, Burst Time: %d, Remaining Time: %d, Priority: %d\n",
            ptr->processID, ptr->arrivalTime, ptr->burstTime, ptr->remainingTime, ptr->priority);

    return string;
}


int main() {

    // test the first come first serve algorithm
    Process *processes = (Process *) malloc(sizeof(Process) * 4);
    ENSURE_NON_NULL(processes, OUT_OF_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

    initializeProcess(&processes[0], 0, 24);
    initializeProcess(&processes[1], 0, 3);
    initializeProcess(&processes[2], 0, 3);
//    initializeProcess(&processes[3], 0, 600);


    PriorityQueue *processQueue = createPriorityQueue(greaterBurstTime);
    for (int i = 0; i < 3; ++i)
        push(processQueue, &processes[i]);

    int waitTime = 0;

    LinkedList *ganttChart = firstComeFirstServe(processQueue, &waitTime);
    printGanttChart(ganttChart, 2);

    return 0;
}
