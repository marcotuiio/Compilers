#include "ast.h"

#include "sintatico.tab.h"

Expression *createExpression(int type, int i, float f, char *s, Expression *left, Expression *right) {
    Expression *e = calloc(1, sizeof(Expression));
    e->type = type;
    e->e_int = i;
    e->e_float = f;
    e->e_string = s;
    e->left = left;
    e->right = right;
    return e;
}