%option noyywrap
%option yylineno

%{

#include <sintatico.tab.h>
extern YYSTYPE yylval;

int textBefore = 0;
int yycolumn = 1;
int lineStart;
int columnStart;

int syntaxError = 0;
char wrongToken[32] = "";
int wrongTokenLine;
int wrongTokenColumn;

void addToUnion() {
    yylval.token.valor = strdup(yytext);
    yylval.token.column = yycolumn;
    yylval.token.line = yylineno;
}

%}

%%

<<EOF>> { return MyEOF; }

"int" { addToUnion(); yycolumn += strlen(yytext); return INT; } 
"char" { addToUnion(); yycolumn += strlen(yytext); return CHAR; }
"float" { addToUnion(); yycolumn += strlen(yytext); return FLOAT; }
"," { addToUnion(); yycolumn++; return COMMA; }
" " { addToUnion(); yycolumn++; }
\n { yycolumn = 1; return EOL; }
[a-z]+ { addToUnion(); yycolumn += strlen(yytext); return ID; }

. { 
    if (textBefore) printf("\n");
    printf("error:lexical:%d:%d: %s", yylineno, yycolumn, yytext);
    yycolumn += strlen(yytext);
    exit(1);
}

%%
