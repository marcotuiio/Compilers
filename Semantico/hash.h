#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 997

typedef struct node {
    int typeVar;
    int pointer;
    char *varId;
    int assign;
    int isConstant;
    int line;
    int column;
    void *dimensions;
    void *param;
    int prototype;
    int qntdParams;
    struct node *next;
} HashNode;

typedef struct param {
    int type;
    int pointer;
    int line;
    int column;
    char *identifier;
    struct param *next;
} Param;

void **createHash();

int hash(char *value);

void *insertHash(void **hashTable, char *varId, int line, int column, int currentType, int pointer);
void setIsConstant(void *node);
void setPrototype(void *node);
void setQntdParams(void *node, int qntdParams);
void setParam(void *node, Param *p);
void setAssign(void *node, int assign);
void setDimensions(void *node, void *dimensions);

int lookForValueInHash(void **hashTable, char *varId, int line, int column, int currentType, int *textBefore, int *semanticError);

Param *createParam(int type, char *identifier, int pointer, int line, int column, void *next);

int lookForPrototypeInHash(void **hashTable, char *varId, int line, int column, int currentType, Param *p, int qntdParam, int *textBefore, int *semanticError);

HashNode *getIdentifierNode(void **hashTable, char *id);
char *getExactType(int type, int pointer);

void freeHash(void **hashTable);

#endif