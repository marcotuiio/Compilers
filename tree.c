#include "tree.h"
#include <sintatico.tab.h>

void traverseTree(Node *root) {
    if (!root) return;

    traverseTree(root->left);
    traverseTree(root->right);

    switch(root->tokenType) {
        case EOF:
            printf("EOF\n");
            break;
        case ADD:
            printf("+ \n");
            break;
        case SUB:
            printf("- \n");
            break;
        case MUL:
            printf("* \n");
            break;
        case DIV:
            printf("/ \n");
            break;
        case POW:
            printf("^ \n");
            break;
        case MOD:
            printf("%% \n");
            break;
        case L_PAREN:
            printf("( \n");
            break;
        case R_PAREN:
            printf(") \n");
            break;
        case SEN:
            printf("sen \n");
            break;
        case COS:
            printf("cos \n");
            break;
        case TAN:
            printf("tan \n");
            break;
        case ABS:
            printf("abs \n");
            break;
        case ID:
            printf("ID: %s\n", (char *)root->value);
            break;
        case REAL:
            printf("REAL: %s\n", (char *)root->value);
            break;
        case INT:
            printf("INT: %s\n", (char *)root->value);
            break;
    }
}

void freeTree(Node *root) {
    if (!root) return;

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}
