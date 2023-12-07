//
// Created by Omar on 07/12/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../utilities.h"
#include "ganttChart.h"
#include "../Collections/linkedList.h"
#include <math.h>

void printDivisor(size_t length);

int getTotalDuration(LinkedList *ganttChartSegments);

void printTimeLine(LinkedList *ganttChartSegments, int finalWidth, float scaleFactor);

void printSegment(int segmentDuration, char *segmentName);

void printAllSegments(LinkedList *ganttChartSegments, int finalWidth, float scaleFactor);

float calculateScaleFactor(int totalDuration, int finalWidth);

void printTab(int numberOfTabs);

static LinkedList *divides;

void printGanttChart(LinkedList *ganttChartSegments, int numberOfTabs) {
    divides = createLinkedList();

    int totalDuration = getTotalDuration(ganttChartSegments);
    int finalWidth = MIN(totalDuration, MAX_GANTT_CHART_WIDTH);

    float scaleFactor = calculateScaleFactor(totalDuration, finalWidth);

    printf("Gantt Chart:\n");

    printTab(numberOfTabs);
    printDivisor(finalWidth * MAX(scaleFactor, 1) + 1);

    printTab(numberOfTabs);
    printAllSegments(ganttChartSegments, finalWidth, scaleFactor);

    printTab(numberOfTabs);
    printDivisor(finalWidth * MAX(scaleFactor, 1) + 1);

    printTab(numberOfTabs);
    printTimeLine(ganttChartSegments, finalWidth, scaleFactor);

    destroyLinkedList(divides);
}

void printAllSegments(LinkedList *ganttChartSegments, int finalWidth, float scaleFactor) {
    LinkedListNode *currentNode = ganttChartSegments->head;
    while (currentNode != NULL) {
        GanttChartSegment *segment = (GanttChartSegment *) currentNode->data;
        printSegment(2 * getSegmentDuration(segment) * scaleFactor, segment->segmentName);

        currentNode = currentNode->nextNode;
    }

    printf("|\n");
}

int numDigits(int number) {
    return (int) floor(log10(number)) + 1;
}

void printTimeLine(LinkedList *ganttChartSegments, int finalWidth, float scaleFactor) {

    GanttChartSegment *segment = front(ganttChartSegments);
    printf("%d", segment->segmentStart);
    while (!isEmptyLS(divides)) {
        int spaces = (int) getElementAt(divides, 0);
        popFront(divides);
        for (int i = 0; i < spaces; ++i)
            printf(" ");

        printf("%d", segment->segmentEnd);

        popFront(ganttChartSegments);
        segment = front(ganttChartSegments);
    }
    printf("\n");

    //    GanttChartSegment *segment = front(ganttChartSegments);
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
//        popFront(ganttChartSegments);
//        segment = front(ganttChartSegments);
//    }
//    printf("\n");
}

void printSegment(int segmentDuration, char *segmentName) {
    int spaces = segmentDuration - (int) strlen(segmentName);

    spaces = MAX(spaces, 2);
    spaces /= 2;

    pushBack(divides, (void *) (spaces * 2 + (int) strlen(segmentName) - 1));

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
        GanttChartSegment *segment = (GanttChartSegment *) getElementAt(ganttChartSegments, i);
        totalDuration += getSegmentDuration(segment);
    }
    return totalDuration;
}

void printDivisor(size_t length) {
    for (int i = 0; i <= length; ++i)
        printf("--");
    printf("\n");
}

float calculateScaleFactor(int totalDuration, int finalWidth) {
    if (totalDuration <= finalWidth)
        return (float) MAX_GANTT_CHART_WIDTH / (float) totalDuration;

    return (float) finalWidth / (float) totalDuration;
}

void printTab(int numberOfTabs) {
    for (int i = 0; i < numberOfTabs; ++i)
        printf("\t");
}
