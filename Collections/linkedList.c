//
// Created by Omar on 07/12/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utilities.h"
#include "../Models/process.h"
#include "../Models/ganttChart.h"

LinkedList *createLinkedList() {
    LinkedList *linkedList = (LinkedList *) malloc(sizeof(LinkedList));
    ENSURE_NON_NULL(linkedList, LINKED_LIST_ALLOCATION_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->size = 0;

    return linkedList;
}

void pushBack(LinkedList *linkedList, void *data) {
    LinkedListNode *newNode = (LinkedListNode *) malloc(sizeof(LinkedListNode));
    ENSURE_NON_NULL(newNode, LINKED_LIST_ALLOCATION_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

    newNode->data = data;
    newNode->nextNode = NULL;

    if (isEmptyLS(linkedList))
        linkedList->head = newNode;
    else
        linkedList->tail->nextNode = newNode;

    linkedList->tail = newNode;
    ++linkedList->size;
}

void pushFront(LinkedList *linkedList, void *data) {
    LinkedListNode *newNode = (LinkedListNode *) malloc(sizeof(LinkedListNode));
    ENSURE_NON_NULL(newNode, LINKED_LIST_ALLOCATION_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

    newNode->data = data;
    newNode->nextNode = linkedList->head;

    if (isEmptyLS(linkedList))
        linkedList->tail = newNode;

    linkedList->head = newNode;
    ++linkedList->size;
}

void popFront(LinkedList *linkedList) {
    if (isEmptyLS(linkedList))
        return;

    LinkedListNode *nodeToBeDeleted = linkedList->head;
    linkedList->head = linkedList->head->nextNode;

    free(nodeToBeDeleted);
    --linkedList->size;
}

void popBack(LinkedList *linkedList) {
    if (isEmptyLS(linkedList))
        return;

    LinkedListNode *iterator = linkedList->head;
    while (iterator->nextNode != linkedList->tail)
        iterator = iterator->nextNode;

    free(iterator->nextNode);
    iterator->nextNode = NULL;
    linkedList->tail = iterator;
    --linkedList->size;
}

void *front(LinkedList *linkedList) {
    if (isEmptyLS(linkedList))
        return NULL;

    return linkedList->head->data;
}

void *back(LinkedList *linkedList) {
    if (isEmptyLS(linkedList))
        return NULL;

    return linkedList->tail->data;
}

void *getElementAt(LinkedList *linkedList, size_t index) {
    if (isEmptyLS(linkedList) || index >= linkedList->size)
        return NULL;

    LinkedListNode *iterator = linkedList->head;
    for (size_t i = 0; i < index; ++i)
        iterator = iterator->nextNode;

    return iterator->data;
}

void removeElementAt(LinkedList *linkedList, size_t index) {
    if (isEmptyLS(linkedList) || index >= linkedList->size)
        return;

    LinkedListNode *iterator = linkedList->head;
    for (size_t i = 0; i < index - 1; ++i)
        iterator = iterator->nextNode;

    LinkedListNode *nodeToBeDeleted = iterator->nextNode;
    iterator->nextNode = iterator->nextNode->nextNode;

    free(nodeToBeDeleted);
    --linkedList->size;
}

void destroyLinkedList(LinkedList *linkedList) {
    while (!isEmptyLS(linkedList))
        popFront(linkedList);

    free(linkedList);
}
