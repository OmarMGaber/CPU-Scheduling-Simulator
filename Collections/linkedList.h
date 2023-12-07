//
// Created by Omar on 07/12/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_LINKEDLIST_H
#define CPU_SCHEDULING_SIMULATOR_LINKEDLIST_H

#include <stdlib.h>
#include <string.h>
#include "../utilities.h"

#define LINKED_LIST_ALLOCATION_MEMORY_ERROR_MESSAGE "Failed to allocate memory for Linked List."

#define isEmptyLS(linkedList) (linkedList->size == 0)

typedef struct LinkedListNode {
    void *data;
    struct LinkedListNode *nextNode;
} LinkedListNode;

typedef struct {
    LinkedListNode *head;
    LinkedListNode *tail;
    size_t size;
} LinkedList;

LinkedList *createLinkedList();

void pushBack(LinkedList *linkedList, void *data);

void pushFront(LinkedList *linkedList, void *data);

void popBack(LinkedList *linkedList);

void popFront(LinkedList *linkedList);

void *front(LinkedList *linkedList);

void *back(LinkedList *linkedList);

void *getElementAt(LinkedList *linkedList, size_t index);

void removeElementAt(LinkedList *linkedList, size_t index);

void destroyLinkedList(LinkedList *linkedList);

#endif //CPU_SCHEDULING_SIMULATOR_LINKEDLIST_H
