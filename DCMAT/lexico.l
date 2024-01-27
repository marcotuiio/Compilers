%option noyywrap
%option yylineno

%{
#include "ast.h"
#include "sintatico.tab.h"
extern YYSTYPE yylval;

int syntaxError = 0;
char wrongToken[32] = "";
int wrongTokenLine;
int wrongTokenColumn;

void assignWrongToken() {
    syntaxError = 1;
    strcpy(wrongToken, yytext);
}


%}

%%

\n { return EOL; }

" " { }
"+" { yylval.value = strdup(yytext); return PLUS; }
"-" { yylval.value = strdup(yytext); return MINUS; }
"*" { yylval.value = strdup(yytext); return MULTIPLY; }
"/" { yylval.value = strdup(yytext); return DIVIDE; }
"^" { yylval.value = strdup(yytext); return POWER; }
"%" { yylval.value = strdup(yytext); return REMAINDER; }
"=" { yylval.value = strdup(yytext); return ASSIGN; }
";" { yylval.value = strdup(yytext); return SEMICOLON; }
"," { yylval.value = strdup(yytext); return COMMA; }
":" { yylval.value = strdup(yytext); return COLON; }
":=" { yylval.value = strdup(yytext); return COLON_ASSIGN; }
"(" { yylval.value = strdup(yytext); return L_PAREN; }
")" { yylval.value = strdup(yytext); return R_PAREN; }
"[" { yylval.value = strdup(yytext); return L_SQUARE_BRACKET; }
"]" { yylval.value = strdup(yytext); return R_SQUARE_BRACKET; }

"about" { yylval.value = strdup(yytext); return ABOUT; }
"abs" { yylval.value = strdup(yytext); return ABS; }
"axis" { yylval.value = strdup(yytext); return AXIS; }
"connect_dots" { yylval.value = strdup(yytext); return CONNECT_DOTS; }
"cos" { yylval.value = strdup(yytext); return COS; }
"determinant" { yylval.value = strdup(yytext); return DETERMINANT; }
"erase" { yylval.value = strdup(yytext); return ERASE; }
"e"|"E" { yylval.value = strdup(yytext); return EULER; }
"float" { yylval.value = strdup(yytext); return FLOAT; }
"h_view" { yylval.value = strdup(yytext); return H_VIEW; }
"integral_steps" { yylval.value = strdup(yytext); return INTEGRAL_STEPS; }
"integrate" { yylval.value = strdup(yytext); return INTEGRATE; }
"linear_system" { yylval.value = strdup(yytext); return LINEAR_SYSTEM; }
"matrix" { yylval.value = strdup(yytext); return MATRIX; }
"off" {  yylval.value = strdup(yytext); return OFF; }
"on" { yylval.value = strdup(yytext); return ON; }
("p"|"P")("i"|"I") { yylval.value = strdup(yytext); return PI; }
"plot" { yylval.value = strdup(yytext); return PLOT; }
"precision" { yylval.value = strdup(yytext); return PRECISION; }
"quit" { yylval.value = strdup(yytext); return QUIT; }
"reset" { yylval.value = strdup(yytext); return RESET; }
"rpn" { yylval.value = strdup(yytext); return RPN; }
"sen" { yylval.value = strdup(yytext); return SEN; }
"set" { yylval.value = strdup(yytext); return SET; }
"settings" { yylval.value = strdup(yytext); return SETTINGS; }
"show" { yylval.value = strdup(yytext); return SHOW; }
"solve" { yylval.value = strdup(yytext); return SOLVE; }
"sum" { yylval.value = strdup(yytext); return SUM; }
"symbols" { yylval.value = strdup(yytext); return SYMBOLS; }
"tan" { yylval.value = strdup(yytext); return TAN; }
"v_view" { yylval.value = strdup(yytext); return V_VIEW; }

"x" { yylval.value = strdup(yytext); return VAR_X; }

([a-zA-Z]+[_a-zA-Z0-9]*) { yylval.value = strdup(yytext); return ID; }
([0-9]+"."[0-9]+) { yylval.value = strdup(yytext); return NUM_FLOAT; }
[0-9]+ { yylval.value = strdup(yytext); return NUM_INT; }

. { printf("\nInvalid Symbol: %s\n\n", yytext); /*return ERROR;*/ }

%%
