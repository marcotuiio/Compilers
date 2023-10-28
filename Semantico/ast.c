#include "ast.h"

Expression *createExpression(int type, void *aux, void *left, void *right) {
    Expression *newExp = calloc(1, sizeof(Expression));
    newExp->type = type;
    newExp->value = aux;
    newExp->left = left;
    newExp->right = right;
    return newExp;
}

IfStatement *createIfStatement(Expression *condition, void *then, void *elseStatement, void *next) {
    IfStatement *newIf = calloc(1, sizeof(IfStatement));
    newIf->condition = condition;
    newIf->then = then;
    newIf->elseStatement = elseStatement;
    newIf->next = next;
    return newIf;
}

ElseStatement *createElseStatement(void *then, void *next) {
    ElseStatement *newElse = calloc(1, sizeof(ElseStatement));
    newElse->then = then;
    newElse->next = next;
    return newElse;
}

DoWhileStatement *createDoWhileStatement(Expression *condition, void *then, void *next) {
    DoWhileStatement *newDoWhile = calloc(1, sizeof(DoWhileStatement));
    newDoWhile->condition = condition;
    newDoWhile->then = then;
    newDoWhile->next = next;
    return newDoWhile;
}

WhileStatement *createWhileStatement(Expression *condition, void *then, void *next) {
    WhileStatement *newWhile = calloc(1, sizeof(WhileStatement));
    newWhile->condition = condition;
    newWhile->then = then;
    newWhile->next = next;
    return newWhile;
}

ForStatement *createForStatement(Expression *init, Expression *condition, Expression *increment, void *then, void *next) {
    ForStatement *newFor = calloc(1, sizeof(ForStatement));
    newFor->init = init;
    newFor->condition = condition;
    newFor->increment = increment;
    newFor->then = then;
    newFor->next = next;
    return newFor;
}