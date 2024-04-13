#include "stack.h"
#include "graph.h"

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
        printf("%d -> ", ((Vertex *)aux->data)->node);
        Edge *edge = ((Vertex *)aux->data)->edgeList;
        while (edge) {
            printf("%d : ", edge->destiny);
            edge = edge->next;
        }
        printf("\n");
        aux = aux->below;
    }
}

void freeStack(void *stack) {
    if (!stack) return;

    Stack *s = stack;
    Node *aux = s->top;
    while (aux) {
        Node *tmp = aux;
        aux = aux->below;
        if (tmp->data) free(tmp->data);
        free(tmp);
    }
    free(s);
}