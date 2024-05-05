//
// Created by Omar on 07/12/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_LINKEDLIST_H
#define CPU_SCHEDULING_SIMULATOR_LINKEDLIST_H

#include <stdlib.h>
#include <string.h>

#define LINKED_LIST_ALLOCATION_MEMORY_ERROR_MESSAGE "Failed to allocate memory for Linked List."
#define EMPTY_LINKED_LIST_ERROR_MESSAGE "Linked List is empty."

#define IS_EMPTY_LS(linkedList) (linkedList->size == 0)

typedef struct LinkedListNode {
    void *data;
    struct LinkedListNode *next;
} LinkedListNode;

typedef struct {
    LinkedListNode *head;
    LinkedListNode *tail;
    size_t size;
} LinkedList;

LinkedList *ls_new();

void ls_pushBack(LinkedList *linkedList, void *data);

void ls_pushFront(LinkedList *linkedList, void *data);

void ls_popBack(LinkedList *linkedList);

void ls_popFront(LinkedList *linkedList);

void *ls_front(LinkedList *linkedList);

void *ls_back(LinkedList *linkedList);

void *ls_getElementAt(LinkedList *ls, size_t index);

void ls_removeElementAt(LinkedList *ls, size_t index);

void ls_destroy(LinkedList *ls);

#endif //CPU_SCHEDULING_SIMULATOR_LINKEDLIST_H
