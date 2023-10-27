#ifndef _AST_H
#define _AST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ast {
    int type;
    void *value;
    struct ast *left;
    struct ast *right;
    void *nextCommand;
} AstTreeNode;


AstTreeNode *insertNode(int type, AstTreeNode *left, AstTreeNode *right, void *data, void *next);
void RPNWalk(AstTreeNode *node);
void freeTree(AstTreeNode *node);

#endif