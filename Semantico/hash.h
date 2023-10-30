#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 997

typedef struct node {
    int key;
    char *value;
    struct node *next;
} HashNode;

int hash(char *value);

void insertHash(void **hashTable, char *value, int currentType);

int lookForValueInHash(void **hashTable, char *value, int line, int column, int currentType, int *textBefore, int *semanticError);

void freeHash(void **hashTable);

#endif