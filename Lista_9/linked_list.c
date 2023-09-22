#include "linked_list.h"

void *createList() {
    listHeader *l = calloc(1, sizeof(listHeader));
    return l;
}

void insertNode(listHeader *list, int value) { // sempre insere no final
    nodeList *node = calloc(1, sizeof(nodeList));
    node->value = value;

    if (list->head == NULL) {
        list->head = node;
        
    } else {
        nodeList *aux = list->head;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = node;
    }
}

int removeNode(listHeader *list) { // sempre remove do inicio
    if (list->head == NULL) {
        return -1;
    } else {
        nodeList *aux = list->head;
        list->head = aux->next;
        int v = aux->value;
        free(aux);
        return v;
    }
}

void printList(listHeader *list) {
    nodeList *aux = list->head;
    while (aux != NULL) {
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void freeList(listHeader *list) {
    nodeList *aux = list->head;
    while (aux != NULL) {
        nodeList *aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
    free(list);
}
