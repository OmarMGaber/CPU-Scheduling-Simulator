//
// Created by Omar on 07/12/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_GANTTCHART_H
#define CPU_SCHEDULING_SIMULATOR_GANTTCHART_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utilities.h"
#include "../Models/process.h"
#include "../Collections/linkedList.h"

#define MAX_GANTT_CHART_WIDTH 45
#define GANTT_CHART_ALLOCATION_MEMORY_ERROR_MESSAGE "Failed to allocate memory for Gantt Chart."
#define getSegmentDuration(segment) (segment->segmentEnd - segment->segmentStart)

typedef struct {
    char *segmentName;
    UnitTime segmentStart;
    UnitTime segmentEnd;
} GanttChartSegment;

/**
 * @brief Prints a Gantt chart representation of the given linked list of Gantt chart segments.
 *
 * This function takes a linked list of GanttChartSegment structures and prints a Gantt chart
 * representation of the segments. The chart includes segment names, durations, and a timeline.
 * The chart is formatted to fit within the specified width @p finalWidth. which is the minimum
 * between the total duration of all segments and the maximum defined width of the chart.
 *
 * @param ganttChartSegments A linked list of GanttChartSegment structures.
 * @param numberOfTabs The number of tabs to be added before printing the Gantt chart.
 *
 * @note The function uses the following helper functions: printDivisor, getTotalDuration,
 * printTimeLine, printSegment, printAllSegments, calculateScaleFactor, and printTab.
 *
 * @warning The function assumes that the given linked list is not empty nor NULL.
 * @warning The function may not print the chart upper and lower divisors correctly (TODO).
 */
void printGanttChart(LinkedList *ganttChartSegments, int numberOfTabs);

#endif //CPU_SCHEDULING_SIMULATOR_GANTTCHART_H
