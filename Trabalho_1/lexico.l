%option noyywrap
%option yylineno
%x COMMENT
%{
int textBefore = 0;
int yycolumn = 1;
int lineStart;
int columnStart;

void printToken(char *token, int *textBefore) {
    if (*textBefore) printf("\n");
    printf("%s", token);
    *textBefore = 1;
}

%}

%%

"/*" { 
    BEGIN(COMMENT); 
    lineStart = yylineno;
    columnStart = yycolumn; 
    yycolumn += strlen(yytext); 
}
<COMMENT>"*/" { // end comment
    BEGIN(INITIAL); 
    yycolumn += strlen(yytext); 
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
    }
    textBefore = 1;
}
<COMMENT>. { yycolumn += strlen(yytext); }
<COMMENT>\n { yycolumn = 1; }
<COMMENT><<EOF>> { 
    if (textBefore) printf("\n");
    printf("error:lexical:%d:%d: unterminated comment", lineStart, columnStart); 
    exit(1); 
}
"//".*\n { /*ignore */ }
"void" {
    printToken("VOID", &textBefore);
    yycolumn += strlen(yytext); 
}
"int" { 
    printToken("INT", &textBefore);
    yycolumn += strlen(yytext); 
}
"char" {
    printToken("CHAR", &textBefore);
    yycolumn += strlen(yytext);
}
"return" {
    printToken("RETURN", &textBefore);
    yycolumn += strlen(yytext);
}
"break" {
    printToken("BREAK", &textBefore);
    yycolumn += strlen(yytext); 
}
"switch" {
    printToken("SWITCH", &textBefore);
    yycolumn += strlen(yytext);
}
"case" {
    printToken("CASE", &textBefore);
    yycolumn += strlen(yytext);
}
"default" {
    printToken("DEFAULT", &textBefore);
    yycolumn += strlen(yytext);
}
"do" {
    printToken("DO", &textBefore);
    yycolumn += strlen(yytext);
}
"while" {
    printToken("WHILE", &textBefore);
    yycolumn += strlen(yytext);
}
"for" {
    printToken("FOR", &textBefore);
    yycolumn += strlen(yytext);
}
"if" {
    printToken("IF", &textBefore);
    yycolumn += strlen(yytext);
}
"else" {
    printToken("ELSE", &textBefore);
    yycolumn += strlen(yytext);
}
"typedef" {
    printToken("TYPEDEF", &textBefore);
    yycolumn += strlen(yytext);
}
"struct" {
    printToken("STRUCT", &textBefore);
    yycolumn += strlen(yytext);
}
"+" {
    printToken("PLUS", &textBefore);
    yycolumn += strlen(yytext);
}
"-" {
    printToken("MINUS", &textBefore);
    yycolumn += strlen(yytext);
}
"*" {
    printToken("MULTIPLY", &textBefore);
    yycolumn += strlen(yytext);
}
"/" {
    printToken("DIV", &textBefore);
    yycolumn += strlen(yytext);
}
"%" {
    printToken("REMAINDER", &textBefore);
    yycolumn += strlen(yytext);
}
"++" {
    printToken("INC", &textBefore);
    yycolumn += strlen(yytext);
}
"--" {
    printToken("DEC", &textBefore);
    yycolumn += strlen(yytext);
}
"&" {
    printToken("BITWISE_AND", &textBefore);
    yycolumn += strlen(yytext);
}
"|" {
    printToken("BITWISE_OR", &textBefore);
    yycolumn += strlen(yytext);
}
"~" {
    printToken("BITWISE_NOT", &textBefore);
    yycolumn += strlen(yytext);
}
"^" {
    printToken("BITWISE_XOR", &textBefore);
    yycolumn += strlen(yytext);
}
"!" {
    printToken("NOT", &textBefore);
    yycolumn += strlen(yytext);
}
"&&" {
    printToken("LOGICAL_AND", &textBefore);
    yycolumn += strlen(yytext);
}
"||" {
    printToken("LOGICAL_OR", &textBefore);
    yycolumn += strlen(yytext);
}
"==" {
    printToken("EQUAL", &textBefore);
    yycolumn += strlen(yytext);
}
"!=" {
    printToken("NOT_EQUAL", &textBefore);
    yycolumn += strlen(yytext);
}
"<" {
    printToken("LESS_THAN", &textBefore);
    yycolumn += strlen(yytext);
}
">" {
    printToken("GREATER_THAN", &textBefore);
    yycolumn += strlen(yytext);
}
"<=" {
    printToken("LESS_EQUAL", &textBefore);
    yycolumn += strlen(yytext);
}
">=" {
    printToken("GREATER_EQUAL", &textBefore);
    yycolumn += strlen(yytext);
}
">>" {
    printToken("R_SHIFT", &textBefore);
    yycolumn += strlen(yytext);
}
"<<" {
    printToken("L_SHIFT", &textBefore);
    yycolumn += strlen(yytext);
}
"=" {
    printToken("ASSIGN", &textBefore);
    yycolumn += strlen(yytext);
}
"+=" {
    printToken("ADD_ASSIGN", &textBefore);
    yycolumn += strlen(yytext);
}
"-=" {
    printToken("MINUS_ASSIGN", &textBefore);
    yycolumn += strlen(yytext);
}
";" {
    printToken("SEMICOLON", &textBefore);
    yycolumn += strlen(yytext);
}
"," {
    printToken("COMMA", &textBefore);
    yycolumn += strlen(yytext);
}
":" {
    printToken("COLON", &textBefore);
    yycolumn += strlen(yytext);
}
"(" {
    printToken("L_PAREN", &textBefore);
    yycolumn += strlen(yytext);
}
")" {
    printToken("R_PAREN", &textBefore);
    yycolumn += strlen(yytext);
}
"{" {
    printToken("L_CURLY_BRACKET", &textBefore);
    yycolumn += strlen(yytext);
}
"}" {
    printToken("R_CURLY_BRACKET", &textBefore);
    yycolumn += strlen(yytext);
}
"[" {
    printToken("L_SQUARE_BRACKET", &textBefore);
    yycolumn += strlen(yytext);
}
"]" {
    printToken("R_SQUARE_BRACKET", &textBefore);
    yycolumn += strlen(yytext);
}
"?" {
    printToken("TERNARY_CONDITIONAL", &textBefore);
    yycolumn += strlen(yytext);
}
"#" {
    printToken("NUMBER_SIGN", &textBefore);
    yycolumn += strlen(yytext);
}
"->" {
    printToken("POINTER", &textBefore);
    yycolumn += strlen(yytext);
}
"printf" {
    printToken("PRINTF", &textBefore);
    yycolumn += strlen(yytext);
}
"scanf" {
    printToken("SCANF", &textBefore);
    yycolumn += strlen(yytext);
}
"define" {
    printToken("DEFINE", &textBefore);
    yycolumn += strlen(yytext);
}
"exit" {
    printToken("EXIT", &textBefore);
    yycolumn += strlen(yytext);
}
\"([^\\\"]|\\.)*\" { /* (\".*\") */
    if (textBefore) printf("\n");
    printf("STRING(%.*s)", (int)(strlen(yytext) - 2), yytext + 1); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
" " { yycolumn++; }
\n { yycolumn = 1; }
(_*[a-zA-Z][a-zA-Z0-9_]*) {
    if (textBefore) printf("\n");
    if (strlen(yytext) > 255) {
        printf("error:lexical:%d:%d: identifier too long", yylineno, yycolumn);
    } else {
        printf("IDENTIFIER(%s)", yytext);  
    }
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"'"(\\.|[^\\']){1}"'" {
    if (textBefore) printf("\n");
    printf("CHARACTER(%.*s)", (int)(strlen(yytext) - 2), yytext + 1); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
(0x[0-9a-f]+)|(0X[0-9A-F]+) {
    if (textBefore) printf("\n");
    printf("NUM_HEXA(%s)", yytext);
    textBefore = 1;
    yycolumn += strlen(yytext);
}
0[1-7][0-7]* {
    if (textBefore) printf("\n");
    printf("NUM_OCTAL(%s)", yytext);
    textBefore = 1;
    yycolumn += strlen(yytext);
}
[0-9]+ {
    if (textBefore) printf("\n");
    printf("NUM_INTEGER(%s)", yytext);
    textBefore = 1;
    yycolumn += strlen(yytext);
}
. { 
    if (textBefore) printf("\n");
    printf("error:lexical:%d:%d: %s", yylineno, yycolumn, yytext);
    textBefore = 1;
    yycolumn += strlen(yytext);
}

%%

int main(int argc, char *argv[]) {
    yylex();
    return 0;
}