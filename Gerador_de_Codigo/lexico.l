%option noyywrap

%{
#include "ast.h"
// #include "asm.h"
#include "sintatico.tab.h"
extern YYSTYPE yylval;

extern FILE *mipsFile;
extern char *mipsPath;

void addToUnion(int type) {
    yylval.token.valor = strdup(yytext);
    yylval.token.type = type;
}

%}

%%

<<EOF>> { return MyEOF; }
"AST -->" { }

"GLOBAL" { addToUnion(GLOBAL); return GLOBAL; }
"VARIABLE" { addToUnion(VARIABLE); return VARIABLE; }
"CONSTANT" { addToUnion{CONSTANT}; return CONSTANT; }
"PARAMETER" { addToUnion{PARAMETER}; return PARAMETER; }
"VALUE" {addToUnion{VALUE}; return VALUE; }
"RETURN_TYPE" { addToUnion(RETURN_TYPE); return RETURN_TYPE; }
"TYPE" { addToUnion(TYPE); return TYPE; }
"void" { addToUnion(VOID); return VOID; }
"int" {  addToUnion(INT); return INT; } 
"char" { addToUnion(CHAR); return CHAR; }

"FUNCTION" { addToUnion(FUNCTION); return FUNCTION; }
"END_FUNCTION" { addToUnion(END_FUNCTION); return END_FUNCTION; }

"RETURN" { addToUnion(RETURN); return RETURN; }
"DO_WHILE" { addToUnion(DO); return DO; }
"WHILE" { addToUnion(WHILE); return WHILE; }
"FOR" { addToUnion(FOR); return FOR; }
"IF" { addToUnion(IF); return IF; }
"PRINTF" { addToUnion(PRINTF); return PRINTF; }
"SCANF" { addToUnion(SCANF); return SCANF; }
"EXIT" { addToUnion(EXIT); return EXIT; }

"+" { addToUnion(PLUS); return PLUS; }
"-" { addToUnion(MINUS); return MINUS; }
"*" { addToUnion(MULTIPLY); return MULTIPLY; }
"/" { addToUnion(DIVIDE); return DIVIDE; }
"%" { addToUnion(REMAINDER); return REMAINDER; }
"++" { addToUnion(INC); return INC; }
"--" { addToUnion(DEC); return DEC; }
"&" { addToUnion(BITWISE_AND); return BITWISE_AND; }
"|" { addToUnion(BITWISE_OR); return BITWISE_OR; }
"~" { addToUnion(BITWISE_NOT); return BITWISE_NOT; }
"^" { addToUnion(BITWISE_XOR); return BITWISE_XOR; }
"!" { addToUnion(NOT); return NOT; }
"&&" { addToUnion(LOGICAL_AND); return LOGICAL_AND; }
"||" { addToUnion(LOGICAL_OR); return LOGICAL_OR; }
"==" { addToUnion(EQUAL); return EQUAL; }
"!=" { addToUnion(NOT_EQUAL); return NOT_EQUAL; }
"<" { addToUnion(LESS_THAN); return LESS_THAN; }
">" { addToUnion(GREATER_THAN); return GREATER_THAN; }
"<=" { addToUnion(LESS_EQUAL); return LESS_EQUAL; }
">=" { addToUnion(GREATER_EQUAL); return GREATER_EQUAL; }
">>" { addToUnion(R_SHIFT); return R_SHIFT; }
"<<" { addToUnion(L_SHIFT); return L_SHIFT; }
"=" { addToUnion(ASSIGN); return ASSIGN; }
"+=" { addToUnion(ADD_ASSIGN); return ADD_ASSIGN; }
"-=" { addToUnion(MINUS_ASSIGN); return MINUS_ASSIGN; }
";" { addToUnion(SEMICOLON); return SEMICOLON; }
"," { addToUnion(COMMA); return COMMA; }
":" { addToUnion(COLON); return COLON; }
"(" { addToUnion(L_PAREN); return L_PAREN; }
")" { addToUnion(R_PAREN); return R_PAREN; }
"[" { addToUnion(L_SQUARE_BRACKET); return L_SQUARE_BRACKET; }
"]" { addToUnion(R_SQUARE_BRACKET); return R_SQUARE_BRACKET; }
"?" { addToUnion(TERNARY_CONDITIONAL); return TERNARY_CONDITIONAL; }

\"([^\\\"]|\\.)*\" { addToUnion(STRING); return STRING; }
" " { addToUnion(0); yycolumn++;  }
\n { }
\t { }

(_*[a-zA-Z][a-zA-Z0-9_]*) {
    // if (strlen(yytext) > 255) {
    //     if (textBefore) printf("\n");
    //     printf("error:lexical:%d:%d: identifier too long", yylineno, yycolumn);
       
    //     deleteMipsFileOnError(mipsFile, mipsPath);
    //     deleteAuxFile();
    //     exit(1);
    // } 
    addToUnion(ID);
    return ID;
}
"'"(\\.|[^\\']){1}"'" { addToUnion(CHARACTER); return CHARACTER; }
[0-9]+ { addToUnion(NUM_INT); return NUM_INT; }

. { 
    // if (textBefore) printf("\n");
    // printf("error:lexical:%d:%d: %s", yylineno, yycolumn, yytext);
   
    // deleteMipsFileOnError(mipsFile, mipsPath);
    // deleteAuxFile();
    // exit(1);
}

%%
