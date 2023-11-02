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

%}

%union {
    Program *prog;
    Function *func;
    Expression *expr;
    Command *cmd;
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
%token INC
%token DEC
%token NUM_INT
%token NUM_HEXA
%token NUM_OCTAL
%token STRING
%token CHARACTER
%token ID

%type <prog> Programa
%type <func> DeclaracaoOUFuncao
%type <func> ListaFuncoes
%type <token> Declaracoes
%type <func> Funcao
%type <token> DeclaraVariaveisFuncao
%type <token> Ponteiro
%type <token> DeclaraVariaveis
%type <token> BlocoVariaveis
%type <expr> ExpressaoColchete
%type <expr> ExpressaoAssign
%type <token> RetornoVariavel
%type <token> DeclaraPrototipos
%type <token> Parametros
%type <token> BlocoParametros
%type <token> RetornaParametros
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

Programa: DeclaracaoOUFuncao ListaFuncoes {
        void **hash = createHash();
        Program *aux = createProgram(hash, $2, NULL); // $2 should be a list of functions, therefore Function *
        $$ = aux;  // should return the whole program after being parsed, but its returning the union
    } ;

DeclaracaoOUFuncao: Declaracoes { $$ = NULL; /* inserir na hash o que quer que apareça aqui */}
    | Funcao { 
        $$ = $1;  // should return a list of functions, but its returning the union  
    } ;
    
ListaFuncoes: DeclaracaoOUFuncao ListaFuncoes { 
        if (((Function *) $1) != NULL) {  // should verify if its a function or a declaration, but its verifying if the union return is NULL
            $1->next = $2;  // should link the fuctions, but is trying to link the unions
            $$ = $1;  // then again should return the functions, but is returning the union
        }
    }
    | { $$ = NULL; } ;

Declaracoes: NUMBER_SIGN DEFINE ID Expressao { /* Adicionar isso na hash */ }
    | DeclaraVariaveis { /* Adicionar isso na hash */ }
    | DeclaraPrototipos { /* Adicionar isso na hash */ } ;

Funcao: Tipo Ponteiro ID Parametros L_CURLY_BRACKET DeclaraVariaveisFuncao Comandos R_CURLY_BRACKET {
        void **hash = createHash();
        // descobrir como pegar nome da funcao
        // colocar nome da funcao na hash global e na struct da funcao 
        Function *func = createFunction(hash, $1.type, pointerQntd, "Nome da funcao", $7, NULL);
        pointerQntd = 0;  // nao sei se funciona
        $$ = func;
    } ;

DeclaraVariaveisFuncao: DeclaraVariaveis DeclaraVariaveisFuncao { /* colocar na hash da funcao */}
    | { } ;

Ponteiro: MULTIPLY Ponteiro { pointerQntd++; }
    | { } ; 

DeclaraVariaveis: Tipo BlocoVariaveis SEMICOLON { } ;

BlocoVariaveis: Ponteiro ID ExpressaoColchete ExpressaoAssign RetornoVariavel {
        // inserir na hash devida
        // considerar ponteiro, nome e dimensoes (se tiver)
        pointerQntd = 0;
    } ;

ExpressaoColchete: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ExpressaoColchete {
        // nova struct para dimensoes?
    }
    | { } ;

ExpressaoAssign: ASSIGN ExpressaoAtribuicao { $$ = $2; }
    | { $$ = NULL; } ;

RetornoVariavel: COMMA BlocoVariaveis { /* colocar na hash */ }
    | { } ; 

DeclaraPrototipos: Tipo Ponteiro ID Parametros SEMICOLON { 
        // colocar na hash global e ver se bate com as funcoes ?
    } ; 

Parametros: L_PAREN BlocoParametros R_PAREN { /* vai pra hash */ } ;

BlocoParametros: Tipo Ponteiro ID ExpressaoColchete RetornaParametros {
        // colocar na hash devida 
    }
    | { } ;

RetornaParametros: COMMA BlocoParametros { /* colocar na hash */ }
    | { } ;

Tipo: INT { 
        CURRENT_TYPE = INT; 
        $$ = yylval.token; 
    }
    | CHAR { CURRENT_TYPE = CHAR;
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

OpRel: LESS_THAN { }
    | LESS_EQUAL { }
    | GREATER_THAN { }
    | GREATER_EQUAL { } ;

OpMult: MULTIPLY { }
    | DIVIDE { }
    | REMAINDER { } ;

OpUnario: BITWISE_AND { }
    | MULTIPLY { }
    | PLUS { }
    | MINUS { }
    | NOT { }
    | BITWISE_NOT { } ;

ExpressaoAtribuicao: ExpressaoCondicional { $$ = $1; }
    | ExpressaoUnaria OpAtrib ExpressaoAtribuicao {
        Expression *aux = createExpression($2.type, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoCondicional: ExpressaoOrLogico AuxCondicional { }

AuxCondicional: TERNARY_CONDITIONAL Expressao COLON ExpressaoCondicional { }
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
    } ;

ExpressaoUnaria: ExpressaoPosFixa { $$ = $1; }
    | INC ExpressaoUnaria { }
    | DEC ExpressaoUnaria { }
    | OpUnario ExpressaoCast { } ;

ExpressaoPosFixa: ExpressaoPrimaria { }
    | ExpressaoPosFixa AuxPosFixa { } ;

AuxPosFixa: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET { $$ = $2; }
    | L_PAREN PulaExpressaoAtribuicao R_PAREN { $$ = $2; }
    | INC { }
    | DEC { } ;

PulaExpressaoAtribuicao: ExpressaoAtribuicao AuxPula { }
    | { $$ = NULL; } ;

AuxPula: COMMA ExpressaoAtribuicao AuxPula { }
    | { $$ = NULL; } ;

ExpressaoPrimaria: ID { 
        Expression *aux = createExpression(ID, yylval.token.valor, NULL, NULL);
        $$ = aux;
    }
    | Numero { $$ = $1; }
    | CHARACTER { 
        Expression *aux = createExpression(CHARACTER, yylval.token.valor, NULL, NULL);
        $$ = aux;
    }
    | STRING { 
        Expression *aux = createExpression(STRING, yylval.token.valor, NULL, NULL);
        $$ = aux;
    }
    | L_PAREN Expressao R_PAREN {
        $$ = $2;
    } ;

Numero: NUM_INT {
        Expression *aux = createExpression(NUM_INT, yylval.token.valor, NULL, NULL);
        $$ = aux;
    }
    | NUM_HEXA { 
        Expression *aux = createExpression(NUM_HEXA, yylval.token.valor, NULL, NULL);
        $$ = aux;
    }
    | NUM_OCTAL {
        Expression *aux = createExpression(NUM_OCTAL, yylval.token.valor, NULL, NULL);
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