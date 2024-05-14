//
// Created by Omar on 07/12/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "ganttChart.h"
#include "../utils/exceptions.h"
#include <math.h>
#include <stdarg.h>

#define SEGMENT_WIDTH 3

void printSegment(GanttChartSegment *segment) {
    printf("Segment: %s, Duration: %d -> %d\n", segment->name, segment->start, segment->end);
}

void printT(size_t tab, char *format, ...) {
    while (tab-- > 0)
        printf("    "); // insted of \t to avoid different tab sizes in different text viewers

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

int calculateScaleFactor(int totalDuration, int segments) {
    if (segments == 0)
        THROW_EXCEPTION(EXIT_FAILURE, "Illegal operation, division by zero.");

    ///
}

int getTotalDuration(LinkedList *ganttChartSegments) {
    if (IS_EMPTY_LS(ganttChartSegments))
        return 0;

    return ((GanttChartSegment *) ganttChartSegments->tail->data)->end -
           ((GanttChartSegment *) ganttChartSegments->head->data)->start;
}

void printSegments(LinkedList *ganttChartSegments, size_t tabs) {
    LinkedListNode *currentNode = ganttChartSegments->head;
    printT(tabs + 1, "");
    while (currentNode != NULL) {
        GanttChartSegment *segment = (GanttChartSegment *) currentNode->data;

        printf("|%*s%s%*s", SEGMENT_WIDTH, " ", segment->name, SEGMENT_WIDTH, " ");

        currentNode = currentNode->next;
    }
    printf("|\n");
}

int calculateTotalLength(LinkedList *ganttChartSegments) {
    int totalLength = 1;
    LinkedListNode *iter = ganttChartSegments->head;
    while (iter != NULL) {
        totalLength += 1 + strlen(((GanttChartSegment *) iter->data)->name) + SEGMENT_WIDTH * 2;
        iter = iter->next;
    }

    return totalLength;
}

void printDivisor(size_t tab, const char *c, size_t length) {
    printT(tab, "");
    for (int i = 0; i < length; i++)
        printf("%s", c);
    printf("\n");
}

void printDurations(LinkedList *ganttChartSegments, size_t tabs) {
    LinkedListNode *currentNode = ganttChartSegments->head;
    printT(tabs, "    %d", ((GanttChartSegment *) currentNode->data)->start);

    while (currentNode != NULL) {
        GanttChartSegment *segment = (GanttChartSegment *) currentNode->data;

        int len = strlen(segment->name) + SEGMENT_WIDTH * 2 + 1;

        printf("%*d", len, segment->end);

        currentNode = currentNode->next;
    }
    printf("\n");
}

void printGanttChart(LinkedList *ganttChartSegments, size_t tabs) {
    printf("\n");

    tabs = __min(tabs, 10);

    printT(tabs, "Gantt Chart:\n");
    printT(tabs, "~~~~~~~~~~~~\n");

    if (IS_EMPTY_LS(ganttChartSegments)) {
        printT(tabs, "No segments to display.\n");
        return;
    }

    int dur = getTotalDuration(ganttChartSegments);

    if (dur < 0)
        THROW_EXCEPTION(EXIT_FAILURE, "Invalid Gantt Chart segments, overlapping segments detected.");

    int len = calculateTotalLength(ganttChartSegments);

    printDivisor(tabs + 1, "=", len);
    printSegments(ganttChartSegments, tabs);
    printDivisor(tabs + 1, "-", len);
    printDurations(ganttChartSegments, tabs);
    printDivisor(tabs + 1, "=", len);

    printT(tabs, "Total duration = %d\n\n", dur);
}
