%{
#include "ast.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

extern int yylex();
void yyerror(void *s);

extern int yychar;
extern int textBefore;
extern char lineBuffer[2048];
extern void getLineBuffer();

extern char wrongToken[32];
extern int wrongTokenLine;
extern int wrongTokenColumn;

int erroAux = 0;
int semanticError = 0;
int CURRENT_TYPE;
int pointerQntd = 0;
int auxPosIncrement;

void *prototypeParam = NULL;


void **globalHash = NULL;
void **currentHash = NULL;

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
        int column;
        int line;
        int type;
    } token;
}

%token MyEOF
%token ERRO

%token NUMBER_SIGN
%token DEFINE
%token L_CURLY_BRACKET
%token R_CURLY_BRACKET
%token L_PAREN
%token R_PAREN
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token COMMA
%token SEMICOLON
%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE
%token REMAINDER
%token INT
%token CHAR
%token VOID
%token DO
%token WHILE
%token IF
%token ELSE
%token FOR
%token PRINTF
%token SCANF
%token RETURN
%token EXIT
%token ADD_ASSIGN
%token MINUS_ASSIGN
%token ASSIGN
%token EQUAL
%token NOT_EQUAL
%token LESS_THAN
%token LESS_EQUAL
%token GREATER_THAN
%token GREATER_EQUAL
%token BITWISE_AND
%token BITWISE_OR
%token BITWISE_XOR
%token BITWISE_NOT
%token LOGICAL_AND
%token LOGICAL_OR
%token NOT
%token TERNARY_CONDITIONAL
%token COLON
%token R_SHIFT
%token L_SHIFT
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
%type <token> Declaracoes
%type <func> Funcao
%type <token> DeclaraVariaveisFuncao
%type <token> Ponteiro
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
%type <expr> AuxCondicional
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
%type <expr> AuxPosFixa
%type <expr> PulaExpressaoAtribuicao
%type <expr> AuxPula
%type <expr> ExpressaoPrimaria
%type <expr> Numero

%start Start

%%

Start: Programa MyEOF { erroAux = 0; return 0; }
    | Programa ERRO { erroAux = 1; return 0; }
    | error { erroAux = 1; return 0; } ;

Programa: { 
        void **hash = createHash();
        globalHash = hash;
    } 
    DeclaracaoOUFuncao ListaFuncoes {
        Program *aux = createProgram(globalHash, $2, NULL); // $2 should be a list of functions, therefore Function *
        $$ = aux; 
    } ;

DeclaracaoOUFuncao: Declaracoes { /* inserir na hash global o que quer que apareça aqui */
        currentHash = globalHash;
        $$ = NULL;
    }
    | Funcao { 
        $$ = $1;  // should return a list of functions
    } ;
    
ListaFuncoes: DeclaracaoOUFuncao ListaFuncoes { 
        if (((Function *) $1) != NULL) {  // se for uma funcao e nao uma declaracao
            $1->next = $2;  // devia linkar as funcoes, sera se ta certo?
            $$ = $1;  // devia retornar aa lista de funcoes
        }
    }
    | { $$ = NULL; } ;

Declaracoes: NUMBER_SIGN DEFINE ID Expressao { /* Adicionar isso na hash */
        if (!lookForValueInHash(currentHash, $3.valor, $3.line, $3.column, DEFINE, &textBefore, &semanticError))
            insertHash(currentHash, $3.valor, $3.line, $3.column, DEFINE, 0, NULL, 0, $4, NULL);
    }
    | DeclaraVariaveis { /* Adicionar isso na hash */ }
    | DeclaraPrototipos { /* Adicionar isso na hash */ } ;

Funcao: Tipo Ponteiro ID Parametros L_CURLY_BRACKET DeclaraVariaveisFuncao Comandos R_CURLY_BRACKET {
        // vendo se a funcao ja foi declarada
        printf("1- %p %p\n", currentHash, globalHash);
        printf("ID: %s\n", $3.valor);
        printf("CURRENT_TYPE: %d\n", $1.type);
        printf("pointerQntd: %d\n", pointerQntd);
        if (!lookForPrototypeInHash(globalHash, $3.valor, $3.line, $3.column, $1.type, $4, &textBefore, &semanticError)) {
            if (!lookForValueInHash(globalHash, $3.valor, $3.line, $3.column, $1.type, &textBefore, &semanticError)) {
                insertHash(globalHash, $3.valor, $3.line, $3.column, $1.type, pointerQntd, $4, 0, NULL, NULL);
            }
        }
        pointerQntd = 0;
        Function *func = createFunction(currentHash, $1.type, pointerQntd, $3.valor, $7, NULL);
        pointerQntd = 0;  // nao sei se funciona
        currentHash = NULL;
        $$ = func;
    } ;

DeclaraVariaveisFuncao: DeclaraVariaveis DeclaraVariaveisFuncao { /* descendo para colocar na hash da funcao */ }
    | { } ;

Ponteiro: MULTIPLY Ponteiro { pointerQntd++; }
    | { } ; 

DeclaraVariaveis: Tipo BlocoVariaveis SEMICOLON {
        // inserir na hash devida
    } ;

BlocoVariaveis: Ponteiro ID ExpressaoColchete ExpressaoAssign RetornoVariavel {
        if (!currentHash) {  // hash da funcao
            void **hash = createHash();
            currentHash = hash;
        }
        // considerar ponteiro, nome e dimensoes (se tiver)
        printf("2- %p %p\n", currentHash, globalHash);
        printf("ID: %s\n", $2.valor);
        printf("CURRENT_TYPE: %d\n", CURRENT_TYPE);
        printf("pointerQntd: %d\n", pointerQntd);
        if (!lookForValueInHash(currentHash, $2.valor, $2.line, $2.column, CURRENT_TYPE, &textBefore, &semanticError)) {
            insertHash(currentHash, $2.valor, $2.line, $2.column, CURRENT_TYPE, pointerQntd, NULL, 0, $4, $3);
        }
        pointerQntd = 0;
    } ;

ExpressaoColchete: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ExpressaoColchete {
        // nova struct para dimensoes?
        Dimension *aux = createDimension($2);
        aux->next = $4;
        $$ = aux;
    }
    | { $$ = NULL; } ;

ExpressaoAssign: ASSIGN ExpressaoAtribuicao { 
        $2->assign = ASSIGN;
        $$ = $2;
    }
    | { $$ = NULL; } ;

RetornoVariavel: COMMA BlocoVariaveis { /* colocar na hash */ }
    | { } ; 

DeclaraPrototipos: Tipo Ponteiro ID Parametros SEMICOLON { 
        // colocar na hash global e ver se bate com as funcoes ?
        if (!lookForPrototypeInHash(globalHash, $3.valor, $3.line, $3.column, $1.type, $4, &textBefore, &semanticError))
            insertHash(globalHash, $3.valor, $3.line, $3.column, $1.type, pointerQntd, $4, 1, NULL, NULL);
        prototypeParam = NULL;
        pointerQntd = 0;
        $$ = NULL;
    } ; 

Parametros: L_PAREN BlocoParametros R_PAREN { 
        $$ = prototypeParam;
    } ;

BlocoParametros: Tipo Ponteiro ID ExpressaoColchete RetornaParametros {
        if (!currentHash) {  // hash da funcao
            void **hash = createHash();
            currentHash = hash;
        }
        Param *aux = createParam($1.type, $1.valor, pointerQntd, $4);
        aux->next = $5;
        if (!prototypeParam) prototypeParam = aux;

        if (!lookForValueInHash(currentHash, $3.valor, $3.line, $3.column, $1.type, &textBefore, &semanticError))
            insertHash(currentHash, $3.valor, $3.line, $3.column, $1.type, pointerQntd, NULL, 0, NULL, $4);
        pointerQntd = 0;
        $$ = aux;
    }
    | { $$ = NULL; } ;

RetornaParametros: COMMA BlocoParametros { 
        $$ = $2;
    }
    | { $$ = NULL; } ;

Tipo: INT { 
        CURRENT_TYPE = INT; 
        $$ = yylval.token; 
    }
    | CHAR { 
        CURRENT_TYPE = CHAR;
        $$ = yylval.token;
    }
    | VOID { 
        CURRENT_TYPE = VOID;
        $$ = yylval.token;
    } ;

Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET { $$ = $2; } ;

Comandos: ListaComandos RetornoComandos {
        $1->next = $2;
        $$ = $1;
    } ;

RetornoComandos: ListaComandos RetornoComandos { 
        $1->next = $2;
        $$ = $1;
    }
    | { $$ = NULL; } ;

ListaComandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON {
        Command *aux = createDoWhileStatement($5, $2, NULL);
        $$ = aux;
    }
    | WHILE L_PAREN Expressao R_PAREN Bloco {
        Command *aux = createWhileStatement($3, $5, NULL);
        $$ = aux;
    }
    | IF L_PAREN Expressao R_PAREN Bloco AuxElse {
        Command *aux = createIfStatement($3, $5, $6, NULL);
        $$ = aux;
    }
    | FOR L_PAREN AuxFor SEMICOLON AuxFor SEMICOLON AuxFor R_PAREN Bloco {
        Command *aux = createForStatement($3, $5, $7, $9, NULL);
        $$ = aux;
    }
    | PRINTF L_PAREN STRING AuxPrint R_PAREN SEMICOLON {
        Command *aux = createPrintStatement(yylval.token.valor, $4, NULL);
        $$ = aux;
    }
    | SCANF L_PAREN STRING COMMA BITWISE_AND ID R_PAREN SEMICOLON {
        Command *aux = createScanStatement(yylval.token.valor, yylval.token.valor, NULL);
        $$ = aux;
    }
    | EXIT L_PAREN Expressao R_PAREN SEMICOLON {
        Command *aux = createExitStatement($3, NULL);
        $$ = aux; 
    }
    | RETURN AuxFor SEMICOLON {
        Command *aux = createReturnStatement($2, NULL);
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

AuxPrint: COMMA Expressao { $$ = $2; }
    | { $$ = NULL; } ;

Expressao: ExpressaoAtribuicao {
        $$ = $1;
    }
    | Expressao COMMA ExpressaoAtribuicao { 
        Expression *aux = createExpression(COMMA, NULL, $1, $3);
        $$ = aux;
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

OpUnario: BITWISE_AND { $$ = yylval.token; }
    | MULTIPLY { $$ = yylval.token; }
    | PLUS { $$ = yylval.token; }
    | MINUS { $$ = yylval.token; }
    | NOT { $$ = yylval.token; }
    | BITWISE_NOT { $$ = yylval.token; } ;

ExpressaoAtribuicao: ExpressaoCondicional { $$ = $1; }
    | ExpressaoUnaria OpAtrib ExpressaoAtribuicao {
        Expression *aux = createExpression($2.type, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoCondicional: ExpressaoOrLogico AuxCondicional {
        $1->ternary = $2;
        $$ = $1;
    }

AuxCondicional: TERNARY_CONDITIONAL Expressao COLON ExpressaoCondicional {
        Expression *aux = createExpression(TERNARY_CONDITIONAL, NULL, $2, $4);
        $$ = aux;
    }
    | { $$ = NULL; } ;

ExpressaoOrLogico: ExpressaoAndLogico { $$ = $1; }
    | ExpressaoOrLogico LOGICAL_OR ExpressaoAndLogico { 
        Expression *aux = createExpression(LOGICAL_OR, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoAndLogico: ExpressaoOr { $$ = $1; }
    | ExpressaoAndLogico LOGICAL_AND ExpressaoOr {
        Expression *aux = createExpression(LOGICAL_AND, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoOr: ExpressaoXor { $$ = $1;}
    | ExpressaoOr BITWISE_OR ExpressaoXor {
        Expression *aux = createExpression(BITWISE_OR, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoXor: ExpressaoAnd { $$ = $1; }
    | ExpressaoXor BITWISE_XOR ExpressaoAnd {
        Expression *aux = createExpression(BITWISE_XOR, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoAnd: ExpressaoIgual { $$ = $1; }
    | ExpressaoAnd BITWISE_AND ExpressaoIgual {
        Expression *aux = createExpression(BITWISE_AND, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoIgual: ExpressaoRelacional { $$ = $1; }
    | ExpressaoIgual EQUAL ExpressaoRelacional {
        Expression *aux = createExpression(EQUAL, NULL, $1, $3);
        $$ = aux;
    }
    | ExpressaoIgual NOT_EQUAL ExpressaoRelacional { 
        Expression *aux = createExpression(NOT_EQUAL, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoRelacional: ExpressaoShift { $$ = $1; }
    | ExpressaoRelacional OpRel ExpressaoShift { 
        Expression *aux = createExpression($2.type, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoShift: ExpressaoAditiva { $$ = $1; }
    | ExpressaoShift R_SHIFT ExpressaoAditiva {
        Expression *aux = createExpression(R_SHIFT, NULL, $1, $3);
        $$ = aux;
    }
    | ExpressaoShift L_SHIFT ExpressaoAditiva {
        Expression *aux = createExpression(L_SHIFT, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoAditiva: ExpressaoMultiplicativa { $$ = $1; }
    | ExpressaoAditiva PLUS ExpressaoMultiplicativa { 
        Expression *aux = createExpression(PLUS, NULL, $1, $3);
        $$ = aux;
    }   
    | ExpressaoAditiva MINUS ExpressaoMultiplicativa { 
        Expression *aux = createExpression(MINUS, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoMultiplicativa: ExpressaoCast { $$ = $1; }
    | ExpressaoMultiplicativa OpMult ExpressaoCast {
        Expression *aux = createExpression($2.type, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoCast: ExpressaoUnaria { $$ = $1; }
    | L_PAREN Tipo Ponteiro R_PAREN ExpressaoCast {
        // tem qua tratar o ponteiro e fazer alguma coisa com essa expressao
        Expression *aux = createExpression(CAST, NULL, NULL, $5);
        aux->pointer = pointerQntd;
        pointerQntd = 0;
    } ;

ExpressaoUnaria: ExpressaoPosFixa { $$ = $1; }
    | INC ExpressaoUnaria { 
        $2->preIncrement = INC; 
        $$ = $2;
    }
    | DEC ExpressaoUnaria {
        $2->preIncrement = DEC; 
        $$ = $2;
    }
    | OpUnario ExpressaoCast {
        $2->unario = $1.type; 
        $$ = $2;
    } ;

ExpressaoPosFixa: ExpressaoPrimaria { $$ = $1; }
    | ExpressaoPosFixa AuxPosFixa {
        $1->next = $2;
        $1->posIncrement = auxPosIncrement;
        auxPosIncrement = 0;
        $$ = $1; 
    } ;

AuxPosFixa: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET { $$ = $2; }
    | L_PAREN PulaExpressaoAtribuicao R_PAREN { $$ = $2; }
    | INC { auxPosIncrement = INC; }
    | DEC { auxPosIncrement = DEC; } ;

PulaExpressaoAtribuicao: ExpressaoAtribuicao AuxPula { 
        $1->next = $2; 
        $$ = $1;
    }
    | { $$ = NULL; } ;

AuxPula: COMMA ExpressaoAtribuicao AuxPula {
        $2->next = $3;
        $$ = $2;
    }
    | { $$ = NULL; } ;

ExpressaoPrimaria: ID { 
        Expression *aux = createExpression(ID, $1.valor, NULL, NULL);
        $$ = aux;
    }
    | Numero { $$ = $1; }
    | CHARACTER { 
        Expression *aux = createExpression(CHARACTER, $1.valor, NULL, NULL);
        $$ = aux;
    }
    | STRING { 
        Expression *aux = createExpression(STRING, $1.valor, NULL, NULL);
        $$ = aux;
    }
    | L_PAREN Expressao R_PAREN {
        $$ = $2;
    } ;

Numero: NUM_INT {
        Expression *aux = createExpression(NUM_INT, $1.valor, NULL, NULL);
        $$ = aux;
    }
    | NUM_HEXA { 
        Expression *aux = createExpression(NUM_HEXA, $1.valor, NULL, NULL);
        $$ = aux;
    }
    | NUM_OCTAL {
        Expression *aux = createExpression(NUM_OCTAL, $1.valor, NULL, NULL);
        $$ = aux;
    } ;

%%

void yyerror(void *s) {}

int main(int argc, char *argv[]) {
    yyparse();

    if (textBefore) printf("\n");
    if (erroAux) {

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

        getLineBuffer(yylval.token.line);
        
        printf("\n%s\n", lineBuffer);
        for (int i = 0; i < localColumn - 1; i++) printf(" ");
        printf("^");

    } else {
        printf("SUCCESSFUL COMPILATION.");
    }
    return 0;
}