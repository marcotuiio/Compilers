#ifndef _AST_H
#define _AST_H

#include <stdio.h>
#include <stdlib.h>
#include "sintatico.tab.h"

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
    void *parameters;
    void *declarations;
    void *commandList;
    void *next;
} Function;

typedef struct expression {
    int type;
    void *value;
    void *extra;
    struct expression *left;
    struct expression *right;
} Expression;

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

Function *createFunction(void **hash, int returnType, int pointer, char *name, void *parameters, void *declarations, void *commandList, void *next);

Expression *createExpression(int type, void *aux, void *left, void *right);

Command *createIfStatement(Expression *condition, void *then, void *elseStatement, void *next);

Command *createElseStatement(void *then, void *next);

Command *createDoWhileStatement(Expression *condition, void *then, void *next);

Command *createWhileStatement(Expression *condition, void *then, void *next);

Command *createForStatement(Expression *init, Expression *condition, Expression *increment, void *then, void *next);

Command *createPrintStatement(char *string, Expression *auxPrint, void *next);

Command *createScanStatement(char *identifier, char *format, void *next);

Command *createReturnStatement(Expression *expression, void *next);

Command *createExitStatement(Expression *expression, void *next);

#endif