%{

#include <stdio.h>
#include <string.h>
extern int yylex();
extern char *yytext;
extern int textBefore;
extern int myEof;
void yyerror(void *s);

%}

%union {
    struct {
        void *valor;
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
    | Exp ERRO { return 0; }
    // | Exp ADD EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
    // | Exp SUB EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
    // | Exp MUL EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
    // | Exp DIV EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
    // | Exp POW EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
    // | Exp MOD EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
    // | Exp L_PAREN EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
    // | Exp R_PAREN EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
    // | Exp SEN EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
    // | Exp COS EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
    // | Exp TAN EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
    // | Exp ABS EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
    // | error { 
    //     if (textBefore) printf("\n");
    //     printf("Erro sinatico na coluna %d [%d]: %s", yylval.token.line, yylval.token.column, (char*)yylval.token.valor); 
    //     textBefore = 1; 
    //     yyerrok; 
    //     yyclearin; }
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
    if (textBefore) printf("\n");
    printf("%d Erro sinatico na coluna [%d][%d]: %s", yylval.token.type, yylval.token.line, yylval.token.column, (char*)yylval.token.valor);
    textBefore = 1;
    return;
}

int main(int argc, char* argv[]) {
    while (!myEof) yyparse();
    return 0;
}