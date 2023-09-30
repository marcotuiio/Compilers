#include "linked_list.h"
#include "PORTUGOL_SINTATICO.h"
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

void removeNode(listHeader *list) { // sempre remove do inicio
    if (list->head == NULL) {
        return;
    } else {
        nodeList *aux = list->head;
        list->head = aux->next;
        free(aux);
    }
}

int getNode(listHeader *list) {
    if (list->head == NULL) {
        return -1;
    }
    return list->head->value;
}

void printList(listHeader *list) {
    nodeList *aux = list->head;
    while (aux != NULL) {
        char *callocAux = calloc(30, sizeof(char));
        switchTokens(callocAux, aux->value);
        printf("%s ", callocAux);
        aux = aux->next;
        free(callocAux);
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
