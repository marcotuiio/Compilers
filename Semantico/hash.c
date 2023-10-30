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
        hash += value[i];
    return hash % HASH_SIZE;
}

void insertHash(void **hashTable, char *value, int currentType) {
    int index = hash(value);
    HashNode *aux = calloc(1, sizeof(HashNode));
    aux->key = currentType;
    aux->value = calloc(strlen(value) + 1, sizeof(char));
    strcpy(aux->value, value);

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
            if (currentType == head->key) {  // se for do mesmo tipo
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