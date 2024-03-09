%{
// #include "asm.h"
#include "ast.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

extern int yylex();
void yyerror(void *s);

// int dimenCount = 0;
int pointerCount = 0;
int paramCount = 0;

void **globalHash = createHash();
void **currentHash = NULL;

Program *AST = NULL;

%}

%union {
    Program *prog;
    Function *func;
    Dimension *dim;
    Expression *expr;
    Command *cmd;
    void *param;
    struct {
        char *valor;
        int type;
    } token;
}

%token <token> MyEOF
%token <token> GLOBAL
%token <token> VARIABLE
%token <token> CONSTANT
%token <token> PARAMETER
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

%type <prog> AstParse
%type <dim> ArrayCheck
%type <expr> Expression 
%type <expr> BinaryExpr 
%type <expr> TernaryExpr 
%type <expr> UnaryExpr
%type <token> Bop
%type <token> Uop
%type <expr> Primaria
%type <token> VarType
%type <param> Parameters
%type <func> Funcoes
%type <cmd> Comandos
%type <expr> AuxPrint
%type DeclaracoesGlobais
%type DeclaracoesLocais
%type Pointers

%start Start

%%

Start: AstParse MyEOF {
        AST = $1;
        return 0;
    } ;

AstParse: DeclaracoesGlobais Funcoes {
        Program *ast = createProgram(globalHash, $2, NULL);
        $$ = ast;
    } ;

DeclaracoesGlobais: CONSTANT ID VALUE COLON NUM_INT DeclaracoesGlobais {
        void *node = insertHash(globalHash, $2.valor, INT, 0);
        setKind(node, VAR);
        setIsConstant(node);
        setAssign(node, $5); 
    }
    | GLOBAL VARIABLE COLON ID TYPE COLON 
        VarType { pointerCount = 0; } 
        Pointers ArrayCheck DeclaracoesGlobais {
        void *node = insertHash(globalHash, $4.valor, $7, pointerCount);
        if (!$10) {
            setKind(node, VAR);
        } else {
            setKind(node, VECTOR);
        }
        setDimensions(node, $10);
        setIsGlobal(node);
    } 
    | { } ;

ArrayCheck: L_SQUARE_BRACKET NUM_INT R_SQUARE_BRACKET ArrayCheck {
        Dimension *dim = createDimension($2);
        dim->next = $4;
        $$ = dim;
    }
    | { $$ = NULL; } ;

Expression: BinaryExpr { $$ = $1; }
    | TernaryExpr { $$ = $1; }
    | UnaryExpr { $$ = $1; } ;

BinaryExpr: Bop L_PAREN Expression COMMA Expression R_PAREN SEMICOLON {
        Expression *bop = createExpression(BOP, $1.type, $3, $5);
        $$ = bop;
    } ;

TernaryExpr: TERNARY_CONDITIONAL L_PAREN Expression COMMA Expression COMMA Expression {
        Expression *ternary = createExpression(TERNARY, TERNARY_OP, $5, $7);
        ternary->ternaryCondition = $3;
        $$ = ternary;
    } ;

UnaryExpr: Uop L_PAREN Expression R_PAREN SEMICOLON {
        Expression *uop = createExpression(UOP, $1.type, $3, NULL);
        $$ = uop;
    } 
    | L_PAREN Expression R_PAREN SEMICOLON Uop {
        Expression *uop = createExpression(UOP, $5.type, $2, NULL);
        $$ = uop;
    } ;

Bop: PLUS { $$ = yylval.token; }
    | MINUS { $$ = yylval.token; }
    | MULTIPLY { $$ = yylval.token; }
    | DIVIDE { $$ = yylval.token; }
    | REMAINDER { $$ = yylval.token; }
    | BITWISE_AND { $$ = yylval.token; }
    | BITWISE_OR { $$ = yylval.token; }
    | BITWISE_XOR { $$ = yylval.token; }
    | LOGICAL_AND { $$ = yylval.token; }
    | LOGICAL_OR { $$ = yylval.token; }
    | EQUAL { $$ = yylval.token; }
    | NOT_EQUAL { $$ = yylval.token; }
    | LESS_THAN { $$ = yylval.token; }
    | LESS_EQUAL { $$ = yylval.token; }
    | GREATER_THAN { $$ = yylval.token; }
    | GREATER_EQUAL { $$ = yylval.token; } 
    | R_SHIFT { $$ = yylval.token; }
    | L_SHIFT { $$ = yylval.token; }
    | ASSIGN { $$ = yylval.token; }
    | ADD_ASSIGN { $$ = yylval.token; }
    | MINUS_ASSIGN { $$ = yylval.token; } ;

Uop: INC { $$ = yylval.token; }
    | DEC { $$ = yylval.token; }
    | NOT { $$ = yylval.token; }
    | BITWISE_NOT { $$ = yylval.token; } ;

Primaria: NUM_INT {
        Expression *expr = createExpression(PRIMARIA, INT, NULL, NULL);
        expr->assign = atoi($1.valor);
        $$ = expr;
    }
    | CHARACTER {
        Expression *expr = createExpression(PRIMARIA, CHAR, NULL, NULL);
        if ($1.valor[1] == '\\') {
            switch ($1.valor[2]) {
                case 'n':
                    expr->assign = '\n';
                    break;
                case 't':
                    expr->assign = '\t';
                    break;
                case 'r':
                    expr->assign = '\r';
                    break;
                case '0':
                    expr->assign = '\0';
                    break;
                case '\\':
                    expr->assign = '\\';
                    break;
                case '\'':
                    expr->assign = '\'';
                    break;
                case '\"':
                    expr->assign = '\"';
                    break;
            }
        } else {
            expr->assign = $1.valor[1];
        }
        $$ = expr;
    }
    | ID {
        Expression *expr = createExpression(PRIMARIA, ID, NULL, NULL);
        $$ = expr;
    } ;

Funcoes: FUNCTION COLON ID { currentHash = createHash(); } 
        RETURN_TYPE COLON VarType { pointerCount = 0; } 
        Pointers { paramCount = 0; } 
        Parameters DeclaracoesLocais Comandos END_FUNCTION Funcoes {
        Function *func = createFunction(currentHash, $6.type, pointerCount, $3.valor, $13, $15);
        node *node = insertHash(globalHash, $3.valor, $6.type, pointerCount);
        setKind(node, FUNCTION);
        setQntdParams(node, paramCount);
        setParams(node, $11);
        currentHash = NULL;
        $$ = func;
    } ;

VarType: INT { $$ = yylval.token; }
    | CHAR { $$ = yylval.token; }
    | VOID { $$ = yylval.token; } ;

Parameters: PARAMETER COLON ID TYPE COLON 
        VarType { pointerCount = 0; } 
        Pointers ArrayCheck Parameters {
        void *node = insertHash(currentHash, $3.valor, $6.type, pointerCount);
        setQntdParams(node, paramCount);
        // setSRegisterInHash(node, paramsQntd-1);
        paramCount++;
        Param *param = createParam($3.valor, $6.type, pointerCount);
        if (!$9) {
            setKind(node, VAR);
            param->kindParam = VAR;
        } else {
            setKind(node, VECTOR);
            param->kindParam = VECTOR;
        }
        setDimensions(node, $9);
        param->next = $10;
        $$ = param;
    }
    | { $$ = NULL; } ;

DeclaracoesLocais: VARIABLE COLON ID TYPE COLON 
        VarType { pointerCount = 0; } 
        Pointers ArrayCheck DeclaracoesLocais {
        void *node = insertHash(currentHash, $3.valor, $6.type, pointerCount);
        if (!$9) {
            setKind(node, VAR);
        } else {
            setKind(node, VECTOR);
        }
        setDimensions(node, $9);
    }
    | { } ; 

Pointers: MULTIPLY Pointers { pointerCount++; }
    | { } ;

Comandos: IF L_PAREN Expression COMMA Comandos COMMA Comandos R_PAREN Comandos {
        Command *cmd = createIfStatement($3, $5, $7, $9);
        $$ = cmd;
    }
    | DO_WHILE L_PAREN Comandos COMMA Expression R_PAREN Comandos {
        Command *cmd = createDoWhileStatement($5, $3, $7);
        $$ = cmd;
    }
    | WHILE L_PAREN Expression COMMA Comandos R_PAREN Comandos {
        Command *cmd = createWhileStatement($3, $5, $7);
        $$ = cmd;
    }
    | FOR L_PAREN Expression COMMA Expression COMMA Expression COMMA Comandos R_PAREN SEMICOLON Comandos {
        Command *cmd = createForStatement($3, $5, $7, $9, $12);
        $$ = cmd;
    }
    | PRINTF L_PAREN STRING AuxPrint R_PAREN SEMICOLON Comandos {
        Command *cmd = createPrintStatement($3, $4, $7);
        $$ = cmd;
    }
    | SCANF L_PAREN STRING COMMA BITWISE_AND L_PAREN ID R_PAREN R_PAREN SEMICOLON Comandos {
        Command *cmd = createScanStatement($3, $7, $11);
        $$ = cmd;
    }
    | RETURN L_PAREN Expression R_PAREN Comandos {
        Command *cmd = createReturnStatement($3, $5);
        $$ = cmd;
    }
    | EXIT L_PAREN Expression R_PAREN Comandos {
        Command *cmd = createExitStatement($3, $5);
        $$ = cmd;
    } 
    | Expression SEMICOLON Comandos {
        Command *cmd = createExpressionStatement($1, $3);
        $$ = cmd;
    }

AuxPrint: COMMA Expression AuxPrint {
        $2->nextExpr = $3;
        $$ = $2;
    }
    | { $$ = NULL; } ;

%%

void yyerror(void *s) {}

int main(int argc, char *argv[]) {
    yyparse();

    void **hash = AST->hashTable;

    HashNode *node = (HashNode*)hash[0];
    while(node) {
        printf("Global hash %s %d\n", node->varId, node->typeVar);
        node = node->next;
    }
    printf("\n");
    Function *func = (Function*)AST->functionsList;
    while (func) {
        printf("Function %s %d hash %p\n", func->name, func->returnType, func->hashTable);
        HashNode *funcNode = (HashNode*)func->hashTable[0];
        while (funcNode) {
            printf("local var %s %d\n", funcNode->varId, funcNode->VarType);
        }
        printf("\n");
        Command *cmd = (Command*)func->commands;
        while (cmd) {
            printf("Command %d\n", cmd->type);
            cmd = cmd->next;
        }
        printf("\n");
        func = func->next;
    }
    
    return 0;
}
