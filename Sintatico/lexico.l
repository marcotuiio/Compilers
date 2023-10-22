%option noyywrap
%option yylineno
%x COMMENT

%{

#include <sintatico.tab.h>
extern YYSTYPE yylval;

int textBefore = 0;
int yycolumn = 1;
int lineStart;
int columnStart;

char lineBuffer[2048] = "";

void clearLineBuffer() {
    for (int i = 0; i < 2048; i++) lineBuffer[i] = '\0';
}

void addToUnion() {
    yylval.token.valor = strdup(yytext);
    yylval.token.column = yycolumn;
    yylval.token.line = yylineno;
    if (yycolumn == 1) clearLineBuffer();
    strcat(lineBuffer, yytext);
}

%}

%%

"/*" { 
    BEGIN(COMMENT); 
    lineStart = yylineno;
    columnStart = yycolumn; 
    yycolumn += strlen(yytext);
    // strcat(lineBuffer, yytext);
}
<COMMENT>"*/" { // end comment
    BEGIN(INITIAL); 
    yycolumn += strlen(yytext);
    // strcat(lineBuffer, yytext); 
} 
<COMMENT>"/*" {  // nested comment
    char next = input();
    if (next == '\n') yylineno--;
    if (next == '/') { 
        BEGIN(INITIAL); 
        yycolumn += strlen(yytext) + 1; 
    } else {
        if (textBefore) printf("\n");
        printf("warning:%d:%d: '%s' within block comment", yylineno, yycolumn, yytext); 
        yycolumn += strlen(yytext);
        if (next == '\n') yylineno++;
        unput(next);
        textBefore = 1;
    }
}
<COMMENT>. { yycolumn += strlen(yytext); }
<COMMENT>\n { yycolumn = 1; }
<COMMENT><<EOF>> { 
    if (textBefore) printf("\n");
    printf("error:lexical:%d:%d: unterminated comment", lineStart, columnStart); 
    exit(1); 
}

<<EOF>> { return MyEOF; }

"//".* { addToUnion(); }
"void" { addToUnion(); yycolumn += strlen(yytext); return VOID; }
"int" {  addToUnion(); yycolumn += strlen(yytext); return INT; } 
"char" { addToUnion(); yycolumn += strlen(yytext); return CHAR; }
"return" { addToUnion(); yycolumn += strlen(yytext); return RETURN; }
"break" { addToUnion(); yycolumn += strlen(yytext); return ERRO; }
"switch" { addToUnion(); yycolumn += strlen(yytext); return ERRO; }
"case" { addToUnion(); yycolumn += strlen(yytext); return ERRO; }
"default" { addToUnion(); yycolumn += strlen(yytext); return ERRO; }
"do" { addToUnion(); yycolumn += strlen(yytext); return DO; }
"while" { addToUnion(); yycolumn += strlen(yytext); return WHILE; }
"for" { addToUnion(); yycolumn += strlen(yytext); return FOR; }
"if" { addToUnion(); yycolumn += strlen(yytext); return IF; }
"else" { addToUnion(); yycolumn += strlen(yytext); return ELSE; }
"typedef" { addToUnion(); yycolumn += strlen(yytext); return ERRO; }
"struct" { addToUnion(); yycolumn += strlen(yytext); return ERRO; }
"+" { addToUnion(); yycolumn += strlen(yytext); return PLUS; }
"-" { addToUnion(); yycolumn += strlen(yytext); return MINUS; }
"*" { addToUnion(); yycolumn += strlen(yytext); return MULTIPLY; }
"/" { addToUnion(); yycolumn += strlen(yytext); return DIVIDE; }
"%" { addToUnion(); yycolumn += strlen(yytext); return REMAINDER; }
"++" { addToUnion(); yycolumn += strlen(yytext); return INC; }
"--" { addToUnion(); yycolumn += strlen(yytext); return DEC; }
"&" { addToUnion(); yycolumn += strlen(yytext); return BITWISE_AND; }
"|" { addToUnion(); yycolumn += strlen(yytext); return BITWISE_OR; }
"~" { addToUnion(); yycolumn += strlen(yytext); return BITWISE_NOT; }
"^" { addToUnion(); yycolumn += strlen(yytext); return BITWISE_XOR; }
"!" { addToUnion(); yycolumn += strlen(yytext); return NOT; }
"&&" { addToUnion(); yycolumn += strlen(yytext); return LOGICAL_AND; }
"||" { addToUnion(); yycolumn += strlen(yytext); return LOGICAL_OR; }
"==" { addToUnion(); yycolumn += strlen(yytext); return EQUAL; }
"!=" { addToUnion(); yycolumn += strlen(yytext); return NOT_EQUAL; }
"<" { addToUnion(); yycolumn += strlen(yytext); return LESS_THAN; }
">" { addToUnion(); yycolumn += strlen(yytext); return GREATER_THAN; }
"<=" { addToUnion(); yycolumn += strlen(yytext); return LESS_EQUAL; }
">=" { addToUnion(); yycolumn += strlen(yytext); return GREATER_EQUAL; }
">>" { addToUnion(); yycolumn += strlen(yytext); return R_SHIFT; }
"<<" { addToUnion(); yycolumn += strlen(yytext); return L_SHIFT; }
"=" { addToUnion(); yycolumn += strlen(yytext); return ASSIGN; }
"+=" { addToUnion(); yycolumn += strlen(yytext); return ADD_ASSIGN; }
"-=" { addToUnion(); yycolumn += strlen(yytext); return MINUS_ASSIGN; }
";" { addToUnion(); yycolumn += strlen(yytext); return SEMICOLON; }
"," { addToUnion(); yycolumn += strlen(yytext); return COMMA; }
":" { addToUnion(); yycolumn += strlen(yytext); return COLON; }
"(" { addToUnion(); yycolumn += strlen(yytext); return L_PAREN; }
")" { addToUnion(); yycolumn += strlen(yytext); return R_PAREN; }
"{" { addToUnion(); yycolumn += strlen(yytext); return L_CURLY_BRACKET; }
"}" { addToUnion(); yycolumn += strlen(yytext); return R_CURLY_BRACKET; }
"[" { addToUnion(); yycolumn += strlen(yytext); return L_SQUARE_BRACKET; }
"]" { addToUnion(); yycolumn += strlen(yytext); return R_SQUARE_BRACKET; }
"?" { addToUnion(); yycolumn += strlen(yytext); return TERNARY_CONDITIONAL; }
"#" { addToUnion(); yycolumn += strlen(yytext); return NUMBER_SIGN; }
"->" { addToUnion(); yycolumn += strlen(yytext); return ERRO; }
"printf" { addToUnion(); yycolumn += strlen(yytext); return PRINTF; }
"scanf" { addToUnion(); yycolumn += strlen(yytext); return SCANF; }
"define" { addToUnion(); yycolumn += strlen(yytext); return DEFINE; }
"exit" { addToUnion(); yycolumn += strlen(yytext); return EXIT; }

\"([^\\\"]|\\.)*\" { /* (\".*\") */
    addToUnion();
    yycolumn += strlen(yytext);
    return STRING;
}
" " { addToUnion(); yycolumn++;  }
\n { yycolumn = 1; }
(_*[a-zA-Z][a-zA-Z0-9_]*) {
    if (strlen(yytext) > 255) {
        if (textBefore) printf("\n");
        printf("error:lexical:%d:%d: identifier too long", yylineno, yycolumn);
        yycolumn += strlen(yytext);
        exit(1);
    } 
    addToUnion();
    yycolumn += strlen(yytext);
    return ID;
}
"'"(\\.|[^\\']){1}"'" {
    addToUnion();
    yycolumn += strlen(yytext);
    return CHARACTER;
}
(0x[0-9a-f]+)|(0X[0-9A-F]+) {
    addToUnion();
    yycolumn += strlen(yytext);
    return NUM_HEXA;
}
0[1-7][0-7]* {
    addToUnion();
    yycolumn += strlen(yytext);
    return NUM_OCTAL;
}
[0-9]+ {
    addToUnion();
    yycolumn += strlen(yytext);
    return NUM_INT;
}
. { 
    if (textBefore) printf("\n");
    printf("error:lexical:%d:%d: %s", yylineno, yycolumn, yytext);
    yycolumn += strlen(yytext);
    exit(1);
}

%%
