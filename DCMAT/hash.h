#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 221
#define MAX_MATRIX_SIZE 10
#define DECOY 999999.0

typedef struct node {
    int typeVar;
    char *varId;
    float valueId;
    int lineMatrix;
    int columnMatrix;
    float **matrix;
    struct node *next;
} HashNode;

void **createHash();

int hash(char *value);

HashNode *lookForValueInHash(void **hashTable, char *value);

void *insertHash(void **hashTable, char *varId, float valueId, int currentType);

float **createMatrix();

void fixMatrix(float **m, int line, int column);

void showMatrix(float **m, int line, int column, int floatPrecision);

void freeMatrix(float **m);

HashNode *getIdentifierNode(void **hashTable, char *id);

void showSymbols(void **hashTable);

void removeNode(void **hashTable, char *id);

void freeHash(void **hashTable);

#endif