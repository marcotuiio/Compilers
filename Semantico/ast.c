#include "ast.h"

Programa *createPrograma(void *declarations, void *functionsList, void *main) {
    Programa *newProg = calloc(1, sizeof(Programa));
    newProg->declarations = declarations;
    newProg->functionsList = functionsList;
    newProg->main = main;
    return newProg;
}

Function *createFunction(int returnType, char *name, void *parameters, void *declarations, void *commandList, void *next) {
    Function *newFunc = calloc(1, sizeof(Function));
    newFunc->returnType = returnType;
    newFunc->name = name;
    newFunc->parameters = parameters;
    newFunc->declarations = declarations;
    newFunc->commandList = commandList;
    newFunc->next = next;
    return newFunc;
}

Expression *createExpression(int type, void *aux, void *left, void *right) {
    Expression *newExp = calloc(1, sizeof(Expression));
    newExp->type = type;
    newExp->value = aux;
    newExp->left = left;
    newExp->right = right;
    return newExp;
}

Command *createIfStatement(Expression *condition, void *then, void *elseStatement, void *next) {
    Command *newIf = calloc(1, sizeof(Command));
    newIf->condition = condition;
    newIf->then = then;
    newIf->elseStatement = elseStatement;
    newIf->next = next;
    return newIf;
}

Command *createElseStatement(void *then, void *next) {
    Command *newElse = calloc(1, sizeof(Command));
    newElse->then = then;
    newElse->next = next;
    return newElse;
}

Command *createDoWhileStatement(Expression *condition, void *then, void *next) {
    Command *newDoWhile = calloc(1, sizeof(Command));
    newDoWhile->condition = condition;
    newDoWhile->then = then;
    newDoWhile->next = next;
    return newDoWhile;
}

Command *createWhileStatement(Expression *condition, void *then, void *next) {
    Command *newWhile = calloc(1, sizeof(Command));
    newWhile->condition = condition;
    newWhile->then = then;
    newWhile->next = next;
    return newWhile;
}

Command *createForStatement(Expression *init, Expression *condition, Expression *increment, void *then, void *next) {
    Command *newFor = calloc(1, sizeof(Command));
    newFor->init = init;
    newFor->condition = condition;
    newFor->increment = increment;
    newFor->then = then;
    newFor->next = next;
    return newFor;
}

Command *createPrintStatement(char *string, Expression *auxPrint, void *next) {
    Command *newPrint = calloc(1, sizeof(Command));
    newPrint->string = string;
    newPrint->auxPrint = auxPrint;
    newPrint->next = next;
    return newPrint;
}

Command *createScanStatement(char *identifier, char *format, void *next) {
    Command *newScan = calloc(1, sizeof(Command));
    newScan->identifier = identifier;
    newScan->format = format;
    newScan->next = next;
    return newScan;
}

Command *createReturnStatement(Expression *expression, void *next) {
    Command *newReturn = calloc(1, sizeof(Command));
    newReturn->condition = expression;
    newReturn->next = next;
    return newReturn;
}

Command *createExitStatement(Expression *expression, void *next) {
    Command *newExit = calloc(1, sizeof(Command));
    newExit->condition = expression;
    newExit->next = next;
    return newExit;
}
