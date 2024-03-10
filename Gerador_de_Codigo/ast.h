#ifndef _AST_H
#define _AST_H

#include <stdio.h>
#include <stdlib.h>
// #include "sintatico.tab.h"

enum expressionTypes {
    BOP = 1001,
    UOP,
    // LISTA_EXP,
    TERNARY,
    PRIMARIA
};
#define LISTA_EXP_COMANDO 9802

/*
enum yytokentype {                
    MyEOF = 258,                   
    GLOBAL = 259,                  
    VARIABLE = 260,                
    CONSTANT = 261,                
    PARAMETER = 262,               
    VALUE = 263,                   
    RETURN_TYPE = 264,             
    TYPE = 265,                    
    VOID = 266,                    
    INT = 267,                     
    CHAR = 268,                    
    FUNCTION = 269,                
    END_FUNCTION = 270,            
    RETURN = 271,                  
    DO_WHILE = 272,                
    WHILE = 273,                   
    FOR = 274,                     
    IF = 275,                      
    PRINTF = 276,                  
    SCANF = 277,                   
    EXIT = 278,                    
    PLUS = 279,                    
    MINUS = 280,                   
    MULTIPLY = 281,                
    DIVIDE = 282,                  
    REMAINDER = 283,               
    INC = 284,                     
    DEC = 285,                     
    ADD_ASSIGN = 286,              
    MINUS_ASSIGN = 287,            
    ASSIGN = 288,                  
    EQUAL = 289,                   
    NOT_EQUAL = 290,               
    LESS_THAN = 291,               
    LESS_EQUAL = 292,              
    GREATER_THAN = 293,            
    GREATER_EQUAL = 294,           
    BITWISE_AND = 295,             
    BITWISE_OR = 296,              
    BITWISE_XOR = 297,             
    BITWISE_NOT = 298,             
    LOGICAL_AND = 299,             
    LOGICAL_OR = 300,              
    NOT = 301,                     
    TERNARY_CONDITIONAL = 302,     
    COLON = 303,                   
    R_SHIFT = 304,                 
    L_SHIFT = 305,                 
    L_PAREN = 306,                 
    R_PAREN = 307,                 
    L_SQUARE_BRACKET = 308,        
    R_SQUARE_BRACKET = 309,        
    COMMA = 310,                   
    SEMICOLON = 311,              
    NUM_INT = 312,                
    STRING = 313,                 
    CHARACTER = 314,              
    ID = 315                      
  }
*/

typedef struct program {
    void **hashTable;  // declarations
    void *functionsList;
    void *definesExps;
    void *dimensionsExps;
    void *main;  // start of the program, wont be used here
} Program;

typedef struct function {
    void **hashTable;
    void *declarations;
    int returnType;
    int pointer;
    char *name;
    void *commandList;
    void *next;
} Function;

typedef struct dimension {
    int size;
    void *exp;
    struct dimension *next;
} Dimension;

typedef struct expParam {
    int type;
    int pointer;
    void *exp;
    char *identifier;
    struct expParam *next;
} ExpParam;

typedef struct expression {
    int type;
    int pointer;
    int operator;
    int assign;
    Dimension *dimension;
    ExpParam *param;
    void *extra;
    int isHeadOfList;

    struct expression *nextExpr;

    struct expression *ternaryCondition;
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

    // print, scan
    char *string;
    Expression *auxPrint;
    char *identifier;

    int visited;
} Command;

typedef struct resultExpression {
    int typeVar;
    int pointer;
    int assign;
    char str[256];

    int registerType;  // 0 = t, 1 = s
    int registerNumber;

    void *auxIdNode;
} ResultExpression;

Program *createProgram(void **hash, void *functionsList, void *main);

Function *createFunction(void **hash, int returnType, int pointer, char *name, void *commandList, void *next);

ExpParam *createExpParam(Expression *exp, ExpParam *next);

Dimension *createDimension(int size);

int countDimension(void *d);

Dimension *createDimensionWithExp(Expression *exp);

void setDimensionExpression(Expression *expression, Dimension *dimension);

Expression *createExpression(int type, int operator, void *left, void *right);

Command *createIfStatement(Expression *condition, void *then, void *elseStatement, void *next);

Command *createElseStatement(void *then, void *next);

Command *createDoWhileStatement(Expression *condition, void *then, void *next);

Command *createWhileStatement(Expression *condition, void *then, void *next);

Command *createForStatement(Expression *init, Expression *condition, Expression *increment, void *then, void *next);

Command *createPrintStatement(char *string, Expression *auxPrint, void *next);

Command *createScanStatement(char *string, char *identifier, void *next);

Command *createReturnStatement(Expression *expression, void *next);

Command *createExitStatement(Expression *expression, void *next);

Command *createCommandExpression(Expression *expression, void *next);

ResultExpression *createResultExpression(int type, int pointer, int value);

ResultExpression *evalExpression(Expression *expression, void **globalHash, void **localHash, Program *program);

int traverseAST(Program *program);

void freeAST(Program *program);

#endif