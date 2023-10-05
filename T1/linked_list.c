#include "linked_list.h"
#include "PORTUGOL_SINTATICO.h"

void *createList() {
    listHeader *l = calloc(1, sizeof(listHeader));
    return l;
}

void insertNode(listHeader *list, int value, int line, int column, char *token) { // sempre insere no final
    nodeList *node = calloc(1, sizeof(nodeList));
    node->value = value;
    node->line = line;
    node->column = column;

    if (value != 19 && token[0] == '/') token++;
    node->token = calloc(strlen(token) + 1, sizeof(char));
    strcpy(node->token, token);

    // printf("value: %d line: %d column: %d\n", value, line, column);
    if (!list->head) {
        list->head = node;
        
    } else {
        nodeList *aux = list->head;
        while (aux->next) {
            aux = aux->next;
        }
        aux->next = node;
    }
}

void removeNode(listHeader *list) { // sempre remove do inicio
    if (!list->head) {
        return;
    } else {
        nodeList *aux = list->head;
        list->head = aux->next;
        if (aux->token) free(aux->token);
        free(aux);
    }
}

int getNode(listHeader *list) {
    if (!list->head) return -1;
    return list->head->value;
}

int getLine(listHeader *list) {
    if (!list->head) return -1;
    return list->head->line;
}

int getColumn(listHeader *list) {
    if (!list->head) return -1;
    return list->head->column;
}

char *getTokenContent(listHeader *list) {
    if (!list->head) return NULL;
    return list->head->token;
}

void printList(listHeader *list) {
    nodeList *aux = list->head;
    while (aux != NULL) {
        // defineID(&aux->value);
        printf("%d ", aux->value);
        // printf("%s %d\n", aux->token, aux->value);
        // char *callocAux = calloc(30, sizeof(char));
        // switchTokens(callocAux, aux->value);
        // printf("%s ", callocAux);
        aux = aux->next;
        // free(callocAux);
    }
    printf("\n");
}

void freeList(listHeader *list) {
    nodeList *aux = list->head;
    while (aux != NULL) {
        nodeList *aux2 = aux->next;
        if (aux) {
            if (aux->token) free(aux->token);
            free(aux);
        }
        aux = aux2;
    }
    if (list) free(list);
}
