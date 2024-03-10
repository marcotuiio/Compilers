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

void **globalHash = NULL;
void **currentHash = NULL;

Function *functionList = NULL;

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
        int line;
        int col;
    } token;
}

%token MyEOF
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

%type <dim> ArrayCheck
%type <expr> Expression 
%type <expr> BinaryExpr 
%type <expr> TernaryExpr 
%type <expr> UnaryExpr
%type <token> Bop
%type <token> Uop
%type <expr> Primaria
%type <expr> ArrayCall
%type <expr> FunctionCall
%type <param> ParamExpression
%type <token> VarType
%type <param> Parameters
%type <cmd> ListaComandos
%type <cmd> Comandos
%type <expr> AuxReturn
%type <expr> AuxPrint
%type <token> SemicolonDeSchrodinger
%type DeclaracoesLocais
%type Pointers

%start AstParse

%%

AstParse: Declaracoes MyEOF {
        Program *ast = createProgram(globalHash, functionList, NULL);
        AST = ast;
        return 0;
    } ;

Declaracoes: DeclaraDefine Declaracoes { }
    | DeclaraVarGlobal Declaracoes { } 
    | DeclaraFuncao Declaracoes { } 
    | { } ;

DeclaraDefine: CONSTANT COLON ID VALUE COLON NUM_INT {
        void *node = insertHash(globalHash, $3.valor, INT, 0);
        setKind(node, VAR);
        setIsConstant(node);
        setAssign(node, atoi($6.valor)); 
    } ;

DeclaraVarGlobal: GLOBAL VARIABLE COLON ID TYPE COLON VarType { pointerCount = 0; } Pointers ArrayCheck {
        // printf("DeclaraVarGlobal global var\n");
        void *node = insertHash(globalHash, $4.valor, $7.type, pointerCount);
        if (!$10) {
            setKind(node, VAR);
        } else {
            setKind(node, VECTOR);
        }
        setDimensions(node, $10);
        setIsGlobal(node);
    } ;

DeclaraFuncao: FUNCTION COLON ID { currentHash = createHash(); } RETURN_TYPE COLON VarType { pointerCount = 0; } Pointers { paramCount = 0; } Parameters DeclaracoesLocais ListaComandos END_FUNCTION {
        Function *func = createFunction(currentHash, $7.type, pointerCount, $3.valor, $13, NULL);
        if (functionList) {
            functionList->next = func;
        } else {
            functionList = func;
        }
        
        // printf("Funcoes %s %p | %p -> %p \n", $3.valor, func, functionList, functionList->next);
        void *node = insertHash(globalHash, $3.valor, $7.type, pointerCount);
        setKind(node, FUNCTIONN);
        setQntdParams(node, paramCount);
        setParam(node, $11);
        currentHash = NULL;
    } ;

ArrayCheck: L_SQUARE_BRACKET NUM_INT R_SQUARE_BRACKET ArrayCheck {
        Dimension *dim = createDimension(atoi($2.valor));
        dim->next = $4;
        $$ = dim;
    }
    | { $$ = NULL; } ;

Expression: BinaryExpr { $$ = $1; }
    | TernaryExpr { $$ = $1; }
    | UnaryExpr { $$ = $1; } 
    | Primaria { $$ = $1; } 
    | ArrayCall { $$ = $1; }
    | FunctionCall { $$ = $1; } ;

BinaryExpr: Bop L_PAREN Expression COMMA Expression R_PAREN {
        // printf("bop %d\n", $1.type);
        Expression *bop = createExpression(BOP, $1.type, $3, $5);
        $$ = bop;
    } ;

TernaryExpr: TERNARY_CONDITIONAL L_PAREN Expression COMMA Expression COMMA Expression {
        Expression *ternary = createExpression(TERNARY, TERNARY_CONDITIONAL, $5, $7);
        ternary->ternaryCondition = $3;
        $$ = ternary;
    } ;

UnaryExpr: Uop L_PAREN Expression R_PAREN {
        // printf("uop %d\n", $1.type);
        Expression *uop = createExpression(UOP, $1.type, $3, NULL);
        $$ = uop;
    } 
    | L_PAREN Expression R_PAREN Uop {
        // printf("uop %d\n", $4.type);
        Expression *uop = createExpression(UOP, $4.type, $2, NULL);
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
    | PLUS { $$ = yylval.token; }
    | MINUS { $$ = yylval.token; }
    | MULTIPLY { $$ = yylval.token; }
    | BITWISE_AND { $$ = yylval.token; }
    | BITWISE_NOT { $$ = yylval.token; } ;

Primaria: NUM_INT {
        Expression *expr = createExpression(PRIMARIA, INT, NULL, NULL);
        expr->assign = atoi($1.valor);
        // printf("primaria %p %d\n", expr, expr->assign);
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

ArrayCall: ID L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {
        // printf("array call %s\n", $1.valor);
        Dimension *dim = createDimensionWithExp($3);
        Expression *expr = createExpression(ARRAY_CALL, ID, NULL, NULL);
        setDimensionExpression(expr, dim);
        $$ = expr;
    } ;

FunctionCall: ID L_PAREN ParamExpression R_PAREN {
        // printf("function call %s\n", $1.valor);
        Expression *expr = createExpression(FUNCTION_CALL, ID, NULL, NULL);
        expr->param = $3;
        $$ = expr;
    } ;

ParamExpression: Expression ParamExpression {
        ExpParam *aux = createExpParam($1, $2);
        $$ = aux;
    }
    | COMMA Expression ParamExpression {
        ExpParam *aux = createExpParam($2, $3);
        $$ = aux;
    }
    | { $$ = NULL; } ;

VarType: INT { $$ = yylval.token; }
    | CHAR { $$ = yylval.token; }
    | VOID { $$ = yylval.token; } ;

Parameters: PARAMETER COLON ID TYPE COLON VarType { pointerCount = 0; } Pointers ArrayCheck Parameters {
        // printf("Parmetro ID %s type %d\n", $3.valor, $6.type);
        void *node = insertHash(currentHash, $3.valor, $6.type, pointerCount);
        setQntdParams(node, paramCount);
        // setSRegisterInHash(node, paramsQntd-1);
        paramCount++;
        Param *param = createParam($6.type, $3.valor, pointerCount, $10);
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

DeclaracoesLocais: VARIABLE COLON ID TYPE COLON VarType { pointerCount = 0; } Pointers ArrayCheck DeclaracoesLocais {
        // printf("DeclaracoesLocais local var %s %d\n", $3.valor, $6.type);
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

ListaComandos: Comandos SemicolonDeSchrodinger ListaComandos {       
        $1->next = $3;
        $$ = $1;
    }
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
    | FOR L_PAREN Expression COMMA Expression COMMA Expression COMMA Comandos R_PAREN Comandos {
        Command *cmd = createForStatement($3, $5, $7, $9, $11);
        $$ = cmd;
    }
    | PRINTF L_PAREN STRING AuxPrint R_PAREN Comandos {
        // printf("Comandos print %s \n", $3.valor);
        Command *cmd = createPrintStatement($3.valor, $4, $6);
        $$ = cmd;
    }
    | SCANF L_PAREN STRING COMMA BITWISE_AND L_PAREN ID R_PAREN R_PAREN Comandos {
        Command *cmd = createScanStatement($3.valor, $7.valor, $10);
        $$ = cmd;
    }
    | RETURN L_PAREN AuxReturn R_PAREN Comandos {
        // printf("@@@@@@@ retunr  %d\n", $3 ? $3->type : -1);
        Command *cmd = createReturnStatement($3, $5);
        $$ = cmd;
    }
    | EXIT L_PAREN Expression R_PAREN Comandos {
        Command *cmd = createExitStatement($3, $5);
        $$ = cmd;
    } 
    | Expression Comandos {
        // printf("000000000000000 Comandos expression\n");
        Command *cmd = createCommandExpression($1, $2);
        $$ = cmd;
    } 
    | { $$ = NULL; };

AuxPrint: COMMA Expression AuxPrint {
        $2->nextExpr = $3;
        $$ = $2;
    }
    | { $$ = NULL; } ;

AuxReturn: Expression { $$ = $1; }
    | { $$ = NULL; } ;

SemicolonDeSchrodinger: SEMICOLON { }
    | { } ;

%%

void yyerror(void *s) {
    printf("Erro na gramatica %d [ %s ]:%d:%d \n", yychar, yylval.token.valor, yylval.token.line, yylval.token.col);
}

int main(int argc, char *argv[]) {
    globalHash = createHash();
    yyparse();
    void **hash = NULL;

    printf("\n>>>>>>>> End Parse <<<<<<<<\n");
    if (AST) {
        Program *ast = (Program*)AST;
        printf("AST %p\n", ast);
        hash = ast->hashTable;
    } else {
        printf("AST NULL\n");
        exit(1);
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *node = (HashNode*)hash[i];
        while (node) {
            printf("%d Global hash %s %d\n", i, node->varId, node->typeVar);
            node = node->next;
        }
    }
    
    printf("\n");
    Function *func = (Function*)AST->functionsList;
    while (func) {
        printf("Function %s %d hash %p\n", func->name, func->returnType, func->hashTable);

        for (int i = 0; i < HASH_SIZE; i++) {
            HashNode *node = (HashNode*)func->hashTable[i];
            while (node) {
                printf("%d Local hash var %s %d\n", i, node->varId, node->typeVar);
                node = node->next;
            }
        }
        printf("\n");
        Command *cmd = (Command*)func->commandList;
        while (cmd) {
            printf("Command %d\n", cmd->type);
            cmd = cmd->next;
        }
        printf("\n");
        func = func->next;
    }
    
    return 0;
}
