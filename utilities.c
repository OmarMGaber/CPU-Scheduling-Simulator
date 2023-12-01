//
// Created by Omar on 01/12/2023.
//

#include <stdio.h>
#include "process.h"

void printGanttChart(const Process *processes, int numberOfProcesses) {
        printf("Gantt Chart: \n");

        printf(" ");
        for (int i = 0; i < numberOfProcesses; ++i) {
            for (int j = 0; j < processes[i].burstTime; ++j)
                printf("__");
            printf(" ");
        }

        printf("\n|");
        for (int i = 0; i < numberOfProcesses; ++i) {
            for (int j = 0; j < processes[i].burstTime - 1; ++j)
                printf(" ");
            printf("P%d", processes[i].processID);
            for (int j = 0; j < processes[i].burstTime - 1; ++j)
                printf(" ");
            printf("|");
        }

        printf("\n ");
        for (int i = 0; i < numberOfProcesses; ++i) {
            for (int j = 0; j < processes[i].burstTime; ++j)
                printf("--");
            printf(" ");
        }
        printf("\n");

        printf("0");
        for (int i = 0; i < numberOfProcesses; ++i) {
            for (int j = 0; j < processes[i].burstTime; ++j)
                printf("  ");
            if (processes[i].completionTime > 9)
                printf("\b");
            printf("%d", processes[i].completionTime);
        }
        printf("\n");
}