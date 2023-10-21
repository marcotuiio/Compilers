#ifndef _TREE_H
#define _TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int tokenType;
    void *value;
    struct node *left;
    struct node *right;
} Node;

void traverseTree(Node *root);
void freeTree(Node *root);

#endif