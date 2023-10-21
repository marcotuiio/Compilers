%{

#include <stdio.h>
#include <string.h>
extern int yylex();
extern char *yytext;
extern int textBefore;
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

%start Start

%%

Start: Exp EOL { if (textBefore) printf("\n"); printf("EXPRESSAO CORRETA"); textBefore = 1; return 0; }
    | Exp ERRO { erroAux = 1; return 0; }
    // | error { return 0; }
    // | Exp ADD EOL { if (textBefore) printf("\n"); printf("A expressao terminou de forma inesperada."); textBefore = 1; }
;


%%

void yyerror(void *s) {
    if (erroAux || erroLexico) return;
    if (textBefore) printf("\n");
    printf("%d Erro sinatico na coluna [%d][%d]: %s", yylval.token.type, yylval.token.line, yylval.token.column, yylval.token.valor);
    textBefore = 1;
    erroAux = 0;
}

int main(int argc, char* argv[]) {
    while (!myEof) yyparse();
    return 0;
}