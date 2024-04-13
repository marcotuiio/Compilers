%{
#include "asm.h"
#include "ast.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

extern int yylex();
extern int yyrestart();
void yyerror(void *s);
extern void yylex_destroy();

extern int yychar;
extern int textBefore;
extern char lineBuffer[2048];
extern void readInputIntoAuxFile();
extern void getLineBuffer();
extern void deleteAuxFile();

extern char wrongToken[32];
extern int wrongTokenLine;
extern int wrongTokenColumn;

int erroAux = 0;
int semanticError = 0;
int CURRENT_TYPE, AUX_CURRENT_TYPE = -1;
int paramsQntd = 0;
int dimensionError = 0;
char bufferAux[128];
char printDimen[1024];
int defineAux = 0;
int dimensionAux = 0;
int funcAux = 0;
int auxLineAssign, auxColumnAssign;
int auxPosFixa = -1;

Function *auxFunctionList = NULL;
int wasThereDeclarations = 0;

void *prototypeParam = NULL;

void **globalHash = NULL;
void **currentHash = NULL;

Program *AST = NULL;
FILE *mipsFile = NULL;
char *mipsPath = NULL;

void printLineError(int line, int column);

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
        int column;
        int line;
        int type;
    } token;
}

%token MyEOF
%token ERRO

%token <token> NUMBER_SIGN
%token <token> DEFINE
%token <token> L_CURLY_BRACKET
%token <token> R_CURLY_BRACKET
%token <token> L_PAREN
%token <token> R_PAREN
%token <token> L_SQUARE_BRACKET
%token <token> R_SQUARE_BRACKET
%token <token> COMMA
%token <token> SEMICOLON
%token <token> PLUS
%token <token> MINUS
%token <token> MULTIPLY
%token <token> DIVIDE
%token <token> REMAINDER
%token <token> INT
%token <token> CHAR
%token <token> VOID
%token <token> DO
%token <token> WHILE
%token <token> IF
%token <token> ELSE
%token <token> FOR
%token <token> PRINTF
%token <token> SCANF
%token <token> RETURN
%token <token> EXIT
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
%token <token> INC
%token <token> DEC
%token <token> NUM_INT
%token <token> NUM_HEXA
%token <token> NUM_OCTAL
%token <token> STRING
%token <token> CHARACTER
%token <token> ID

%type <prog> Programa
%type <func> DeclaracaoOUFuncao
%type <func> ListaFuncoes
%type Declaracoes
%type <func> Funcao
%type <token> DeclaraVariaveisFuncao
%type <ptr> Ponteiro
%type <token> DeclaraVariaveis
%type <token> BlocoVariaveis
%type <dim> ExpressaoColchete
%type <expr> ExpressaoAssign
%type <token> RetornoVariavel
%type <param> DeclaraPrototipos
%type <param> Parametros
%type <param> BlocoParametros
%type <param> RetornaParametros
%type <token> Tipo
%type <cmd> Bloco
%type <cmd> Comandos
%type <cmd> RetornoComandos
%type <cmd> ListaComandos
%type <cmd> AuxElse
%type <expr> AuxFor
%type <expr> AuxPrint
%type <expr> Expressao
%type <token> OpAtrib
%type <token> OpRel
%type <token> OpMult
%type <token> OpUnario
%type <expr> ExpressaoAtribuicao
%type <expr> ExpressaoCondicional
%type <expr> ExpressaoOrLogico
%type <expr> ExpressaoAndLogico
%type <expr> ExpressaoOr
%type <expr> ExpressaoXor
%type <expr> ExpressaoAnd
%type <expr> ExpressaoIgual
%type <expr> ExpressaoRelacional
%type <expr> ExpressaoShift
%type <expr> ExpressaoAditiva
%type <expr> ExpressaoMultiplicativa
%type <expr> ExpressaoCast
%type <expr> ExpressaoUnaria
%type <expr> ExpressaoPosFixa
%type <paramExp> PulaExpressaoAtribuicao
%type <paramExp> AuxPula
%type <expr> ExpressaoPrimaria
%type <expr> Numero

%start Start

%%

Start: Programa MyEOF { 
        AST = $1;
        erroAux = 0; 
        return 0; 
    }
    | Programa ERRO { erroAux = 1; return 0; }
    | error { erroAux = 1; return 0; } ;

Programa: { 
        void **hash = createHash();
        globalHash = hash;
        // printf("criou hash global %p\n", globalHash);
    } 
    DeclaracaoOUFuncao ListaFuncoes {
        Program *aux = NULL;
        if (wasThereDeclarations == 1) {
            aux = createProgram(globalHash, auxFunctionList, NULL); // $2 should be a list of functions, therefore Function *
        } else {
            aux = createProgram(globalHash, $2, NULL);
        }
        $$ = aux; 
    } ;

DeclaracaoOUFuncao: Declaracoes { /* inserir na hash global o que quer que apareça aqui */
        wasThereDeclarations = 1;
        $$ = NULL;
    }
    | Funcao { 
        if (!auxFunctionList) {
            auxFunctionList = $1;
        } else {
            // auxFunctionList->next = $1;
            Function *aux = auxFunctionList;
            while (auxFunctionList->next) {
                auxFunctionList = auxFunctionList->next;
            }
            auxFunctionList->next = $1;
            auxFunctionList = aux;
        }
        $$ = $1;  // should return a list of functions
    } ;
    
ListaFuncoes: DeclaracaoOUFuncao ListaFuncoes { 
        if ($1) {  // se for uma funcao e nao uma declaracao
            $$ = auxFunctionList;
        } else {
            // printf("chegaaaa %p %p\n", $1, auxFunctionList);
        }
    }
    | { $$ = NULL; } ;

Declaracoes: NUMBER_SIGN DEFINE ID Expressao { /* Adicionar isso na hash */
        // printf("\ntipo da expressao do define %s %d\n", $3.valor, $4->type);
        if ($4->value->type == STRING) {
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: string type is not compatible with define", $4->value->line, $4->value->column);
            printLineError($4->value->line, $4->value->column);
            if (currentHash) freeHash(currentHash);
            if (globalHash) freeHash(globalHash);
            deleteMipsFileOnError(mipsFile, mipsPath);
            deleteAuxFile();
            exit(1);
        }

        if (!lookForValueInHash(globalHash, $3.valor, $3.line, $3.column, INT, &textBefore, &semanticError)) {
            void *node = insertHash(globalHash, $3.valor, $3.line, $3.column, INT, 0);
            setKind(node, VAR);
            setIsConstant(node);
            defineAux = 1;
            // printf("expressao do define %d %p %p\n", $4->type, $4->left, $4->right);
            ResultExpression *result = evalExpression($4, globalHash, NULL, NULL);
            defineAux = 0;
            // printf("\nresult do define %s %d %d\n", $3.valor, result->typeVar, result->assign);
            setDefineIntVariable($3.valor, result->assign, result->registerType, result->registerNumber);
            setAssign(node, result->assign);
        }
    }
    | DeclaraVariaveis {
        if (strlen(printDimen) > 0) {
            printf("%s", printDimen);
            printLineError($1.line, $1.column);
            if (currentHash) freeHash(currentHash);
            // if (globalHash) freeHash(globalHash);
            deleteMipsFileOnError(mipsFile, mipsPath);
            deleteAuxFile();
            exit(1);
        }
        currentHash = NULL;
    }
    | DeclaraPrototipos { } ;

Funcao: Tipo Ponteiro ID Parametros L_CURLY_BRACKET DeclaraVariaveisFuncao Comandos R_CURLY_BRACKET {
        // printf(">>>>> function name %s\n", $3.valor);
        // vendo se a funcao ja foi declarada
        if (!lookForPrototypeInHash(globalHash, $3.valor, $3.line, $3.column, $1.type, $4, paramsQntd, &textBefore, &semanticError)) {
            if (!lookForValueInHash(globalHash, $3.valor, $3.line, $3.column, $1.type, &textBefore, &semanticError)) {
                void *node = insertHash(globalHash, $3.valor, $3.line, $3.column, $1.type, $2);
                setKind(node, FUNCTION);
                setQntdParams(node, paramsQntd);
                setParam(node, $4);
            } 
        }
        if (strlen(printDimen) > 0) {
            printf("%s", printDimen);
            printLineError($6.line, $6.column);
            if (currentHash) freeHash(currentHash);
            if (globalHash) freeHash(globalHash);
            traverseAST(AST);
            deleteMipsFileOnError(mipsFile, mipsPath);
            deleteAuxFile();
            exit(1);
        }
        Function *func = createFunction(currentHash, $1.type, $2, $3.valor, $7, NULL);
        // printf("\ncriou funcao %s %p comando %p\n", $3.valor, func, $7);
        paramsQntd = 0;
        currentHash = NULL;
        funcAux = 0;
        $$ = func;
    } ;

DeclaraVariaveisFuncao: DeclaraVariaveis DeclaraVariaveisFuncao { /* descendo para colocar na hash da funcao */ }
    | { } ;

Ponteiro: MULTIPLY Ponteiro {
        int ptr = $2 + 1;
        $$ = ptr;
    }
    | { $$ = 0; } ; 

DeclaraVariaveis: Tipo BlocoVariaveis SEMICOLON {
        CURRENT_TYPE = $1.type;
        // printf("o que acontece aqui %d\n", $1.type);
        $$ = $2;  // retornando id da declaracao
    } ;

BlocoVariaveis: Ponteiro ID ExpressaoColchete ExpressaoAssign RetornoVariavel {
        if (!currentHash) {
            if (!currentHash && funcAux) {  // hash da funcao
                void **hash = createHash();
                currentHash = hash;
            } else {
                currentHash = globalHash;
            }
        } 
        // printf("\n==> variavel %s tipo %d (%d) %d || linha %d\n", $2.valor, CURRENT_TYPE, AUX_CURRENT_TYPE, $1, $2.line);
        if (CURRENT_TYPE == 277 && $1 == 0) { // variables of type void not allowed
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: variable '%s' declared void", $2.line, $2.column, $2.valor);
            printLineError($2.line, $2.column);
            if (currentHash) freeHash(currentHash);
            if (globalHash) freeHash(globalHash);
            traverseAST(AST);
            deleteMipsFileOnError(mipsFile, mipsPath);
            deleteAuxFile();
            exit(1);
        }
        // considerar o ponteiro, dimensoes e atribuicao se existirem
        if (!lookForValueInHash(currentHash, $2.valor, $2.line, $2.column, CURRENT_TYPE, &textBefore, &semanticError)) {
            void *node = insertHash(currentHash, $2.valor, $2.line, $2.column, CURRENT_TYPE, $1);
            // printf("\n----- %s %p node %p \n\n", $2.valor, $3, node);
            if (!$3) {
                setKind(node, VAR);
            } else {
                // printf("Declaring vector %s %d\n", $2.valor, $3->size);
                setKind(node, VECTOR);
            }

            if (dimensionError != 0) {
                // printf("dimension error\n");
                if (textBefore) printf("\n");
                strcpy(printDimen, "error:semantic:");
                for (int i = 0; i < 128; i++) bufferAux[i] = '\0';
                sprintf(bufferAux, "%d", $2.line);
                strcat(printDimen, bufferAux);
                strcat(printDimen, ":");
                for (int i = 0; i < 128; i++) bufferAux[i] = '\0';
                sprintf(bufferAux, "%d", $2.column);
                strcat(printDimen, bufferAux);
                strcat(printDimen, ": size of array '");
                strcat(printDimen, $2.valor);
                if (dimensionError == 1) {
                    strcat(printDimen, "' is zero");
                } else if (dimensionError == 2) {
                    strcat(printDimen, "' is negative");
                }
                $$ = $2;
            }
            setDimensions(node, $3);

            if ($4) {
                setHashExpr(node, $4, auxLineAssign, auxColumnAssign);
                // printf("assign no bison = %s %d | %d\n", $4->value->valor, $4->type, ((HashNode*)node)->typeVar);
            }
        }
    } ;

ExpressaoColchete: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ExpressaoColchete {
        ResultExpression *result = NULL;
        dimensionAux = 1;
        if ($2) result = evalExpression($2, globalHash, currentHash, NULL);
        if (result) {
            // printf("result->assign %d %d\n", result->assign, result->typeVar);
            if ((result->typeVar != NUM_INT && result->typeVar != INT) || result->pointer != 0) {
                if (textBefore) printf("\n");
                printf("error:semantic:%d:%d: array subscript is not an integer", $1.line, $1.column);
                printLineError($1.line, $1.column);
                if (currentHash) freeHash(currentHash);
                // if (globalHash) freeHash(globalHash);
                deleteMipsFileOnError(mipsFile, mipsPath);
                deleteAuxFile();
                exit(1);
            }
            if (result->assign == 0) {
                dimensionError = 1;
            } else if (result->assign < 0) {
                dimensionError = 2;
            }   
            freeRegister(result->registerType, result->registerNumber);
        }
        dimensionAux = 0;
        Dimension *aux = createDimension(result->assign);
        aux->next = $4;
        $$ = aux;
    }
    | { $$ = NULL; } ;

ExpressaoAssign: ASSIGN ExpressaoAtribuicao { 
        $2->assign = ASSIGN;
        auxLineAssign = $1.line;
        auxColumnAssign = $1.column;
        $$ = $2;
    }
    | { $$ = NULL; } ;

RetornoVariavel: COMMA BlocoVariaveis { if (AUX_CURRENT_TYPE == 0) AUX_CURRENT_TYPE = CURRENT_TYPE; $$ = $2; }
    | { } ; 

DeclaraPrototipos: Tipo Ponteiro ID Parametros SEMICOLON { 
        // colocar na hash global e ver se bate com as funcoes ?
        void *node = insertHash(globalHash, $3.valor, $3.line, $3.column, $1.type, $2);
        setKind(node, FUNCTION);
        setPrototype(node);
        setQntdParams(node, paramsQntd);
        setParam(node, $4);
        prototypeParam = NULL;
        paramsQntd = 0;
        free(currentHash);
        currentHash = NULL;
    } ; 

Parametros: L_PAREN BlocoParametros R_PAREN {
        funcAux = 1;
        // printf("parametros %p x %p\n", $2, prototypeParam);
        $$ = $2;
        // $$ = prototypeParam;
    } ;

BlocoParametros: Tipo Ponteiro ID ExpressaoColchete RetornaParametros {
        if (!currentHash) {  // hash da funcao
            void **hash = createHash();
            currentHash = hash;
        }
        if ($1.type == 277 && $2 == 0) { // variables of type void not allowed
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: parameter '%s' declared void", $3.line, $3.column, $3.valor);
            printLineError($3.line, $3.column);
            if (currentHash) freeHash(currentHash);
            // traverseAST(AST);
            deleteMipsFileOnError(mipsFile, mipsPath);
            deleteAuxFile();
            exit(1);
        }
        paramsQntd++;
        Param *aux = createParam($1.type, $3.valor, $2, $3.line, $3.column+1, $5);
        // printf("tipo param %p %d %s %p\n", aux, aux->type, aux->identifier, aux->next);
        if (!prototypeParam) prototypeParam = aux;

        if (!lookForValueInHash(currentHash, $3.valor, $3.line, $3.column, $1.type, &textBefore, &semanticError)) {
            void *node = insertHash(currentHash, $3.valor, $3.line, $3.column, $1.type, $2);
            setQntdParams(node, paramsQntd);
            setSRegisterInHash(node, paramsQntd-1);
            // printf("register $ s %d for param %s\n", paramsQntd-1, $3.valor);
            
            if (dimensionError != 0) {
                if (textBefore) printf("\n");
                strcpy(printDimen, "error:semantic:");
                for (int i = 0; i < 128; i++) bufferAux[i] = '\0';
                sprintf(bufferAux, "%d", $3.line);
                strcat(printDimen, bufferAux);
                strcat(printDimen, ":");
                for (int i = 0; i < 128; i++) bufferAux[i] = '\0';
                sprintf(bufferAux, "%d", $3.column);
                strcat(printDimen, bufferAux);
                strcat(printDimen, ": size of array '");
                strcat(printDimen, $3.valor);
                if (dimensionError == 1) {
                    strcat(printDimen, "' is zero");
                } else if (dimensionError == 2) {
                    strcat(printDimen, "' is negative");
                }
            }
            if (!$4) {
                setKind(node, VAR);
                aux->kindParam = VAR; 
            } else {
                printf("VETOR param %d %s\n", $1.type, $3.valor);
                setKind(node, VECTOR);
                aux->kindParam = VECTOR;
            }
            setDimensions(node, $4);
        }

        $$ = aux;
    }
    | { $$ = NULL; } ;

RetornaParametros: COMMA BlocoParametros { 
        $$ = $2;
    }
    | { $$ = NULL; } ;

Tipo: INT {
        AUX_CURRENT_TYPE = CURRENT_TYPE;
        CURRENT_TYPE = INT; 
        $$ = yylval.token; 
    }
    | CHAR { 
        AUX_CURRENT_TYPE = CURRENT_TYPE;
        CURRENT_TYPE = CHAR;
        $$ = yylval.token;
    }
    | VOID {
        AUX_CURRENT_TYPE = CURRENT_TYPE;
        CURRENT_TYPE = VOID;
        $$ = yylval.token;
    } ;

Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET { 
    Command *aux = $2;
        // while (aux) {
        //     printf("1..comando %p\n", aux);
            aux = aux->next;
        // }
        // printf("comando %p\n", aux);
        $$ = $2; 
    }

Comandos: ListaComandos RetornoComandos {
        // Command *aux = $1;
        // while ($1) {
        //     if ($1->next == NULL) {
        //         printf("2 comando %p %p\n", $1, $2);
        //         $1->next = $2;
        //         break;
        //     }
        //     $1 = $1->next;
        // }
        // $1 = aux;
        $1->next = $2;
        $$ = $1;
    } ;

RetornoComandos: ListaComandos RetornoComandos { 
        // Command *aux = $1;
        // while ($1) {
        //     if ($1->next == NULL) {
        //         printf("\n1 comando %p %p\n", $1, $2);
        //         $1->next = $2;
        //         break;
        //     }
        //     $1 = $1->next;
        // }
        // $1 = aux;
        $1->next = $2;
        $$ = $1;
    }
    | { $$ = NULL; } ;

ListaComandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, DO);
        Command *aux = createDoWhileStatement($5, $2, NULL);
        aux->auxToken = auxToken;
        $$ = aux;
    }
    | WHILE L_PAREN Expressao R_PAREN Bloco {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, WHILE);
        Command *aux = createWhileStatement($3, $5, NULL);
        aux->auxToken = auxToken;
        $$ = aux;
    }
    | IF L_PAREN Expressao R_PAREN Bloco AuxElse {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, IF);
        Command *aux = createIfStatement($3, $5, $6, NULL);
        aux->auxToken = auxToken;
        $$ = aux;
    }
    | FOR L_PAREN AuxFor SEMICOLON AuxFor SEMICOLON AuxFor R_PAREN Bloco {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, FOR);
        Command *aux = createForStatement($3, $5, $7, $9, NULL);
        aux->auxToken = auxToken;
        $$ = aux;
    }
    | PRINTF L_PAREN STRING AuxPrint R_PAREN SEMICOLON {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, PRINTF);
        Command *aux = createPrintStatement($3.valor, $4, NULL);
        aux->auxToken = auxToken;
        $$ = aux;
    }
    | SCANF L_PAREN STRING COMMA BITWISE_AND ID R_PAREN SEMICOLON {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, SCANF);
        Command *aux = createScanStatement($3.valor, $6.valor, $6.line, $6.column, NULL);
        aux->auxToken = auxToken;
        $$ = aux;
    }
    | EXIT L_PAREN Expressao R_PAREN SEMICOLON {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, EXIT);
        Command *aux = createExitStatement($3, NULL);
        aux->auxToken = auxToken;
        $$ = aux; 
    }
    | RETURN AuxFor SEMICOLON {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, RETURN);
        Command *aux = createReturnStatement($2, NULL);
        aux->auxToken = auxToken;
        $$ = aux;
    }
    | Expressao SEMICOLON {
        Command *aux = createCommandExpression($1, NULL);
        $$ = aux;
    }
    | SEMICOLON { }
    | Bloco { $$ = $1; } ;

AuxElse: ELSE Bloco {
        $$ = $2;
    }
    | { $$ = NULL; } ;

AuxFor: Expressao { $$ = $1; }
    | { $$ = NULL; } ;

AuxPrint: COMMA Expressao { // da conflito de reduce mas paciencia
        // printf("auxprint %p\n", $2);
        $2->isHeadOfList = 0;
        $$ = $2; 
    }
    | { $$ = NULL; } ;

Expressao: ExpressaoAtribuicao {
        $$ = $1;
    }
    | Expressao COMMA ExpressaoAtribuicao { // o gerador do conflito aqui
        // AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, $1->value->type);
        // Expression *aux = createExpression($1->type, COMMA, auxToken, $1, NULL);
        Expression *head = $1;
        // int i = 0;
        head->isHeadOfList = LISTA_EXP;
        while (head->nextExpr) {    
            // printf("%d list de exprs %p %d \n", i++, head, head->type);
            head = head->nextExpr;   
        }
        head->nextExpr = $3;
        $$ = $1;
    } ;

OpAtrib: ASSIGN { $$ = yylval.token; }
    | ADD_ASSIGN { $$ = yylval.token; }
    | MINUS_ASSIGN { $$ = yylval.token; } ;

OpRel: LESS_THAN { $$ = yylval.token; }
    | LESS_EQUAL { $$ = yylval.token; }
    | GREATER_THAN { $$ = yylval.token; }
    | GREATER_EQUAL { $$ = yylval.token; } ;

OpMult: MULTIPLY { $$ = yylval.token; }
    | DIVIDE { $$ = yylval.token; }
    | REMAINDER { $$ = yylval.token; } ;

OpUnario: BITWISE_AND { $$ = yylval.token; }  // &
    | MULTIPLY { $$ = yylval.token; } 
    | PLUS { $$ = yylval.token; }
    | MINUS { $$ = yylval.token; }
    | NOT { $$ = yylval.token; }  // !
    | BITWISE_NOT { $$ = yylval.token; } ;  // ~

ExpressaoAtribuicao: ExpressaoCondicional { $$ = $1; }
    | ExpressaoUnaria OpAtrib ExpressaoAtribuicao {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, $2.type);
        Expression *aux = createExpression(ATRIBUICAO, $2.type, auxToken, $1, $3);
        $$ = aux;
    } ;

ExpressaoCondicional: ExpressaoOrLogico { $$ = $1; }
    | ExpressaoOrLogico TERNARY_CONDITIONAL Expressao COLON ExpressaoCondicional {
        AuxToken *auxToken = createAuxToken($4.valor, $4.line, $4.column, $4.type);
        Expression *aux = createExpression(TERNARY, TERNARY_CONDITIONAL, auxToken, $3, $5);
        aux->ternary = $1;
        $$ = aux;
    } ;

ExpressaoOrLogico: ExpressaoAndLogico { $$ = $1; }
    | ExpressaoOrLogico LOGICAL_OR ExpressaoAndLogico {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, LOGICAL_OR);
        Expression *aux = createExpression(OR_LOGICO, LOGICAL_OR, auxToken, $1, $3);
        $$ = aux;
    } ;

ExpressaoAndLogico: ExpressaoOr { $$ = $1; }
    | ExpressaoAndLogico LOGICAL_AND ExpressaoOr {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, LOGICAL_AND);
        Expression *aux = createExpression(AND_LOGICO, LOGICAL_AND, auxToken, $1, $3);
        $$ = aux;
    } ;

ExpressaoOr: ExpressaoXor { $$ = $1;}
    | ExpressaoOr BITWISE_OR ExpressaoXor {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, BITWISE_OR);
        Expression *aux = createExpression(OR_BIT, BITWISE_OR, auxToken, $1, $3);
        $$ = aux;
    } ;

ExpressaoXor: ExpressaoAnd { $$ = $1; }
    | ExpressaoXor BITWISE_XOR ExpressaoAnd {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, BITWISE_XOR);
        Expression *aux = createExpression(XOR_BIT, BITWISE_XOR, auxToken, $1, $3);
        $$ = aux;
    } ;

ExpressaoAnd: ExpressaoIgual { $$ = $1; }
    | ExpressaoAnd BITWISE_AND ExpressaoIgual {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, BITWISE_AND);
        Expression *aux = createExpression(AND_BIT, BITWISE_AND, auxToken, $1, $3);
        $$ = aux;
    } ;

ExpressaoIgual: ExpressaoRelacional { $$ = $1; }
    | ExpressaoIgual EQUAL ExpressaoRelacional {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, EQUAL);
        Expression *aux = createExpression(RELACIONAL, EQUAL, auxToken, $1, $3);
        $$ = aux;
    }
    | ExpressaoIgual NOT_EQUAL ExpressaoRelacional {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, NOT_EQUAL);
        Expression *aux = createExpression(RELACIONAL, NOT_EQUAL, auxToken, $1, $3);
        $$ = aux;
    } ;

ExpressaoRelacional: ExpressaoShift { $$ = $1; }
    | ExpressaoRelacional OpRel ExpressaoShift {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, $2.type);
        Expression *aux = createExpression(RELACIONAL, $2.type, auxToken, $1, $3);
        $$ = aux;
    } ;

ExpressaoShift: ExpressaoAditiva { $$ = $1; }
    | ExpressaoShift R_SHIFT ExpressaoAditiva {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, R_SHIFT);
        Expression *aux = createExpression(SHIFT, R_SHIFT, auxToken, $1, $3);
        $$ = aux;
    }
    | ExpressaoShift L_SHIFT ExpressaoAditiva {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, L_SHIFT);
        Expression *aux = createExpression(SHIFT, L_SHIFT, auxToken, $1, $3);
        $$ = aux;
    } ;

ExpressaoAditiva: ExpressaoMultiplicativa { $$ = $1; }
    | ExpressaoAditiva PLUS ExpressaoMultiplicativa { 
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, PLUS);
        Expression *aux = createExpression(ADITIVIVA, PLUS, auxToken, $1, $3);
        $$ = aux;
    }   
    | ExpressaoAditiva MINUS ExpressaoMultiplicativa { 
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, MINUS);
        Expression *aux = createExpression(ADITIVIVA, MINUS, auxToken, $1, $3);
        $$ = aux;
    } ;

ExpressaoMultiplicativa: ExpressaoCast { $$ = $1; }
    | ExpressaoMultiplicativa OpMult ExpressaoCast {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, $2.type);
        Expression *aux = createExpression(MULTIPLICATIVA, $2.type, auxToken, $1, $3);
        $$ = aux;
    } ;

ExpressaoCast: ExpressaoUnaria { $$ = $1; }
    | L_PAREN Tipo Ponteiro R_PAREN ExpressaoCast {
        AuxToken *auxToken = createAuxToken($2.valor, $1.line, $1.column, $2.type);
        auxToken->pointer = $3;
        Expression *aux = createExpression(CASTING, $2.type, auxToken, NULL, $5);
        // printf("tipo atual antes %d %d\n", CURRENT_TYPE, AUX_CURRENT_TYPE);
        CURRENT_TYPE = AUX_CURRENT_TYPE;
        // AUX_CURRENT_TYPE = -1;
        // printf("tipo atual depois %d %d\n", CURRENT_TYPE, AUX_CURRENT_TYPE);
        aux->pointer = $3;
        $$ = aux;
    } ;

ExpressaoUnaria: ExpressaoPosFixa { $$ = $1; }
    | INC ExpressaoUnaria {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, INC);
        Expression *aux = createExpression(UNARIA, INC, auxToken, $2, NULL);
        $$ = aux;
    }
    | DEC ExpressaoUnaria {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, DEC);
        Expression *aux = createExpression(UNARIA, DEC, auxToken, $2, NULL);
        $$ = aux;
    }
    | OpUnario ExpressaoCast {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, $1.type);
        Expression *aux = createExpression(UNARIA, $1.type, auxToken, $2, NULL);
        $$ = aux;
    } ;

ExpressaoPosFixa: ExpressaoPrimaria { $$ = $1; }
    | ExpressaoPosFixa L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, $2.type);
        Dimension *dimen = createDimensionWithExp($3, auxToken);
        if ($1->type != POS_FIXA) {
            auxToken = createAuxToken($1->value->valor, $1->value->line, $1->value->column, $1->value->type);
            Expression *aux = createExpression(POS_FIXA, $2.type, auxToken, $1, NULL);
            setDimensionExpression(aux, dimen);
            $$ = aux;
        } else {
            setDimensionExpression($1, dimen);
            $$ = $1;
        }
    }
    | ExpressaoPosFixa L_PAREN PulaExpressaoAtribuicao R_PAREN {
        // printf("chegou aqui %p %p %p\n", $3, ((ExpParam *)$3)->next, ((ExpParam *)$3)->next->next);
        AuxToken *auxToken = createAuxToken($1->value->valor, $1->value->line, $1->value->column, $1->value->type);
        Expression *aux = createExpression(POS_FIXA, $2.type, auxToken, $1, NULL);
        aux->param = $3;
        $$ = aux;
    }
    | ExpressaoPosFixa INC {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, INC);
        Expression *aux = createExpression(POS_FIXA, INC, auxToken, $1, NULL);
        $$ = aux;
    }
    | ExpressaoPosFixa DEC {
        AuxToken *auxToken = createAuxToken($2.valor, $2.line, $2.column, DEC);
        Expression *aux = createExpression(POS_FIXA, DEC, auxToken, $1, NULL);
        $$ = aux;
    } ;

PulaExpressaoAtribuicao: ExpressaoAtribuicao AuxPula { 
        ExpParam *aux = createExpParam($1, $2);
        $$ = aux;
    }
    | { $$ = NULL; } ;

AuxPula: COMMA ExpressaoAtribuicao AuxPula {
        ExpParam *aux = createExpParam($2, $3);
        $$ = aux;
    }
    | { $$ = NULL; } ;

ExpressaoPrimaria: ID {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, ID);
        Expression *aux = createExpression(PRIMARIA, ID, auxToken, NULL, NULL);
        $$ = aux;
    }
    | Numero { $$ = $1; }
    | CHARACTER {
        char *actualChar = calloc(2, sizeof(char));
        if ($1.valor[1] == '\\') {
            switch ($1.valor[2]) {
                case '0':
                    actualChar[0] = '\0';
                    break;
                case 'n':
                    actualChar[0] = '\n';
                    break;
                case 't':
                    actualChar[0] = '\t';
                    break;
                case 'r':
                    actualChar[0] = '\r';
                    break;
                case '\\':
                    actualChar[0] = '\\';
                    break;
                case '\'':
                    actualChar[0] = '\'';
                    break;
                case '\"':
                    actualChar[0] = '\"';
                    break;
                // Add more cases here for other escape sequences if needed
                default:
                    actualChar[0] = $1.valor[2];
                    break;
            }
        } else {
            actualChar[0] = $1.valor[1];
        }
        actualChar[1] = '\0';
        // printf("actual one %d\n", actualChar[0]);
        AuxToken *auxToken = createAuxToken(actualChar, $1.line, $1.column, CHARACTER);
        Expression *aux = createExpression(PRIMARIA, CHARACTER, auxToken, NULL, NULL);
        $$ = aux;
    }
    | STRING {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, STRING);
        Expression *aux = createExpression(PRIMARIA, STRING, auxToken, NULL, NULL);
        $$ = aux;
    }
    | L_PAREN Expressao R_PAREN {
        $$ = $2;
    } ;

Numero: NUM_INT {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, NUM_INT);
        Expression *aux = createExpression(NUMEROS, NUM_INT, auxToken, NULL, NULL);
        $$ = aux;
    }
    | NUM_HEXA {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, NUM_HEXA);
        Expression *aux = createExpression(NUMEROS, NUM_HEXA, auxToken, NULL, NULL);
        $$ = aux;
    }
    | NUM_OCTAL {
        AuxToken *auxToken = createAuxToken($1.valor, $1.line, $1.column, NUM_OCTAL);
        Expression *aux = createExpression(NUMEROS, NUM_OCTAL, auxToken, NULL, NULL);
        $$ = aux;
    } ;

%%

void yyerror(void *s) {}

void printLineError(int line, int column) {
    getLineBuffer(line);
    printf("\n%s\n", lineBuffer);
    for (int i = 0; i < column - 1; i++) printf(" ");
    printf("^");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No input file.\n");
        return 1;

    } else {
        char *sourcePath = calloc(strlen(argv[argc - 1]) + 1, sizeof(char));
        strcpy(sourcePath, argv[argc - 1]);
        mipsPath = calloc(strlen(argv[argc - 1]) + 20, sizeof(char));
        mipsFile = createAsmFile(sourcePath, mipsPath);
    }
    
    FILE *source = fopen(argv[argc - 1], "r");
    if (!source) {
        printf("Source file not found.\n");
        return 1;
    }
    readInputIntoAuxFile(source);
    yyrestart(source);

    yyparse();

    if (erroAux) {
        if (textBefore) printf("\n");
        int localColumn = yylval.token.column;
        if (yychar == 0 || yychar == MyEOF) {
            printf("error:syntax:%d:%d: expected declaration or statement at end of input", yylval.token.line, yylval.token.column);
        
        } else {
            if (strlen(wrongToken) > 0) {
                localColumn = wrongTokenColumn;
                printf("error:syntax:%d:%d: %s", wrongTokenLine, wrongTokenColumn, wrongToken);
            } else {
                printf("error:syntax:%d:%d: %s", yylval.token.line, yylval.token.column, yylval.token.valor);
            }
        }
        printLineError(yylval.token.line, localColumn);
    
    } else {
        traverseAST(AST);  // se tiver erro semantico vai dar exit e free la dentro
        if (textBefore) printf("\n");
        printf("SUCCESSFUL COMPILATION."); // se chegar aqui, compilou com sucesso e nao tem erros semanticos
        printEnd(mipsFile);
    }
    freeAST(AST);
    fclose(source);
    free(mipsPath);
    deleteAuxFile();
    yylex_destroy();
    return 0;
}