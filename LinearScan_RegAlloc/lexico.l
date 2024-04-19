%option noyywrap

%{

#include "sintatico.tab.h"
extern YYSTYPE yylval;

%}

%% 

<<EOF>> { return MyEof; }
"K" { return K; }
"=" { return ASSIGN; }
"-->" { return ARROW; }
"vr"[0-9]+ { yylval = atoi(yytext+2); return REG_ID; }
[0-9]+ { yylval = atoi(yytext); return NUM_INT; }
"\n" { }
" " { }
. { }

%%