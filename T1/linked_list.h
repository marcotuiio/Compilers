#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Very simple linked list implementation
// It's not a generic implementation, it's only for integers

typedef struct node {
    int value;
    int line;
    int column;
    struct node *next;
} nodeList;

typedef struct list {
    nodeList *head;
} listHeader;

// Returns a pointer to a listHeader
void *createList();

// Just inserts at the end of the list
void insertNode(listHeader *list, int value, int line, int column);

// Just removes the first node
void removeNode(listHeader *list);

// Returns the value of the first node, -1 if the list is empty
int getNode(listHeader *list);

// Returns the line of the first node, -1 if the list is empty
int getLine(listHeader *list);

// Returns the column of the first node, -1 if the list is empty
int getColumn(listHeader *list);

// Prints all values of the list
void printList(listHeader *list);

// Frees all memory allocated for the list and the nodes
void freeList(listHeader *list);

#endif