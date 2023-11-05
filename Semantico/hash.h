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
    void *param;
    int prototype;
    struct node *next;
} HashNode;

typedef struct param {
    int type;
    int pointer;
    char *identifier;
    struct param *next;
} Param;

void **createHash();

int hash(char *value);

void insertHash(void **hashTable, char *value, int line, int column, int currentType, int pointer, Param *p, int prototype, void *assign, void *dimensions);

int lookForValueInHash(void **hashTable, char *value, int line, int column, int currentType, int *textBefore, int *semanticError);

Param *createParam(int type, char *identifier, int pointer, void *next);

int lookForPrototypeInHash(void **hashTable, char *value, int line, int column, int currentType, Param *p, int *textBefore, int *semanticError);

void freeHash(void **hashTable);

#endif