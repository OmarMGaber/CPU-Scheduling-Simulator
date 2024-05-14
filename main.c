#include <stdio.h>
#include <string.h>
#include "Models/process.h"
#include "Collections/priorityQueue.h"
#include "Schedulers/schedulers.h"
#include "Models/ganttChart.h"
#include "Collections/linkedList.h"
#include "utils/exceptions.h"


char *toStringProcess(void *element) {
    Process *ptr = (Process *) element;
    char *string = (char *) malloc(sizeof(char) * 100);

    sprintf(string, "\nProcess ID: %d, Arrival Time: %d, Burst Time: %d, Remaining Time: %d, Priority: %d\n",
            ptr->processID, ptr->arrivalTime, ptr->burstTime, ptr->remainingTime, ptr->priority);

    return string;
}


int main(int argc, char *argv[]) {
    if (argc < 4)
        THROW_EXCEPTION(EXIT_FAILURE, "Invalid number of arguments");

    int processNumIndex = 1;
    if (strcmp(argv[1], "-file") == 0) {
        // Redirecting to io folder taking cmake file as a baseline.
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/error.txt", "w", stderr);
        ++processNumIndex;
    }

    int numberOfProcesses = atoi(argv[processNumIndex]);

//    numberOfProcesses = 0;

    if (numberOfProcesses < 0)
        THROW_EXCEPTION(EXIT_FAILURE, "Invalid number of processes");
    if (numberOfProcesses > 10000)
        THROW_EXCEPTION(EXIT_FAILURE, "More than 10000 processes!, What are you trying to do?");

    numberOfProcesses = 10;

    Process *processes = (Process *) malloc(sizeof(Process) * numberOfProcesses);
    ENSURE_ALLOCATED_ELSE_REPORT_ERROR(processes, MEMORY_ALLOCATION_ERROR_MESSAGE);

    initializeProcess(&processes[0], 0, 1);
    initializeProcess(&processes[1], 0, 1);
    initializeProcess(&processes[2], 0, 1);
    initializeProcess(&processes[3], 0, 1);
    initializeProcess(&processes[4], 0, 1);
    initializeProcess(&processes[5], 0, 1);
    initializeProcess(&processes[6], 0, 1);
    initializeProcess(&processes[7], 0, 1);
    initializeProcess(&processes[8], 0, 1);
    initializeProcess(&processes[9], 0, 1);

    int waitTime = 0;
    setNeglectContextSwitching(true);
    LinkedList *ganttChart = firstComeFirstServe(processes, numberOfProcesses, sizeof(Process), &waitTime);
    printProcessTable(processes, numberOfProcesses);

    printGanttChart(ganttChart, 3);

    setNeglectContextSwitching(true);
    ganttChart = roundRobin(processes, numberOfProcesses, sizeof(Process), waitTime);
    printProcessTable(processes, numberOfProcesses);

    printGanttChart(ganttChart, 3);

    free(processes);


    fprintf(stderr, "No errors Occurred, program exited successfully\n");
    return 0;
}
