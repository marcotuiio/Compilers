%option noyywrap
%option yylineno
%x COMMENT
%{
int textBefore = 0;
int yycolumn = 1;
int lineStart;
int columnStart;
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
    // problema esta aqui. quando next == \n esta somando +1 no contador de linha
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
    if (textBefore) printf("\n");
    printf("VOID");
    textBefore = 1;
    yycolumn += strlen(yytext); 
}
"int" { 
    if (textBefore) printf("\n");
    printf("INT");
    textBefore = 1;
    yycolumn += strlen(yytext); 
}
"char" {
    if (textBefore) printf("\n");
    printf("CHAR"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"return" {
    if (textBefore) printf("\n");
    printf("RETURN"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"break" {
    if (textBefore) printf("\n");
    printf("BREAK");
    textBefore = 1;
    yycolumn += strlen(yytext); 
}
"switch" {
    if (textBefore) printf("\n");
    printf("SWITCH"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"case" {
    if (textBefore) printf("\n");
    printf("CASE"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"default" {
    if (textBefore) printf("\n");
    printf("DEFAULT"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"do" {
    if (textBefore) printf("\n");
    printf("DO"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"while" {
    if (textBefore) printf("\n");
    printf("WHILE"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"for" {
    if (textBefore) printf("\n");
    printf("FOR"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"if" {
    if (textBefore) printf("\n");
    printf("IF"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"else" {
    if (textBefore) printf("\n");
    printf("ELSE"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"typedef" {
    if (textBefore) printf("\n");
    printf("TYPEDEF"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"struct" {
    if (textBefore) printf("\n");
    printf("STRUCT"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"+" {
    if (textBefore) printf("\n");
    printf("PLUS"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"-" {
    if (textBefore) printf("\n");
    printf("MINUS"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"*" {
    if (textBefore) printf("\n");
    printf("MULTIPLY"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"/" {
    if (textBefore) printf("\n");
    printf("DIV"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"%" {
    if (textBefore) printf("\n");
    printf("REMAINDER"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"++" {
    if (textBefore) printf("\n");
    printf("INC"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"--" {
    if (textBefore) printf("\n");
    printf("DEC"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"&" {
    if (textBefore) printf("\n");
    printf("BITWISE_AND"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"|" {
    if (textBefore) printf("\n");
    printf("BITWISE_OR"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"~" {
    if (textBefore) printf("\n");
    printf("BITWISE_NOT"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"^" {
    if (textBefore) printf("\n");
    printf("BITWISE_XOR"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"!" {
    if (textBefore) printf("\n");
    printf("NOT"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"&&" {
    if (textBefore) printf("\n");
    printf("LOGICAL_AND"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"||" {
    if (textBefore) printf("\n");
    printf("LOGICAL_OR"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"==" {
    if (textBefore) printf("\n");
    printf("EQUAL"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"!=" {
    if (textBefore) printf("\n");
    printf("NOT_EQUAL"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"<" {
    if (textBefore) printf("\n");
    printf("LESS_THAN"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
">" {
    if (textBefore) printf("\n");
    printf("GREATER_THAN"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"<=" {
    if (textBefore) printf("\n");
    printf("LESS_EQUAL"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
">=" {
    if (textBefore) printf("\n");
    printf("GREATER_EQUAL"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
">>" {
    if (textBefore) printf("\n");
    printf("R_SHIFT"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"<<" {
    if (textBefore) printf("\n");
    printf("L_SHIFT"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"=" {
    if (textBefore) printf("\n");
    printf("ASSIGN"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"+=" {
    if (textBefore) printf("\n");
    printf("ADD_ASSIGN"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"-=" {
    if (textBefore) printf("\n");
    printf("MINUS_ASSIGN"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
";" {
    if (textBefore) printf("\n");
    printf("SEMICOLON"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"," {
    if (textBefore) printf("\n");
    printf("COMMA"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
":" {
    if (textBefore) printf("\n");
    printf("COLON"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"(" {
    if (textBefore) printf("\n");
    printf("L_PAREN"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
")" {
    if (textBefore) printf("\n");
    printf("R_PAREN"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"{" {
    if (textBefore) printf("\n");
    printf("L_CURLY_BRACKET"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"}" {
    if (textBefore) printf("\n");
    printf("R_CURLY_BRACKET"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"[" {
    if (textBefore) printf("\n");
    printf("L_SQUARE_BRACKET"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"]" {
    if (textBefore) printf("\n");
    printf("R_SQUARE_BRACKET"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"?" {
    if (textBefore) printf("\n");
    printf("TERNARY_CONDITIONAL"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"#" {
    if (textBefore) printf("\n");
    printf("NUMBER_SIGN"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"->" {
    if (textBefore) printf("\n");
    printf("POINTER"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"printf" {
    if (textBefore) printf("\n");
    printf("PRINTF"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"scanf" {
    if (textBefore) printf("\n");
    printf("SCANF"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"define" {
    if (textBefore) printf("\n");
    printf("DEFINE"); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"exit" {
    if (textBefore) printf("\n");
    printf("EXIT"); 
    textBefore = 1;
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

/*

TO DO 
- arrumar bloco dos comentarios
- testar e ajustar

*/