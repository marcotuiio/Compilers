%option noyywrap
%option yylineno

%{
#include "ast.h"
#include "sintatico.tab.h"
extern YYSTYPE yylval;

int textBefore = 0;
int yycolumn = 1;

int syntaxError = 0;
char wrongToken[32] = "";
int wrongTokenLine;
int wrongTokenColumn;


void addToUnion(int type) {
    yylval.token.valor = strdup(yytext);
    yylval.token.type = type;
}

void assignWrongToken() {
    syntaxError = 1;
    strcpy(wrongToken, yytext);
}


%}

%%

<<EOF>> { return MyEOF; }

"+" { addToUnion(PLUS); return PLUS; }
"-" { addToUnion(MINUS); return MINUS; }
"*" { addToUnion(MULTIPLY); return MULTIPLY; }
"/" { addToUnion(DIVIDE); return DIVIDE; }
"^" { addToUnion(POWER); return POWER; }
"%" { addToUnion(REMAINDER); return REMAINDER; }
"=" { addToUnion(ASSIGN); return ASSIGN; }
";" { addToUnion(SEMICOLON); return SEMICOLON; }
"," { addToUnion(COMMA); return COMMA; }
":" { addToUnion(COLON); return COLON; }
":=" { addToUnion(COLON_ASSIGN); return COLON_ASSIGN; }
"(" { addToUnion(L_PAREN); return L_PAREN; }
")" { addToUnion(R_PAREN); return R_PAREN; }
"[" { addToUnion(L_SQUARE_BRACKET); return L_SQUARE_BRACKET; }
"]" { addToUnion(R_SQUARE_BRACKET); return R_SQUARE_BRACKET; }

"about" { addToUnion(ABOUT); return ABOUT; }
"abs" { addToUnion(ASIN); return ABS; }
"axis" { addToUnion(AXIS); return AXIS; }
"connect_dots" { addToUnion(CONNECT_DOTS); return CONNECT_DOTS; }
"cos" { addToUnion(COS); return COS; }
"determinant" { addToUnion(DETERMINANT); return DETERMINANT; }
"erase" { addToUnion(ERASE); return ERASE; }
"e"|"E" { addToUnion(E); return EULER; }
"float" { addToUnion(FLOAT); return FLOAT; }
"h_view" { addToUnion(H_VIEW); return H_VIEW; }
"integral_steps" { addToUnion(INTEGRAL_STEPS); return INTEGRAL_STEPS; }
"integrate" { addToUnion(INTEGRATE); return INTEGRATE; }
"linear_system" { addToUnion(LINEAR_SYSTEM); return LINEAR_SYSTEM; }
"matrix" { addToUnion(MATRIX); return MATRIX; }
"off" { addToUnion(OFF); return OFF; }
"on" { addToUnion(ON); return ON; }
("p"|"P")("i"|"I") { addToUnion(PI); return PI; }
"plot" { addToUnion(PLOT); return PLOT; }
"precision" { addToUnion(PRECISION); return PRECISION; }
"quit" { addToUnion(QUIT); return QUIT; }
"reset" { addToUnion(RESET); return RESET; }
"rpn" { addToUnion(RPN); return RPN; }
"sen" { addToUnion(SEN); return SEN; }
"set" { addToUnion(SET); return SET; }
"settings" { addToUnion(SETTINGS); return SETTINGS; }
"show" { addToUnion(SHOW); return SHOW; }
"solve" { addToUnion(SOLVE); return SOLVE; }
"sum" { addToUnion(SUM); return SUM; }
"symbols" { addToUnion(SYMBOLS); return SYMBOLS; }
"tan" { addToUnion(TAN); return TAN; }
"v_view" { addToUnion(V_VIEW); return V_VIEW; }

"x" { addToUnion(X); return VAR_X; }

\n { yycolumn = 1; if (syntaxError) return ERRO; }

([a-zA-Z]+[_a-zA-Z0-9]*) { 
    addToUnion(ID);
   
    return ID;
}
[0-9]+ { addToUnion(NUM_INT); return NUM_INT; }
([0-9]+"."[0-9]+) { addToUnion(NUM_FLOAT); return NUM_FLOAT; }

. { 
    if (textBefore) printf("\n");
    printf("error:lexical:%d:%d: %s", yylineno, yycolumn, yytext);
   
    deleteAuxFile();
    exit(1);
}

%%
