%option noyywrap

%{

#include "sintatico.tab.h"
extern YYSTYPE yylval;

%}

%% 
<<EOF>> { return MyEof; }
"Grafo" { return GRAFO; }
"K" { return K; }
"=" { return ASSIGN; }
":" { return COLON; }
"-->" { return ARROW; }
[0-9]+ { yylval = atoi(yytext); return REG; }

[ \t\n] { }
. { }

%%