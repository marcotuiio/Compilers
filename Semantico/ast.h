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

// enum tokens {
//     YYEMPTY = -2,
//     YYEOF = 0,
//     YYerror = 256,
//     YYUNDEF = 257,
//     MyEOF = 258,
//     ERRO = 259,
//     NUMBER_SIGN = 260,
//     DEFINE = 261,
//     L_CURLY_BRACKET = 262,
//     R_CURLY_BRACKET = 263,
//     L_PAREN = 264,
//     R_PAREN = 265,
//     L_SQUARE_BRACKET = 266,
//     R_SQUARE_BRACKET = 267,
//     COMMA = 268,
//     SEMICOLON = 269,
//     PLUS = 270,
//     MINUS = 271,
//     MULTIPLY = 272,
//     DIVIDE = 273,
//     REMAINDER = 274,
//     INT = 275,
//     CHAR = 276,
//     VOID = 277,
//     DO = 278,
//     WHILE = 279,
//     IF = 280,
//     ELSE = 281,
//     FOR = 282,
//     PRINTF = 283,
//     SCANF = 284,
//     RETURN = 285,
//     EXIT = 286,
//     ADD_ASSIGN = 287,
//     MINUS_ASSIGN = 288,
//     ASSIGN = 289,
//     EQUAL = 290,
//     NOT_EQUAL = 291,
//     LESS_THAN = 292,
//     LESS_EQUAL = 293,
//     GREATER_THAN = 294,
//     GREATER_EQUAL = 295,
//     BITWISE_AND = 296,
//     BITWISE_OR = 297,
//     BITWISE_XOR = 298,
//     BITWISE_NOT = 299,
//     LOGICAL_AND = 300,
//     LOGICAL_OR = 301,
//     NOT = 302,
//     TERNARY_CONDITIONAL = 303,
//     COLON = 304,
//     R_SHIFT = 305,
//     L_SHIFT = 306,
//     INC = 307,
//     DEC = 308,
//     NUM_INT = 309,
//     NUM_HEXA = 310,
//     NUM_OCTAL = 311,
//     STRING = 312,
//     CHARACTER = 313,
//     ID = 314
// };

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

Expression *createExpression(int type, int operator, void * aux, void *left, void *right);

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