#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    void *top;
    int size;
} Stack;

typedef struct node {
    void *data;
    struct node *below;
} Node;

void *createStack();
void push(void *stack, void *data);
void *pop(void *stack);
void *peek(void *stack);
void printStack(void *stack);
void freeStack(void *stack);

#endif