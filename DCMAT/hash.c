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

HashNode *lookForValueInHash(void **hashTable, char *value) {
    if (!hashTable) return 0;
    int index = hash(value);
    HashNode *head = (HashNode *)hashTable[index];
    while (head) {
        if (!strcmp(value, head->varId)) return head;
        head = head->next;
    }
    return NULL;
}

void *insertHash(void **hashTable, char *varId, float valueId, int currentType) {
    if (!hashTable) return NULL;
    
    HashNode *aux = lookForValueInHash(hashTable, varId);
    if (aux) {
        aux->typeVar = currentType;
        aux->valueId = valueId;
        strcpy(aux->varId, varId);
        return aux;
    }

    int index = hash(varId);
    aux = calloc(1, sizeof(HashNode));
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
            if (!strcmp(head->varId, "x")) {
                head = head->next;
                continue;
            }
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