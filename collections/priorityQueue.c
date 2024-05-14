//
// Created by Omar on 03/12/2023.
//

/*
 *
 * Priority Queue
 * This is a generic priority queue implementation using a heap.
 * It has compare functions for the C data types: int, float, double, long long, short, and char *.
 *
 * GitHub: OmarMGaber
 */

#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"
#include "../utils/exceptions.h"
#include <string.h>

#define getParentIndex(i) ((i - 1) / 2)
#define getLeftChildIndex(i) ((2 * i) + 1)
#define getRightChildIndex(i) ((2 * i) + 2)
#define hasHigherPriority(pq, parentIndex, childIndex) pq->compare(pq->heapArray[parentIndex], pq->heapArray[childIndex]) < 0
#define hasParent(i) (i > 0)
#define hasLeftChild(priorityQueue, i) (getLeftChildIndex(i) < priorityQueue->size)
#define hasRightChild(priorityQueue, i) (getRightChildIndex(i) < priorityQueue->size)
#define getLeftChild(priorityQueue, i) (priorityQueue->heapArray[getLeftChildIndex(i)])
#define getRightChild(priorityQueue, i) (priorityQueue->heapArray[getRightChildIndex(i)])
#define getParent(priorityQueue, i) (priorityQueue->heapArray[getParentIndex(i)])
#define SWAP_VALUES(priorityQueue, i, j) {void *temp = priorityQueue->heapArray[i]; \
                                    priorityQueue->heapArray[i] = priorityQueue->heapArray[j];               \
                                    priorityQueue->heapArray[j] = temp;}

void heapifyUp(PriorityQueue *pq, int childIndex);

void heapifyDown(PriorityQueue *pq, int parentIndex);

PriorityQueue *createPriorityQueue(CompareFunction compare) {
    return createPriorityQueueWithCapacity(compare, DEFAULT_PRIORITY_QUEUE_CAPACITY);
}

PriorityQueue *
convertArrayIntoPriorityQueue(void *array, size_t arrayLength, int sizeOfElement, CompareFunction compare) {
    PriorityQueue *pq = createPriorityQueueWithCapacity(compare, arrayLength);
    for (int i = 0; i < arrayLength; ++i) {
        push(pq, array + (i * sizeOfElement));
    }

    return pq;
}

PriorityQueue *createPriorityQueueWithCapacity(CompareFunction compare, size_t capacity) {
    PriorityQueue *pq = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    ENSURE_ALLOCATED_ELSE_REPORT_ERROR(pq, MEMORY_ALLOCATION_ERROR_MESSAGE);

    pq->heapArray = (void **) malloc(capacity * sizeof(void *));
    ENSURE_ALLOCATED_ELSE_REPORT_ERROR(pq->heapArray, MEMORY_ALLOCATION_ERROR_MESSAGE);

    pq->size = 0;
    pq->indexOfLastElement = 0;
    pq->capacity = capacity;
    pq->compare = compare;
    return pq;
}

void *resizePriorityQueue(PriorityQueue *pq) {
    pq->capacity *= 2;
    pq->heapArray = realloc(pq->heapArray, pq->capacity * sizeof(void *));
    ENSURE_ALLOCATED_ELSE_REPORT_ERROR(pq->heapArray, MEMORY_ALLOCATION_ERROR_MESSAGE);

    return NULL;
}

void *top(PriorityQueue *pq) {
    if (IS_EMPTY_PQ(pq))
        THROW_EXCEPTION(EXIT_FAILURE, EMPTY_PRIORITY_QUEUE_ERROR_MESSAGE);

    return pq->heapArray[0];
}

void pop(PriorityQueue *pq) {
    if (IS_EMPTY_PQ(pq))
        THROW_EXCEPTION(EXIT_FAILURE, EMPTY_PRIORITY_QUEUE_ERROR_MESSAGE);

    pq->heapArray[0] = pq->heapArray[pq->indexOfLastElement - 1];
    --pq->indexOfLastElement;
    --pq->size;
    heapifyDown(pq, 0);
}

void push(PriorityQueue *pq, void *element) {
    if (REACHED_CAPACITY(pq))
        resizePriorityQueue(pq);

    pq->heapArray[pq->indexOfLastElement] = element;
    heapifyUp(pq, pq->indexOfLastElement);
    ++pq->size;
    ++pq->indexOfLastElement;
}

void heapifyUp(PriorityQueue *pq, int childIndex) {
    int parentIndex = getParentIndex(childIndex);
    while (hasParent(childIndex) && hasHigherPriority(pq, childIndex, parentIndex)) {
        SWAP_VALUES(pq, parentIndex, childIndex);
        childIndex = parentIndex;
        parentIndex = getParentIndex(childIndex);
    }
}

void heapifyDown(PriorityQueue *pq, int parentIndex) {
    while (hasLeftChild(pq, parentIndex)) {
        int higherPriorityChildIndex = getLeftChildIndex(parentIndex);
        if (hasRightChild(pq, parentIndex) &&
            hasHigherPriority(pq, getRightChildIndex(parentIndex), higherPriorityChildIndex))
            higherPriorityChildIndex = getRightChildIndex(parentIndex);

        if (hasHigherPriority(pq, parentIndex, higherPriorityChildIndex))
            break;
        else SWAP_VALUES(pq, parentIndex, higherPriorityChildIndex);

        parentIndex = higherPriorityChildIndex;
    }
}

// Debugging function
void printHeapTree(PriorityQueue *pq, char *(*toStringFunction)(void *)) {
    int level = 0;
    int levelSize = 1;
    int index = 0;
    while (index < pq->size) {
        for (int i = 0; i < levelSize && index < pq->size; i++) {
            printf("%d ", *(int *) pq->heapArray[index]);
            index++;
        }
        printf("\n");
        level++;
        levelSize *= 2;
    }
}

PriorityQueue *copy(PriorityQueue *pq) {
    PriorityQueue *copy = createPriorityQueueWithCapacity(pq->compare, pq->capacity);
    copy->size = pq->size;
    copy->indexOfLastElement = pq->indexOfLastElement;
    for (int i = 0; i < pq->size; ++i) {
        copy->heapArray[i] = pq->heapArray[i];
    }

    return copy;
}

void display(PriorityQueue *pq, char *(*toStringFunction)(void *)) {
    printf("Priority Queue: %s\n", toString(pq, toStringFunction));
}

char *toString(PriorityQueue *pq, char *(*toStringFunction)(void *)) {
    char *string = malloc(1);

    string[0] = '\0';
    for (int i = 0; i < pq->size; ++i) {
        char *elementString = toStringFunction(pq->heapArray[i]);
        string = realloc(string, strlen(string) + strlen(elementString) + 1);

        strcat(string, elementString);
        strcat(string, " ");
        free(elementString);
    }

    return string;
}

void destroy(PriorityQueue *pq) {
    free(pq->heapArray);
    free(pq);
}

// toString functions
char *toStringInt(void *element) {
    char *string = malloc(12);

    sprintf(string, "%d", *(int *) element);
    return string;
}

char *toStringFloat(void *element) {
    char *string = malloc(12);

    sprintf(string, "%f", *(float *) element);
    return string;
}

char *toStringDouble(void *element) {
    char *string = malloc(12);

    sprintf(string, "%lf", *(double *) element);
    return string;
}

char *toStringLongLong(void *element) {
    char *string = malloc(12);

    sprintf(string, "%lld", *(long long *) element);
    return string;
}

char *toStringShort(void *element) {
    char *string = malloc(12);

    sprintf(string, "%hd", *(short *) element);
    return string;
}

char *toStringString(void *element) {
    return *(char **) element;
}
