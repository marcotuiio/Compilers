#include "list.h"

List *createList() {
    List *l = calloc(1, sizeof(List));
    l->head = NULL;
    l->tail = NULL;
    return l;
}

void insertNode(List *list, int id, int start, int end) {
    Node *n = calloc(1, sizeof(Node));
    list->size++;
    n->id = id;
    n->start = start;
    n->end = end;
    n->lifeSpan = end - start;
    n->next = NULL;
    if (list->head == NULL) {
        list->head = n;
        list->tail = n;
    } else {
        list->tail->next = n;
        list->tail = n;
    }
}

Node *getNode(List *list, int id) {
    Node *curr = list->head;
    while (curr) {
        if (curr->id == id) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void deleteNode(List *list, int id) {
    Node *prev = NULL;
    Node *curr = list->head;
    while (curr) {
        if (curr->id == id) {
            if (prev == NULL) {
                list->head = curr->next;
                if (list->tail == curr) {
                    list->tail = NULL;
                }
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void printList(List *list) {
    Node *curr = list->head;
    printf("size %d | %d\n", list->size, list->availableRegs);

    while (curr) {
        printf("id: %d, start: %d, end: %d, lifeSpan: %d\n", curr->id, curr->start, curr->end, curr->lifeSpan);
        curr = curr->next;
    }
}

void freeList(List *list) {
    Node *curr = list->head;
    while (curr) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
}
