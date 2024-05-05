//
// Created by Omar on 07/12/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "ganttChart.h"
#include <math.h>

void printDivisor(size_t length);

int getTotalDuration(LinkedList *ganttChartSegments);

void printTimeLine(LinkedList *ganttChartSegments, int finalWidth, float scaleFactor);

void calculateSegmentLength(int segmentDuration, char *segmentName);

void printAllSegments(LinkedList *ganttChartSegments, int finalWidth, float scaleFactor);

float calculateScaleFactor(int totalDuration, int finalWidth);

void printTab(int numberOfTabs);

// temporary global linked list to store the number of spaces between segments until i fix the printTimeLine function
static LinkedList *divides;

void printGanttChart(LinkedList *ganttChartSegments, size_t numberOfTabs) {
    divides = ls_new();

    int totalDuration = getTotalDuration(ganttChartSegments);
    int finalWidth = __min(totalDuration, MAX_GANTT_CHART_WIDTH);

    float scaleFactor = calculateScaleFactor(totalDuration, finalWidth);

    printTab(numberOfTabs);
    printf("Gantt Chart:\n");

    printTab(numberOfTabs);
    printf("~~~~~~~~~~~~\n");

//    printTab(numberOfTabs);
//    printDivisor(finalWidth * MAX(scaleFactor, 1) + 1);

    printTab(numberOfTabs);
    printAllSegments(ganttChartSegments, finalWidth, scaleFactor);

//    printTab(numberOfTabs);
//    printDivisor(finalWidth * MAX(scaleFactor, 1) + 1);

    printTab(numberOfTabs);
//    printTimeLine(ganttChartSegments, finalWidth, scaleFactor);

    ls_destroy(divides);
}

void printAllSegments(LinkedList *ganttChartSegments, int finalWidth, float scaleFactor) {
    if (IS_EMPTY_LS(ganttChartSegments))
        return;

    LinkedListNode *currentNode = ganttChartSegments->head;
    while (currentNode != NULL) {
        GanttChartSegment *segment = (GanttChartSegment *) currentNode->data;
        calculateSegmentLength(2 * getSegmentDuration(segment) * scaleFactor, segment->segmentName);

        currentNode = currentNode->next;
    }

    printf("|\n");
}

int numDigits(int number) {
    return (int) floor(log10(number)) + 1;
}

void printTimeLine(LinkedList *ganttChartSegments, int finalWidth, float scaleFactor) {
    if (IS_EMPTY_LS(ganttChartSegments))
        return;

    GanttChartSegment *segment = ls_front(ganttChartSegments);
    printf("%d", segment->segmentStart);
    while (!IS_EMPTY_LS(divides)) {
        int spaces = (int) ls_getElementAt(divides, 0);
        ls_popFront(divides);
        for (int i = 0; i < spaces; ++i)
            printf(" ");

        printf("%d", segment->segmentEnd);

        ls_popFront(ganttChartSegments);
        segment = ls_front(ganttChartSegments);
    }
    printf("\n");

    //    GanttChartSegment *segment = ls_front(ganttChartSegments);
//    printf("%d", segment->segmentStart);
//
//
//    while (segment != NULL) {
//        int spaces = 2 * getSegmentDuration(segment) * scaleFactor - numDigits(segment->segmentEnd);
//        for (int i = 0; i < spaces; ++i)
//            printf(" ");
//
//        printf("%d", segment->segmentEnd);
//
//        ls_popFront(ganttChartSegments);
//        segment = ls_front(ganttChartSegments);
//    }
//    printf("\n");
}

void calculateSegmentLength(int segmentDuration, char *segmentName) {
    int spaces = segmentDuration - (int) strlen(segmentName);

    spaces = __max(spaces, 2);
    spaces /= 2;

    ls_pushBack(divides, (void *) (spaces * 2 + (int) strlen(segmentName) - 1));

    printf("|");
    for (int i = 0; i < spaces; ++i)
        printf(" ");

    printf("%s", segmentName);

    for (int i = 0; i < spaces; ++i)
        printf(" ");
}

int getTotalDuration(LinkedList *ganttChartSegments) {
    int totalDuration = 0;
    for (int i = 0; i < ganttChartSegments->size; ++i) {
        GanttChartSegment *segment = (GanttChartSegment *) ls_getElementAt(ganttChartSegments, i);
        totalDuration += getSegmentDuration(segment);
    }
    return totalDuration;
}

void printDivisor(size_t length) {
    for (int i = 0; i <= length; ++i)
        printf("==");
    printf("\n");
}

float calculateScaleFactor(int totalDuration, int finalWidth) {
    if (totalDuration <= finalWidth)
        return (float) MAX_GANTT_CHART_WIDTH / (float) totalDuration;

    return (float) finalWidth / (float) totalDuration;
}

void printTab(int numberOfTabs) {
    printf("%*s", numberOfTabs * 4, "");
}
