#ifndef _AST_H
#define _AST_H

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <math.h>

enum expressionTypes {
    ADITIVA = 1001,
    MULTIPLICATIVA,
    UNARIA,
    PRIMARIA
};

typedef struct expression {
    int type;
    int operator;
    char *e_string;
    struct expression *left;
    struct expression *right;
} Expression;

typedef struct resultExpression {
    int type;
    float r_float;
    char *r_string;
} ResultExpression;

typedef struct function {
    int type;
    Expression *expression;
} Function;

Expression *createExpression(int type, int op, char *s, Expression *left, Expression *right);

ResultExpression *createResultExpression(int type, float r_float, char *r_string);

Function *createFunction(int type, Expression *expression);

ResultExpression *evalExpression(Expression *expr, void **hash);

ResultExpression *evalFunction(Function *func, void **hash);

#endif