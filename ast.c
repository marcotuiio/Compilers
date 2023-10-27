#include "ast.h"
#include <sintatico.tab.h>

AstTreeNode *insertNode(int type, AstTreeNode *left, AstTreeNode *right, void *data, void *next) {
    AstTreeNode *node = calloc(1, sizeof(AstTreeNode));
    node->type = type;
    node->left = left;
    node->right = right;
    node->value = data;
    node->nextCommand = next;
    return node;
}

void RPNWalk(AstTreeNode *node) {
    if (!node) return;

    RPNWalk(node->left);
    RPNWalk(node->right);

    switch(node->type) {
        case INT:
            printf("%s ", (char*)node->value);
            break;
        case FLOAT:
            printf("%s ", (char*)node->value);
            break;
        case CHAR:
            printf("%s ", (char*)node->value);
            break;
        case NUM_INT:
            printf("%d ", *(int *)node->value);
            break;
        case NUM_FLOAT:
            printf("%f ", *(float *)node->value);
            break;
        case CHARACTER:
            printf("%c ", *(char *)node->value);
            break;
        case ID:
            printf("%s ", (char*)node->value);
            break;
        default:
            printf("Default\n");
            break;
    }
}

void freeTree(AstTreeNode *node) {
    if (!node) return;

    freeTree(node->left);
    freeTree(node->right);

    if (node->value) free(node->value);
    if (node->nextCommand) free(node->nextCommand);
    if (node) free(node);
}
