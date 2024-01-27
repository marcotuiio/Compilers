#ifndef _AST_H
#define _AST_H

#include <stdio.h>
#include <stdlib.h>

enum expressionTypes {
    ADITIVA = 1001,
    MULTIPLICATIVA,
    UNARIA,
    PRIMARIA
};

typedef struct expression {
    int type;
    int e_int;    
    float e_float;
    char *e_string;
    struct expression *left;
    struct expression *right;
} Expression;

typedef struct resultExpression {
    int type;
    int r_int;
    float r_float;
    char *r_string;
} ResultExpression;

Expression *createExpression(int type, int i, float f, char *s, Expression *left, Expression *right);

#endif