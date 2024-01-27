#include "hash.h"
#include "sintatico.tab.h"

void **createHash() {
    void **hashTable = calloc(HASH_SIZE, sizeof(HashNode));
    if (!hashTable) {
        printf("Erro ao alocar memoria para hash\n");
        exit(1);
    }
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
            if (head->typeVar == NUM_INT) {
                strcpy(type, "INT");
            } else if (head->typeVar == NUM_FLOAT){
                strcpy(type, "FLOAT");
            } else if (head->typeVar == MATRIX) {
                strcpy(type, "MATRIX[][]");
            }
            printf("\n%s - %s", head->varId);
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
            free(head);
            head = aux;
        }
        hashTable[i] = NULL;
    }
    free(hashTable);
    hashTable = NULL;
}