//
// Created by Omar on 03/12/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_PRIORITY_QUEUE_H
#define CPU_SCHEDULING_SIMULATOR_PRIORITY_QUEUE_H

#include <stdio.h>
#include <malloc.h>
#include "../Models/process.h"
#include "compareFunctions.h"

#define EMPTY_PRIORITY_QUEUE_ERROR_MESSAGE "Priority queue is empty."

// priority queue function-like macros and constants
#define DEFAULT_PRIORITY_QUEUE_CAPACITY 100
#define IS_EMPTY_PQ(priorityQueue) (priorityQueue->size == 0)
#define REACHED_CAPACITY(priorityQueue) (priorityQueue->size == priorityQueue->capacity)

typedef char *(*ToStringFunction)(void *);

typedef struct {
    void **heapArray;
    size_t size;
    size_t capacity;
    int indexOfLastElement;
    CompareFunction compare;
} PriorityQueue;

// Function prototypes
PriorityQueue *createPriorityQueue(CompareFunction compare);

PriorityQueue *createPriorityQueueWithCapacity(CompareFunction compare, size_t capacity);

PriorityQueue *convertArrayIntoPriorityQueue(void *array, size_t arrayLength, int sizeOfElement, CompareFunction compare);

void push(PriorityQueue *pq, void *element);

void *top(PriorityQueue *pq);

void pop(PriorityQueue *pq);

PriorityQueue *copy(PriorityQueue *pq);

char *toString(PriorityQueue *pq, char *(*toStringFunction)(void *));

void display(PriorityQueue *pq, char *(*toStringFunction)(void *));

void heapSort(void *array, size_t size, size_t sizeOfElement, CompareFunction compare);

void destroy(PriorityQueue *pq);

// print functions and toString functions
char *toStringInt(void *a);

char *toStringString(void *a);

char *toStringFloat(void *a);

char *toStringLongLong(void *a);

char *toStringDouble(void *a);

char *toStringShort(void *a);

void printHeapTree(PriorityQueue *pq, char *(*toStringFunction)(void *));


#endif //CPU_SCHEDULING_SIMULATOR_PRIORITY_QUEUE_H
