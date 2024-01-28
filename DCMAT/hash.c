#include "hash.h"

int NUM_INT = 306;
int NUM_FLOAT = 307;
int MATRIX = 286;

void **createHash() {
    void **hashTable = calloc(HASH_SIZE, sizeof(HashNode));
    if (!hashTable) {
        printf("Erro ao alocar memoria para hash\n");
        exit(1);
    }
    insertHash(hashTable, "x", 0, 304);
    return hashTable;
}

int hash(char *value) {
    int hash = 0;
    for (int i = 0; i < strlen(value); i++)
        hash += value[i] * (i + 1);
    return hash % HASH_SIZE;
}

void *insertHash(void **hashTable, char *varId, float valueId, int currentType) {
    int index = hash(varId);
    HashNode *aux = calloc(1, sizeof(HashNode));
    aux->typeVar = currentType;
    aux->varId = calloc(strlen(varId) + 1, sizeof(char));
    strcpy(aux->varId, varId);
    aux->valueId = valueId;

    HashNode *head = (HashNode *)hashTable[index];
    if (!head) {
        hashTable[index] = aux;
    } else {
        while (head->next)
            head = head->next;
        head->next = aux;
    }
    return aux;
}

void fixVarXHash(void **hashTable, float valueId) {
    if (!hashTable) return;
    int index = hash("x");

    HashNode *head = (HashNode *)hashTable[index];
    if (head) {
        while (strcmp(head->varId, "x") && head->next)
            head = head->next;

        if (head && !strcmp(head->varId, "x")) {
            head->valueId = valueId;
        }
    }
}

HashNode *getIdentifierNode(void **hashTable, char *id) {
    if (!hashTable) return NULL;
    int index = hash(id);
    HashNode *head = (HashNode *)hashTable[index];
    while (head) {
        // printf("head->value: %s %d\n", head->value, head->typeVar);
        if (!strcmp(id, head->varId)) return head;
        head = head->next;
    }
    return NULL;
}

void showSymbols(void **hashTable) {
    if (!hashTable) return;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (!hashTable[i]) continue;
        HashNode *head = hashTable[i];
        while (head) {
            char type[30];
            if (head->typeVar == NUM_FLOAT || head->typeVar == NUM_INT) {
                strcpy(type, "FLOAT");
            } else if (head->typeVar == MATRIX) {
                strcpy(type, "MATRIX[][]");
            }
            printf("\n%s - %s", head->varId, type);
            head = head->next;
        }
    }
    printf("\n\n");
}

void freeHash(void **hashTable) {
    if (!hashTable) return;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (!hashTable[i]) continue;
        HashNode *head = hashTable[i];
        while (head) {
            HashNode *aux = head->next;
            if (head->varId) free(head->varId);
            head->varId = NULL;
            if (head) free(head);
            head = aux;
        }
        hashTable[i] = NULL;
    }
    
    free(hashTable);
    hashTable = NULL;
}