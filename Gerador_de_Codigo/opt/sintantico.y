%{
#include "asm.h"
#include "ast.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

extern int yylex();
void yyerror(void *s);

void *prototypeParam = NULL;

void **globalHash = NULL;
void **currentHash = NULL;

Program *AST = NULL;
FILE *mipsFile = NULL;
char *mipsPath = NULL;

%}

%union {
    Program *prog;
    Function *func;
    Dimension *dim;
    Expression *expr;
    Command *cmd;
    void *param;
    void *paramExp;
    int ptr;
    struct {
        char *valor;
        int type;
    } token;
}

%token <token> MyEOF
%token <token> GLOBAL
%token <token> VARIABLE
%token <token> CONSTANT
%token <token> VALUE
%token <token> RETURN_TYPE
%token <token> TYPE
%token <token> VOID
%token <token> INT
%token <token> CHAR
%token <token> FUNCTION
%token <token> END_FUNCTION
%token <token> RETURN
%token <token> DO_WHILE
%token <token> WHILE
%token <token> FOR
%token <token> IF
%token <token> PRINTF
%token <token> SCANF
%token <token> EXIT

%token <token> PLUS
%token <token> MINUS
%token <token> MULTIPLY
%token <token> DIVIDE
%token <token> REMAINDER
%token <token> INC
%token <token> DEC
%token <token> ADD_ASSIGN
%token <token> MINUS_ASSIGN
%token <token> ASSIGN
%token <token> EQUAL
%token <token> NOT_EQUAL
%token <token> LESS_THAN
%token <token> LESS_EQUAL
%token <token> GREATER_THAN
%token <token> GREATER_EQUAL
%token <token> BITWISE_AND
%token <token> BITWISE_OR
%token <token> BITWISE_XOR
%token <token> BITWISE_NOT
%token <token> LOGICAL_AND
%token <token> LOGICAL_OR
%token <token> NOT
%token <token> TERNARY_CONDITIONAL
%token <token> COLON
%token <token> R_SHIFT
%token <token> L_SHIFT

%token <token> L_PAREN
%token <token> R_PAREN
%token <token> L_SQUARE_BRACKET
%token <token> R_SQUARE_BRACKET
%token <token> COMMA
%token <token> SEMICOLON

%token <token> NUM_INT
%token <token> STRING
%token <token> CHARACTER
%token <token> ID

%start Start

%%

Start: AstParse MyEOF {
    return 0;
} ;

AstParse: { 
        void **hash = createHash();
        globalHash = hash;
    }
    DeclaracoesGlobais Funcoes { } ;

DeclaracoesGlobais: CONSTANT ID VALUE COLON NUM_INT { }
    | GLOBAL VARIABLE ID TYPE COLON VarType ArrayCheck { } 
    | { } ;

ArrayCheck: L_SQUARE_BRACKET NUM_INT R_SQUARE_BRACKET ArrayCheck { }
    | { } ;

Expression: BinaryExpr { }
    | TernaryExpr { }
    | UnaryExpr { } ;

BinaryExpr: Bop L_PAREN Expression R_PAREN SEMICOLON { } ;

TernaryExpr: TERNARY_CONDITIONAL L_PAREN Expression COMMA Expression COMMA Expression { } ;

UnaryExpr: Uop L_PAREN ID R_PAREN SEMICOLON { } ;

Bop: PLUS { }
    | MINUS { }
    | MULTIPLY { }
    | DIVIDE { }
    | REMAINDER { }
    | BITWISE_AND { }
    | BITWISE_OR { }
    | BITWISE_XOR { }
    | LOGICAL_AND { }
    | LOGICAL_OR { }
    | EQUAL { }
    | NOT_EQUAL { }
    | LESS_THAN { }
    | LESS_EQUAL { }
    | GREATER_THAN { }
    | GREATER_EQUAL { } 
    | R_SHIFT { }
    | L_SHIFT { }
    | ASSIGN { }
    | ADD_ASSIGN { }
    | MINUS_ASSIGN { } ;

Uop: INC { }
    | DEC { }
    | NOT { }
    | BITWISE_NOT { } ;

Primaria: NUM_INT { }
    | CHARACTER { }
    | ID { } ;

Funcoes: FUNCTION COLON ID { /*criar hashLocal aq */ } RETURN_TYPE COLON VarType DeclaracoesLocais { }

VarType: INT { }
    | CHAR { }
    | VOID { } ;

DeclaracoesLocais: VARIABLE COLON ID TYPE COLON VarType DeclaracoesLocais Comandos END_FUNCTION { }
    | { } ; 

Comandos: IF L_PAREN END_FUNCTION Expression COMMA Comandos COMMA Comandos { }
    | DO_WHILE L_PAREN Comandos COMMA Expression R_PAREN { }
    | WHILE L_PAREN Expression COMMA Comandos R_PAREN { }
    | FOR L_PAREN Expression COMMA Expression COMMA Expression COMMA Comandos R_PAREN SEMICOLON { }
    | PRINTF L_PAREN STRING AuxPrint R_PAREN SEMICOLON { }
    | SCANF L_PAREN STRING COMMA BITWISE_AND L_PAREN ID R_PAREN R_PAREN SEMICOLON { }
    | RETURN L_PAREN Expression R_PAREN { }
    | EXIT L_PAREN Expression R_PAREN { } ;

AuxPrint: COMMA Expression AuxPrint { }
    | { } ;
