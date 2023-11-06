#ifndef _AST_H
#define _AST_H

#include <stdio.h>
#include <stdlib.h>
// #include "sintatico.tab.h"

enum expressionTypes {
    ATRIBUICAO = 1001,
    NAOSEI,
    TERNARY,
    OR_LOGICO,
    AND_LOGICO,
    OR_BIT,
    XOR_BIT,
    AND_BIT,
    IGUALDADE,
    RELACIONAL,
    SHIFT,
    ADITIVIVA,
    MULTIPLICATIVA,
    CASTING,
    UNARIA,
    POS_FIXA,
    PRIMARIA,
    NUMEROS
};

typedef struct program {
    void **hashTable;  // declarations
    void *functionsList;
    void *main;  // start of the program, wont be used here
} Program;

typedef struct function {
    void **hashTable;
    int returnType;
    int pointer;
    char *name;
    void *commandList;
    void *next;
} Function;

typedef struct expression {
    int type;
    int pointer;
    int operator;
    void *value;
    int preIncrement;
    int posIncrement;
    int unario;
    int assign;
    struct expression *dimension;
    void *next;
    void *extra;

    struct expression *ternary;
    struct expression *left;
    struct expression *right;
} Expression;

typedef struct dimension {
    Expression *size;
    struct dimension *next;
} Dimension;

typedef struct command {
    // generic
    // while, do while, for, if, if else, print, scan, return, exit
    // most of them have a condition, a execution and a next
    int type;
    Expression *condition; 
    void *then;
    void *next;
    
    // if else
    void *elseStatement;

    // for
    Expression *init;
    Expression *increment;

    // print
    char *string;
    Expression *auxPrint;

    // scan
    char *identifier;
    char *format;
} Command;

Program *createProgram(void **hash, void *functionsList, void *main);

Function *createFunction(void **hash, int returnType, int pointer, char *name, void *commandList, void *next);

Expression *createExpression(int type, int operator, void *aux, void *left, void *right);

Dimension *createDimension(Expression *size);

Command *createIfStatement(Expression *condition, void *then, void *elseStatement, void *next);

Command *createElseStatement(void *then, void *next);

Command *createDoWhileStatement(Expression *condition, void *then, void *next);

Command *createWhileStatement(Expression *condition, void *then, void *next);

Command *createForStatement(Expression *init, Expression *condition, Expression *increment, void *then, void *next);

Command *createPrintStatement(char *string, Expression *auxPrint, void *next);

Command *createScanStatement(char *identifier, char *format, void *next);

Command *createReturnStatement(Expression *expression, void *next);

Command *createExitStatement(Expression *expression, void *next);

Command *createCommandExpression(Expression *expression, void *next);

void evalExpression(void *node, void *expression);

int traverseAST(Program *program);

void freeAST(Program *program);

#endif