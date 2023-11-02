#include "hash.h"

void **createHash() {
    void **hashTable = calloc(HASH_SIZE, sizeof(HashNode));
    if (!hashTable) {
        printf("Erro ao alocar memoria para hash\n");
        exit(-1);
    }
    return hashTable;
}

int hash(char *value) {
    int hash = 0;
    for (int i = 0; i < strlen(value); i++)
        hash += value[i] * (i + 1);
    return hash % HASH_SIZE;
}

void insertHash(void **hashTable, char *value, int line, int column, int currentType, int pointer, void *assign, void *dimensions) {
    int index = hash(value);
    HashNode *aux = calloc(1, sizeof(HashNode));
    aux->typeVar = currentType;
    aux->value = calloc(strlen(value) + 1, sizeof(char));
    strcpy(aux->value, value);
    aux->line = line;
    aux->column = column;
    aux->pointer = pointer;
    aux->assign = assign;
    aux->dimensions = dimensions;

    HashNode *head = (HashNode *) hashTable[index];
    if (!head) {
        hashTable[index] = aux;
    } else {
        while (head->next) 
            head = head->next;
        head->next = aux;
    }

}

int lookForValueInHash(void **hashTable, char *value, int line, int column, int currentType, int *textBefore, int *semanticError) {
    if (!hashTable) return 0;
    int index = hash(value);
    int ocorrencias = 0;
    HashNode *head = (HashNode *) hashTable[index];

    while (head) {
        if (!strcmp(value, head->value)) { // existe outro daquele identificador na hash
            ocorrencias++;
            if (ocorrencias == 1) continue;  // se for o primeiro, continua 
            if (currentType == head->typeVar) {  // se for do mesmo tipo
                if (*textBefore) printf("\n");
                printf("%d: identifier '%s' already declared", line, value);
                *semanticError = 1;
                *textBefore = 1;
                return 1;

            } else {  // se for de tipo diferente
                if (*textBefore) printf("\n");
                printf("%d: redefinition of identifier '%s'", line, value);
                *semanticError = 1;
                *textBefore = 1;
                return 1;
            }
        }
        head = head->next;
    }
    return 0;
}

void freeHash(void **hashTable) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *head = hashTable[i];
        while (head) {
            HashNode *aux = head->next;
            if (head->value) 
                free(head->value);
            free(head);
            head = aux;
        }
        hashTable[i] = NULL; 
    }
    free(hashTable);
}