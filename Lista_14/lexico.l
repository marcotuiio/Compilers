%option noyywrap
%option yylineno

%{

#include <stdlib.h>
#include <string.h>
#include <sintatico.tab.h>

extern YYSTYPE yylval;

int myEof = 0;
int yycolumn = 1;
int erroLexico = 0;
int textBefore = 0;
char invalidos[256] = "";

void printErro() {
    if (textBefore) printf("\n");
    printf("Caractere(s) invalido(s) -> [%s]", invalidos);
    textBefore = 1;
    for (int i = 0; i < 256; i++) invalidos[i] = '\0'; 
    erroLexico = 0;
}

void addToUnion() {
    yylval.token.valor = strdup(yytext);
    yylval.token.column = yycolumn;
    yylval.token.line = yylineno;
}

%}

%%

<<EOF>> { 
    myEof = 1;      
    if (erroLexico) {
        printErro();
        return ERRO;
    } 
    return EOL; }

\n { 
    yycolumn = 1; 
    if (erroLexico) {
        printErro();
        return ERRO; 
    }
    return EOL; }

[ \t] { yycolumn += strlen(yytext); }

[+-]?(([0-9]+"."[0-9]*)|([0-9]*"."[0-9]+)) {
    addToUnion();
    yylval.token.type = REAL;
    yycolumn += strlen(yytext);
    return REAL; }

[+-]?[0-9]+ { 
    addToUnion();
    yylval.token.type = INT;
    yycolumn += strlen(yytext); 
    return INT; }

"+" {
    addToUnion();
    yylval.token.type = ADD;
    yycolumn += strlen(yytext); 
    return ADD; }

"-" {
    addToUnion(); 
    yylval.token.type = SUB;
    yycolumn += strlen(yytext); 
    return SUB; }

"*" {
    addToUnion(); 
    yylval.token.type = MUL;
    yycolumn += strlen(yytext); 
    return MUL; }

"/" {
    addToUnion(); 
    yylval.token.type = DIV;
    yycolumn += strlen(yytext); 
    return DIV; }

"^" {
    addToUnion(); 
    yylval.token.type = POW;
    yycolumn += strlen(yytext); 
    return POW; }

"%" {
    addToUnion(); 
    yylval.token.type = MOD;
    yycolumn += strlen(yytext); 
    return MOD; }

"(" {
    addToUnion(); 
    yylval.token.type = L_PAREN;
    yycolumn += strlen(yytext); 
    return L_PAREN; }

")" {
    addToUnion(); 
    yylval.token.type = R_PAREN;
    yycolumn += strlen(yytext); 
    return R_PAREN; }

"sen" {
    addToUnion(); 
    yylval.token.type = SEN;
    yycolumn += strlen(yytext); 
    return SEN; }

"cos" {
    addToUnion(); 
    yylval.token.type = COS;
    yycolumn += strlen(yytext); 
    return COS; }

"tan" {
    addToUnion(); 
    yylval.token.type = TAN;
    yycolumn += strlen(yytext); 
    return TAN; }

"abs" {
    addToUnion(); 
    yylval.token.type = ABS;
    yycolumn += strlen(yytext); 
    return ABS; }

([a-zA-Z]+[a-zA-Z0-9]*) {
    addToUnion();
    yylval.token.type = ID;
    yycolumn += strlen(yytext); 
    return ID; }

. { 
    erroLexico = 1; 
    if (strlen(invalidos) != 0) invalidos[strlen(invalidos)] = ','; 
    invalidos[strlen(invalidos)] = yytext[0];
    yycolumn += strlen(yytext);
}

%%
