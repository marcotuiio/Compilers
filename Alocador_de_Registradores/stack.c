#include "stack.h"

void *createStack() {
    Stack *stack = calloc(1, sizeof(Stack));
    return stack;
}

void push(void *stack, void *data) {
    if (!stack) return;

    Stack *s = stack;
    Node *n = calloc(1, sizeof(Node));
    n->data = data;
    s->size++;  

    if (!s->top) {
        s->top = n;
    
    } else {
        n->below = s->top;
        s->top = n;
    }
}

void *pop(void *stack) {
    if (!stack) return NULL;

    Stack *s = stack;
    if (!s->top) return NULL;

    Node *n = s->top;
    s->top = n->below;
    s->size--;
    return n;
}

void *peek(void *stack) {
    if (!stack) return NULL;

    Stack *s = stack;
    if (!s->top) return NULL;

    return s->top;
}

void printStack(void *stack) {
    if (!stack) return;

    Stack *s = stack;
    Node *aux = s->top;
    while (aux) {
        printf("%p\n", aux->data);
        aux = aux->below;
    }
}