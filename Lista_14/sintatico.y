%{

#include <stdio.h>
#include <string.h>
extern int yylex();
extern char *yytext;
extern int textBefore;
extern int yychar;
extern int myEof;
extern int erroLexico;
int erroAux = 0;
void yyerror(void *s);

%}

%union {
    struct {
        char *valor;
        int column;
        int line;
        int type;
    } token;
}

%token EOL
%token ADD
%token SUB
%token MUL
%token DIV
%token POW
%token MOD
%token L_PAREN
%token R_PAREN
%token SEN
%token COS
%token TAN
%token ABS
%token ID
%token REAL
%token INT
%token ERRO

%start Start

%left '+' '-'
%left '*' '/'
%right '^'

%%

/* 
Start -> Exp EOL
Exp -> Fator
Exp -> Exp ADD Fator
Exp -> Exp SUB Fator
Fator -> Termo
Fator -> Fator MUL Termo
Fator -> Fator DIV Termo
Fator -> Fator POW Termo
Fator -> Fator MOD Termo
Termo ->  L_PAREN Exp R_PAREN
Termo -> SEN L_PAREN Exp R_PAREN
Termo -> COS L_PAREN Exp R_PAREN
Termo -> TAN L_PAREN Exp R_PAREN
Termo -> ABS L_PAREN Exp R_PAREN
Termo -> ID
Termo -> INT
Termo -> REAL
*/

Start: Exp EOL { if (textBefore) printf("\n"); printf("EXPRESSAO CORRETA"); textBefore = 1; return 0; }
    | Exp ERRO { erroAux = 1; return 0; }
    // | error { return 0; }
    // | Exp ADD EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
;

Exp: Fator { }
    | Exp ADD Fator { } 
    | Exp SUB Fator { }
;

Fator: Termo { }
    | Fator MUL Termo { }
    | Fator DIV Termo { }
    | Fator POW Termo { }
    | Fator MOD Termo { }
;

Termo: L_PAREN Exp R_PAREN { } 
    | ID { }
    | INT { }
    | REAL { }
    | SEN L_PAREN Exp R_PAREN { }
    | COS L_PAREN Exp R_PAREN { }
    | TAN L_PAREN Exp R_PAREN { }
    | ABS L_PAREN Exp R_PAREN { }
    | ADD Termo { }
    | SUB Termo { }
;

%%

void yyerror(void *s) {
    if (erroAux || erroLexico) return;
    if (textBefore) printf("\n");
    if (yychar == EOL) {
        printf("A expressao terminou de forma inesperada.");
    } else {
        printf("%d Erro sinatico na coluna [%d][%d]: %s", yylval.token.type, yylval.token.line, yylval.token.column, yylval.token.valor);
    }
    textBefore = 1;
    erroAux = 0;
}

int main(int argc, char* argv[]) {
    while (!myEof) yyparse();
    return 0;
}