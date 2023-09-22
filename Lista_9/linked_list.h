#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} nodeList;

typedef struct list {
    nodeList *head;
} listHeader;

void *createList();
void insertNode(listHeader *list, int value);
int removeNode(listHeader *list);
void printList(listHeader *list);
void freeList(listHeader *list);

#endif