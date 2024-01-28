#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 221

typedef struct node {
    int typeVar;
    char *varId;
    float valueId;
    void *dimensions;
    int qntdDimen;
    struct node *next;
} HashNode;

void **createHash();

int hash(char *value);

HashNode *lookForValueInHash(void **hashTable, char *value);

void *insertHash(void **hashTable, char *varId, float valueId, int currentType);

HashNode *getIdentifierNode(void **hashTable, char *id);

void showSymbols(void **hashTable);

void freeHash(void **hashTable);

#endif