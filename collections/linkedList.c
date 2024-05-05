//
// Created by Omar on 07/12/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../Models/process.h"
#include "../Models/ganttChart.h"
#include "../utils/exceptions.h"

LinkedList *ls_new() {
    LinkedList *linkedList = (LinkedList *) malloc(sizeof(LinkedList));
    ENSURE_ALLOCATED_ELSE_REPORT_ERROR(linkedList, LINKED_LIST_ALLOCATION_MEMORY_ERROR_MESSAGE);

    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->size = 0;

    return linkedList;
}

void ls_pushBack(LinkedList *linkedList, void *data) {
    LinkedListNode *newNode = (LinkedListNode *) malloc(sizeof(LinkedListNode));
    ENSURE_ALLOCATED_ELSE_REPORT_ERROR(newNode, LINKED_LIST_ALLOCATION_MEMORY_ERROR_MESSAGE);

    newNode->data = data;
    newNode->next = NULL;

    if (IS_EMPTY_LS(linkedList))
        linkedList->head = newNode;
    else
        linkedList->tail->next = newNode;

    linkedList->tail = newNode;
    ++linkedList->size;
}

void ls_pushFront(LinkedList *linkedList, void *data) {
    LinkedListNode *newNode = (LinkedListNode *) malloc(sizeof(LinkedListNode));
    ENSURE_ALLOCATED_ELSE_REPORT_ERROR(newNode, LINKED_LIST_ALLOCATION_MEMORY_ERROR_MESSAGE);

    newNode->data = data;
    newNode->next = linkedList->head;

    if (IS_EMPTY_LS(linkedList))
        linkedList->tail = newNode;

    linkedList->head = newNode;
    ++linkedList->size;
}

void ls_popFront(LinkedList *linkedList) {
    if (IS_EMPTY_LS(linkedList))
        THROW_EXCEPTION(EXIT_FAILURE, EMPTY_LINKED_LIST_ERROR_MESSAGE);

    LinkedListNode *nodeToBeDeleted = linkedList->head;
    linkedList->head = linkedList->head->next;

    free(nodeToBeDeleted);
    --linkedList->size;
}

void ls_popBack(LinkedList *linkedList) {
    if (IS_EMPTY_LS(linkedList))
        THROW_EXCEPTION(EXIT_FAILURE, EMPTY_LINKED_LIST_ERROR_MESSAGE);

    LinkedListNode *iterator = linkedList->head;
    while (iterator->next != linkedList->tail)
        iterator = iterator->next;

    free(iterator->next);
    iterator->next = NULL;
    linkedList->tail = iterator;
    --linkedList->size;
}

void *ls_front(LinkedList *linkedList) {
    if (IS_EMPTY_LS(linkedList))
        THROW_EXCEPTION(EXIT_FAILURE, EMPTY_LINKED_LIST_ERROR_MESSAGE);

    return linkedList->head->data;
}

void *ls_back(LinkedList *linkedList) {
    if (IS_EMPTY_LS(linkedList))
        THROW_EXCEPTION(EXIT_FAILURE, EMPTY_LINKED_LIST_ERROR_MESSAGE);

    return linkedList->tail->data;
}

void *ls_getElementAt(LinkedList *ls, size_t index) {
    if (IS_EMPTY_LS(ls))
        THROW_EXCEPTION(EXIT_FAILURE, EMPTY_LINKED_LIST_ERROR_MESSAGE);
    if (index >= ls->size)
        THROW_EXCEPTION(EXIT_FAILURE, OUT_OF_BOUNDS_ERROR_MESSAGE);

    if (index == ls->size - 1) return ls_back(ls);

    LinkedListNode *iter = ls->head;
    for (size_t i = 0; i < index; ++i)
        iter = iter->next;

    return iter->data;
}

void ls_removeElementAt(LinkedList *ls, size_t index) {
    if (IS_EMPTY_LS(ls))
        THROW_EXCEPTION(EXIT_FAILURE, EMPTY_LINKED_LIST_ERROR_MESSAGE);
    if (index >= ls->size)
        THROW_EXCEPTION(EXIT_FAILURE, OUT_OF_BOUNDS_ERROR_MESSAGE);

    LinkedListNode *iter = ls->head;
    for (size_t i = 0; i < index - 1; ++i)
        iter = iter->next;

    LinkedListNode *nodeToBeDeleted = iter->next;
    iter->next = iter->next->next;

    free(nodeToBeDeleted);
    --ls->size;
}

void ls_destroy(LinkedList *ls) {
    while (!IS_EMPTY_LS(ls))
        ls_popFront(ls);

    free(ls);
}
