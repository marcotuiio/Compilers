%option noyywrap
%option yylineno

%{
#include "sintatico.tab.h"
extern YYSTYPE yylval;

int textBefore = 0;
int yycolumn = 1;

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
" " { }
"+" { return PLUS; }
"-" { return MINUS; }
"*" { return MULTIPLY; }
"/" { return DIVIDE; }
"^" { return POWER; }
"%" { return REMAINDER; }
"=" { return ASSIGN; }
";" { return SEMICOLON; }
"," { return COMMA; }
":" { return COLON; }
":=" { return COLON_ASSIGN; }
"(" { return L_PAREN; }
")" { return R_PAREN; }
"[" { return L_SQUARE_BRACKET; }
"]" { return R_SQUARE_BRACKET; }

"about" { return ABOUT; }
"abs" { return ABS; }
"axis" { return AXIS; }
"connect_dots" { return CONNECT_DOTS; }
"cos" { return COS; }
"determinant" { return DETERMINANT; }
"erase" { return ERASE; }
"e"|"E" { return EULER; }
"float" { return FLOAT; }
"h_view" { return H_VIEW; }
"integral_steps" {  return INTEGRAL_STEPS; }
"integrate" { return INTEGRATE; }
"linear_system" { return LINEAR_SYSTEM; }
"matrix" { return MATRIX; }
"off" {  return OFF; }
"on" { return ON; }
("p"|"P")("i"|"I") { return PI; }
"plot" { return PLOT; }
"precision" { return PRECISION; }
"quit" { return QUIT; }
"reset" { return RESET; }
"rpn" { return RPN; }
"sen" { return SEN; }
"set" { return SET; }
"settings" { return SETTINGS; }
"show" { return SHOW; }
"solve" { return SOLVE; }
"sum" { return SUM; }
"symbols" { return SYMBOLS; }
"tan" { return TAN; }
"v_view" { return V_VIEW; }

"x" { return VAR_X; }

\n { return EOL; }

([a-zA-Z]+[_a-zA-Z0-9]*) { return ID; }
[0-9]+ { return NUM_INT; }
([0-9]+"."[0-9]+) { return NUM_FLOAT; }

. { 
    // if (textBefore) printf("\n");
    printf("Invalid Symbol: %s", yytext);
    // exit(1);
}

%%
