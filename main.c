#include <stdio.h>
#include "Models/process.h"
#include "Schedulers/schedulers.h"
#include "utilities.h"

int main() {
    Process *processes;

    NewProcess newProcesses[] = {
            {1, 0, 24},
            {2, 0, 3},
            {3, 0, 3}
    };

    printf("First Come First Serve\n");
    processes = firstComeFirstServe(newProcesses, sizeof newProcesses / sizeof newProcesses[0]);
    printGanttChart(processes, sizeof newProcesses / sizeof newProcesses[0]);
    printProcessTable(processes, sizeof newProcesses / sizeof newProcesses[0]);

    free(processes);

    neglectContextSwitching = false;
    printf("\n\n\n");
    processes = firstComeFirstServe(newProcesses, sizeof newProcesses / sizeof newProcesses[0]);
    printProcessTable(processes, sizeof newProcesses / sizeof newProcesses[0]);


//    freeProcesses(processes, 5);
    return 0;
}
