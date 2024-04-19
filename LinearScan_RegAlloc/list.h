#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    struct listNode *next;
    int id;
    int start;
    int end;
    int lifeSpan;
    int assignedReg;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
    int availableRegs;
} List;

List *createList();
void insertNode(List *list, int id, int start, int end);
void deleteNode(List *list, int id);
void printList(List *list);
void freeList(List *list);

#endif