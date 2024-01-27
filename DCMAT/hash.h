#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 221

typedef struct node {
    int typeVar;
    char *varId;
    void *dimensions;
    int qntdDimen;
    struct node *next;
} HashNode;

void **createHash();
int hash(char *value);
void *insertHash(void **hashTable, char *varId, int currentType);
HashNode *getIdentifierNode(void **hashTable, char *id);
void freeHash(void **hashTable);

#endif