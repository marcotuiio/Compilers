#ifndef _AST_H
#define _AST_H

#include <stdio.h>
#include <stdlib.h>
#include <sintatico.tab.h>

typedef struct expression {
    int type;
    void *value;
    struct expression *left;
    struct expression *right;
} Expression;

typedef struct ifStatement {
    Expression *condition;
    void *then;
    void *elseStatement;
    void *next;
} IfStatement;

typedef struct elseStatement {
    void *then;
    void *next;
} ElseStatement;

typedef struct doWhileStatement {
    Expression *condition;
    void *then;
    void *next;
} DoWhileStatement;

typedef struct whileStatement {
    Expression *condition;
    void *then;
    void *next;
} WhileStatement;

typedef struct forStatement {
    Expression *init;
    Expression *condition;
    Expression *increment;
    void *then;
    void *next;
} ForStatement;

Expression *createExpression(int type, void *aux, void *left, void *right);

IfStatement *createIfStatement(Expression *condition, void *then, void *elseStatement, void *next);

ElseStatement *createElseStatement(void *then, void *next);

DoWhileStatement *createDoWhileStatement(Expression *condition, void *then, void *next);

WhileStatement *createWhileStatement(Expression *condition, void *then, void *next);

ForStatement *createForStatement(Expression *init, Expression *condition, Expression *increment, void *then, void *next);

#endif