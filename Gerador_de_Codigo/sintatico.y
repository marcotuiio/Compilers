%{
#include "asm.h"
#include "ast.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

extern int yylex();
void yyerror(void *s);

// int dimenCount = 0;
int isFuncOrArray = -1;
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
    void *posfixa;
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
%type <token> Ops
%type <expr> Primaria
%type <posfixa> PosFixa
%type <dim> ArrayCall
%type <param> FunctionCall
%type <param> ParamExpression
%type <token> VarType
%type <param> Parameters
%type <cmd> ListaComandos
%type <cmd> Comandos
%type <cmd> AuxElse
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
        setDefineIntVariable($3.valor, atoi($6.valor));
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
    | FunctionCall { $$ = $1; } ;

BinaryExpr: Ops L_PAREN Expression COMMA Expression R_PAREN {
        // printf("bop %d\n", $1.type);
        Expression *bop = createExpression(BOP, $1.type, $3, $5);
        $$ = bop;
    } ;

TernaryExpr: TERNARY_CONDITIONAL L_PAREN Expression COMMA Expression COMMA Expression {
        Expression *ternary = createExpression(TERNARY, TERNARY_CONDITIONAL, $5, $7);
        ternary->ternaryCondition = $3;
        $$ = ternary;
    } ;

UnaryExpr: Ops L_PAREN Expression R_PAREN {
        // printf("uop %d\n", $1.type);
        Expression *uop = createExpression(UOP, $1.type, $3, NULL);
        uop->preOrPost = 1;
        $$ = uop;
    } 
    | L_PAREN Expression R_PAREN INC {
        // printf("uop %d\n", $4.type);
        Expression *uop = createExpression(UOP, INC, $2, NULL);
        uop->preOrPost = 2;
        $$ = uop;
    } 
    | L_PAREN Expression R_PAREN DEC {
        // printf("uop %d\n", $4.type);
        Expression *uop = createExpression(UOP, DEC, $2, NULL);
        uop->preOrPost = 2;
        $$ = uop;
    } ;

Ops: PLUS { $$ = yylval.token; } // bop or uop
    | MINUS { $$ = yylval.token; } // bop or uop
    | MULTIPLY { $$ = yylval.token; } // bop or uop
    | DIVIDE { $$ = yylval.token; } // bop
    | REMAINDER { $$ = yylval.token; } // bop 
    | BITWISE_AND { $$ = yylval.token; } // bop
    | BITWISE_OR { $$ = yylval.token; } // bop
    | BITWISE_XOR { $$ = yylval.token; } // bop
    | LOGICAL_AND { $$ = yylval.token; } // bop
    | LOGICAL_OR { $$ = yylval.token; } // bop
    | EQUAL { $$ = yylval.token; } // bop
    | NOT_EQUAL { $$ = yylval.token; } // bop
    | LESS_THAN { $$ = yylval.token; } // bop
    | LESS_EQUAL { $$ = yylval.token; } // bop
    | GREATER_THAN { $$ = yylval.token; } // bop
    | GREATER_EQUAL { $$ = yylval.token; } // bop
    | R_SHIFT { $$ = yylval.token; } // bop
    | L_SHIFT { $$ = yylval.token; } // bop
    | ASSIGN { $$ = yylval.token; } // bop
    | ADD_ASSIGN { $$ = yylval.token; } // bop
    | MINUS_ASSIGN { $$ = yylval.token; } // bop
    | INC { $$ = yylval.token; } // uop
    | DEC { $$ = yylval.token; } // uop
    | NOT { $$ = yylval.token; } // uop
    | BITWISE_NOT { $$ = yylval.token; } ; // uop 

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
    | STRING {
        Expression *expr = createExpression(PRIMARIA, STRING, NULL, NULL);
        strcpy(expr->string, $1.valor);
        $$ = expr;
    }
    | ID PosFixa {
        Expression *expr = createExpression(PRIMARIA, ID, NULL, NULL);
        strcpy(expr->identifier, $1.valor);
        if (isFuncOrArray == 1) {
            // printf("pos fixa %s [%p]  \n", $1.valor, $2);
            expr->type = ARRAY_CALL;
            setDimensionExpression(expr, ((Dimension*)$2));
        
        } else if (isFuncOrArray == 2) {
            // printf("pos fixa %s (%p)  \n", $1.valor, $2);
            expr->type = FUNCTION_CALL;
            expr->param = (ExpParam*)$2;
        }
        isFuncOrArray = -1;
        $$ = expr;
    } ;

PosFixa: ArrayCall { isFuncOrArray = 1; $$ = $1; }
    | FunctionCall { isFuncOrArray = 2; $$ = $1; }
    | { isFuncOrArray = 0; $$ = NULL; }

ArrayCall: L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {
        Dimension *dim = createDimensionWithExp($2);
        // Expression *expr = createExpression(ARRAY_CALL, ID, NULL, NULL);
        $$ = dim;
    } ;

FunctionCall: L_PAREN ParamExpression R_PAREN {
        // Expression *expr = createExpression(FUNCTION_CALL, L_PAREN, NULL, NULL);
        $$ = $2;
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

Comandos: IF L_PAREN Expression COMMA Comandos AuxElse R_PAREN SemicolonDeSchrodinger Comandos {
        Command *cmd = createIfStatement($3, $5, $6, $9);
        $$ = cmd;
    }
    | DO_WHILE L_PAREN Comandos COMMA Expression R_PAREN SemicolonDeSchrodinger Comandos {
        Command *cmd = createDoWhileStatement($5, $3, $8);
        $$ = cmd;
    }
    | WHILE L_PAREN Expression COMMA Comandos R_PAREN SemicolonDeSchrodinger Comandos {
        Command *cmd = createWhileStatement($3, $5, $8);
        $$ = cmd;
    }
    | FOR L_PAREN Expression COMMA Expression COMMA Expression COMMA Comandos R_PAREN SemicolonDeSchrodinger Comandos {
        Command *cmd = createForStatement($3, $5, $7, $9, $12);
        $$ = cmd;
    }
    | PRINTF L_PAREN STRING AuxPrint R_PAREN SemicolonDeSchrodinger Comandos {
        // printf("Comandos print %s \n", $3.valor);
        Command *cmd = createPrintStatement($3.valor, $4, $7);
        $$ = cmd;
    }
    | SCANF L_PAREN STRING COMMA BITWISE_AND L_PAREN ID R_PAREN R_PAREN SemicolonDeSchrodinger Comandos {
        Command *cmd = createScanStatement($3.valor, $7.valor, $11);
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
    | Expression SemicolonDeSchrodinger Comandos {
        // printf("000000000000000 Comandos expression\n");
        Command *cmd = createCommandExpression($1, $3);
        $$ = cmd;
    } 
    | { $$ = NULL; };

AuxElse: COMMA Comandos { $$ = $2; }
    | { $$ = NULL; } ;

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

    /* printf("\n>>>>>>>> End Parse <<<<<<<<\n"); */
    if (AST) {
        Program *ast = (Program*)AST;
        /* printf("AST %p\n", ast); */
        traverseAST(ast);
        /* hash = ast->hashTable; */
    } else {
        printf("AST NULL\n");
        exit(1);
    }

    /* for (int i = 0; i < HASH_SIZE; i++) {
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
    } */
    
    return 0;
}
