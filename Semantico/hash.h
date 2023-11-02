#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 997

typedef struct node {
    int typeVar;
    int pointer;
    char *identifier;
    char *value;
    int line;
    int column;
    void *assign;
    void *dimensions;
    struct node *next;
} HashNode;

void **createHash();

int hash(char *value);

void insertHash(void **hashTable, char *value, int line, int column, int currentType, int pointer, void *assign, void *dimensions);

int lookForValueInHash(void **hashTable, char *value, int line, int column, int currentType, int *textBefore, int *semanticError);

void freeHash(void **hashTable);

#endif