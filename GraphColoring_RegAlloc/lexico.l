%option noyywrap

%{

#include "sintatico.tab.h"
extern YYSTYPE yylval;

/*
    Careful with this because IT NEEDS the token for \n. if you dont add it the 
    next vertex id will be accounted as another edge for the previous vertex
*/

%}

%% 

<<EOF>> { return MyEof; }
"\n" { return MyEol; }
"Grafo" { return GRAFO; }
"K" { return K; }
"=" { return ASSIGN; }
":" { return COLON; }
"-->" { return ARROW; }
[0-9]+ { yylval = atoi(yytext); return NUM_INT; }
"\t" { }
" " { }
. { }

%%