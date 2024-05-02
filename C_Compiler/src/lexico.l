%option noyywrap
%option yylineno
%x COMMENT

%{
#include "ast.h"
#include "asm.h"
#include "sintatico.tab.h"
extern YYSTYPE yylval;

int textBefore = 0;
int yycolumn = 1;
int lineStart;
int columnStart;

int syntaxError = 0;
char wrongToken[32] = "";
int wrongTokenLine;
int wrongTokenColumn;

char lineBuffer[2048] = "";
FILE *auxFile;

extern FILE *mipsFile;
extern char *mipsPath;

void addToUnion(int type) {
    yylval.token.valor = strdup(yytext);
    yylval.token.column = yycolumn;
    yylval.token.line = yylineno;
    yylval.token.type = type;
}

void assignWrongToken() {
    syntaxError = 1;
    strcpy(wrongToken, yytext);
    wrongTokenLine = yylineno;
    wrongTokenColumn = yycolumn;
}

void readInputIntoAuxFile(FILE *srcFile) {
    auxFile = fopen("tempfile.txt", "w+");
    if (auxFile == NULL) {
        printf("Error: Unable to create temporary file\n");
        return;
    }
    // ====> USE THIS WHEN IS PASSED FROM THE STDIN
    // char ch;
    // while ((ch = fgetc(stdin)) != EOF) {
    //     fputc(ch, auxFile);
    // }
    // rewind(auxFile);
    // fseek(stdin, 0, SEEK_SET);

    // ====> USE THIS WHEN ITS A FILE PASSED AS ARGUMENT
    char line[2048];
    while (fgets(line, sizeof(line), srcFile) != NULL) {
        fputs(line, auxFile);
    }
    rewind(auxFile);
    fseek(srcFile, 0, SEEK_SET);
}

void getLineBuffer(int nline) {
    fseek(auxFile, 0, SEEK_SET);
    for (int i = 0; i < nline; i++) {
        fgets(lineBuffer, 2048, auxFile);
    }
    if (lineBuffer[0] == '\n') lineBuffer[0] = ' ';
    if (lineBuffer[strlen(lineBuffer) - 1] == '\n') lineBuffer[strlen(lineBuffer) - 1] = '\0';
}

void deleteAuxFile() {
    printf("\n");
    fclose(auxFile);
    remove("tempfile.txt");
}

%}

%%

"/*" { 
    BEGIN(COMMENT); 
    addToUnion(0);
    lineStart = yylineno;
    columnStart = yycolumn; 
    yycolumn += strlen(yytext);
}
<COMMENT>"*/" { // end comment
    BEGIN(INITIAL);
    yycolumn += strlen(yytext);
    addToUnion(0); 
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
<COMMENT>. { addToUnion(0); yycolumn += strlen(yytext); }
<COMMENT>\n { yycolumn = 1; }
<COMMENT><<EOF>> { 
    if (textBefore) printf("\n");
    printf("error:lexical:%d:%d: unterminated comment", lineStart, columnStart);
    deleteMipsFileOnError(mipsFile, mipsPath);
    deleteAuxFile();
    exit(1); 
}

<<EOF>> { return MyEOF; }

"//".* { addToUnion(0); }
"void" { addToUnion(VOID); yycolumn += strlen(yytext); return VOID; }
"int" {  addToUnion(INT); yycolumn += strlen(yytext); return INT; } 
"char" { addToUnion(CHAR); yycolumn += strlen(yytext); return CHAR; }
"return" { addToUnion(RETURN); yycolumn += strlen(yytext); return RETURN; }
"break" { assignWrongToken(); yycolumn += strlen(yytext); }
"switch" { assignWrongToken(); yycolumn += strlen(yytext); }
"case" { assignWrongToken(); yycolumn += strlen(yytext); }
"default" { assignWrongToken(); yycolumn += strlen(yytext); }
"do" { addToUnion(DO); yycolumn += strlen(yytext); return DO; }
"while" { addToUnion(WHILE); yycolumn += strlen(yytext); return WHILE; }
"for" { addToUnion(FOR); yycolumn += strlen(yytext); return FOR; }
"if" { addToUnion(IF); yycolumn += strlen(yytext); return IF; }
"else" { addToUnion(ELSE); yycolumn += strlen(yytext); return ELSE; }
"typedef" { assignWrongToken(); yycolumn += strlen(yytext); }
"struct" { assignWrongToken(); yycolumn += strlen(yytext); }
"+" { addToUnion(PLUS); yycolumn += strlen(yytext); return PLUS; }
"-" { addToUnion(MINUS); yycolumn += strlen(yytext); return MINUS; }
"*" { addToUnion(MULTIPLY); yycolumn += strlen(yytext); return MULTIPLY; }
"/" { addToUnion(DIVIDE); yycolumn += strlen(yytext); return DIVIDE; }
"%" { addToUnion(REMAINDER); yycolumn += strlen(yytext); return REMAINDER; }
"++" { addToUnion(INC); yycolumn += strlen(yytext); return INC; }
"--" { addToUnion(DEC); yycolumn += strlen(yytext); return DEC; }
"&" { addToUnion(BITWISE_AND); yycolumn += strlen(yytext); return BITWISE_AND; }
"|" { addToUnion(BITWISE_OR); yycolumn += strlen(yytext); return BITWISE_OR; }
"~" { addToUnion(BITWISE_NOT); yycolumn += strlen(yytext); return BITWISE_NOT; }
"^" { addToUnion(BITWISE_XOR); yycolumn += strlen(yytext); return BITWISE_XOR; }
"!" { addToUnion(NOT); yycolumn += strlen(yytext); return NOT; }
"&&" { addToUnion(LOGICAL_AND); yycolumn += strlen(yytext); return LOGICAL_AND; }
"||" { addToUnion(LOGICAL_OR); yycolumn += strlen(yytext); return LOGICAL_OR; }
"==" { addToUnion(EQUAL); yycolumn += strlen(yytext); return EQUAL; }
"!=" { addToUnion(NOT_EQUAL); yycolumn += strlen(yytext); return NOT_EQUAL; }
"<" { addToUnion(LESS_THAN); yycolumn += strlen(yytext); return LESS_THAN; }
">" { addToUnion(GREATER_THAN); yycolumn += strlen(yytext); return GREATER_THAN; }
"<=" { addToUnion(LESS_EQUAL); yycolumn += strlen(yytext); return LESS_EQUAL; }
">=" { addToUnion(GREATER_EQUAL); yycolumn += strlen(yytext); return GREATER_EQUAL; }
">>" { addToUnion(R_SHIFT); yycolumn += strlen(yytext); return R_SHIFT; }
"<<" { addToUnion(L_SHIFT); yycolumn += strlen(yytext); return L_SHIFT; }
"=" { addToUnion(ASSIGN); yycolumn += strlen(yytext); return ASSIGN; }
"+=" { addToUnion(ADD_ASSIGN); yycolumn += strlen(yytext); return ADD_ASSIGN; }
"-=" { addToUnion(MINUS_ASSIGN); yycolumn += strlen(yytext); return MINUS_ASSIGN; }
";" { addToUnion(SEMICOLON); yycolumn += strlen(yytext); return SEMICOLON; }
"," { addToUnion(COMMA); yycolumn += strlen(yytext); return COMMA; }
":" { addToUnion(COLON); yycolumn += strlen(yytext); return COLON; }
"(" { addToUnion(L_PAREN); yycolumn += strlen(yytext); return L_PAREN; }
")" { addToUnion(R_PAREN); yycolumn += strlen(yytext); return R_PAREN; }
"{" { addToUnion(L_CURLY_BRACKET); yycolumn += strlen(yytext); return L_CURLY_BRACKET; }
"}" { addToUnion(R_CURLY_BRACKET); yycolumn += strlen(yytext); return R_CURLY_BRACKET; }
"[" { addToUnion(L_SQUARE_BRACKET); yycolumn += strlen(yytext); return L_SQUARE_BRACKET; }
"]" { addToUnion(R_SQUARE_BRACKET); yycolumn += strlen(yytext); return R_SQUARE_BRACKET; }
"?" { addToUnion(TERNARY_CONDITIONAL); yycolumn += strlen(yytext); return TERNARY_CONDITIONAL; }
"#" { addToUnion(NUMBER_SIGN); yycolumn += strlen(yytext); return NUMBER_SIGN; }
"->" { assignWrongToken(); yycolumn += strlen(yytext); }
"printf" { addToUnion(PRINTF); yycolumn += strlen(yytext); return PRINTF; }
"scanf" { addToUnion(SCANF); yycolumn += strlen(yytext); return SCANF; }
"define" { addToUnion(DEFINE); yycolumn += strlen(yytext); return DEFINE; }
"exit" { addToUnion(EXIT); yycolumn += strlen(yytext); return EXIT; }

\"([^\\\"]|\\.)*\" { addToUnion(STRING); yycolumn += strlen(yytext); return STRING; }
" " { addToUnion(0); yycolumn++;  }
\n { yycolumn = 1; if (syntaxError) return ERRO; }
(_*[a-zA-Z][a-zA-Z0-9_]*) {
    if (strlen(yytext) > 255) {
        if (textBefore) printf("\n");
        printf("error:lexical:%d:%d: identifier too long", yylineno, yycolumn);
        yycolumn += strlen(yytext);
        deleteMipsFileOnError(mipsFile, mipsPath);
        deleteAuxFile();
        exit(1);
    } 
    addToUnion(ID);
    yycolumn += strlen(yytext);
    return ID;
}
"'"(\\.|[^\\']){1}"'" { addToUnion(CHARACTER); yycolumn += strlen(yytext); return CHARACTER; }
(0x[0-9a-f]+)|(0X[0-9A-F]+) { addToUnion(NUM_HEXA); yycolumn += strlen(yytext); return NUM_HEXA; }
0[1-7][0-7]* { addToUnion(NUM_OCTAL); yycolumn += strlen(yytext); return NUM_OCTAL; }
[0-9]+ { addToUnion(NUM_INT); yycolumn += strlen(yytext); return NUM_INT; }

. { 
    if (textBefore) printf("\n");
    printf("error:lexical:%d:%d: %s", yylineno, yycolumn, yytext);
    yycolumn += strlen(yytext);
    deleteMipsFileOnError(mipsFile, mipsPath);
    deleteAuxFile();
    exit(1);
}

%%
