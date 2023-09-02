%option yylineno
%{
int textBefore = 0;
int yycolumn = 1;
%}

%%

"void" { 
    if (textBefore) printf("\n");
    printf("%-10s VOID", yytext);
    textBefore = 1;
    yycolumn += strlen(yytext); 
}
"int" { 
    if (textBefore) printf("\n");
    printf("%-10s INT", yytext);
    textBefore = 1;
    yycolumn += strlen(yytext); 
}
"char" {
    if (textBefore) printf("\n");
    printf("%-10s CHAR", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"return" {
    if (textBefore) printf("\n");
    printf("%-10s RETURN", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"break" {
    if (textBefore) printf("\n");
    printf("%-10s BREAK", yytext);
    textBefore = 1;
    yycolumn += strlen(yytext); 
}
"switch" {
    if (textBefore) printf("\n");
    printf("%-10s SWITCH", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"case" {
    if (textBefore) printf("\n");
    printf("%-10s CASE", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"default" {
    if (textBefore) printf("\n");
    printf("%-10s DEFAULT", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"do" {
    if (textBefore) printf("\n");
    printf("%-10s DO", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"while" {
    if (textBefore) printf("\n");
    printf("%-10s WHILE", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"for" {
    if (textBefore) printf("\n");
    printf("%-10s FOR", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"if" {
    if (textBefore) printf("\n");
    printf("%-10s IF", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"else" {
    if (textBefore) printf("\n");
    printf("%-10s ELSE", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"typedef" {
    if (textBefore) printf("\n");
    printf("%-10s TYPEDEF", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"struct" {
    if (textBefore) printf("\n");
    printf("%-10s STRUCT", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"+" {
    if (textBefore) printf("\n");
    printf("%-10s PLUS", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"-" {
    if (textBefore) printf("\n");
    printf("%-10s MINUS", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"*" {
    if (textBefore) printf("\n");
    printf("%-10s MULTIPLY", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"/" {
    if (textBefore) printf("\n");
    printf("%-10s DIV", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"%" {
    if (textBefore) printf("\n");
    printf("%-10s REMAINDER", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"++" {
    if (textBefore) printf("\n");
    printf("%-10s INC", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"--" {
    if (textBefore) printf("\n");
    printf("%-10s DEC", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"&" {
    if (textBefore) printf("\n");
    printf("%-10s BITWISE_AND", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"|" {
    if (textBefore) printf("\n");
    printf("%-10s BITWISE_OR", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"~" {
    if (textBefore) printf("\n");
    printf("%-10s BITWISE_NOT", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"^" {
    if (textBefore) printf("\n");
    printf("%-10s BITWISE_XOR", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"!" {
    if (textBefore) printf("\n");
    printf("%-10s NOT", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"&&" {
    if (textBefore) printf("\n");
    printf("%-10s LOGICAL_AND", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"||" {
    if (textBefore) printf("\n");
    printf("%-10s LOGICAL_OR", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"==" {
    if (textBefore) printf("\n");
    printf("%-10s EQUAL", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"!=" {
    if (textBefore) printf("\n");
    printf("%-10s NOT_EQUAL", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"<" {
    if (textBefore) printf("\n");
    printf("%-10s LESS_THAN", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
">" {
    if (textBefore) printf("\n");
    printf("%-10s GREATER_THAN", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"<=" {
    if (textBefore) printf("\n");
    printf("%-10s LESS_EQUAL", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
">=" {
    if (textBefore) printf("\n");
    printf("%-10s GREATER_EQUAL", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
">>" {
    if (textBefore) printf("\n");
    printf("%-10s R_SHIFT", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"<<" {
    if (textBefore) printf("\n");
    printf("%-10s L_SHIFT", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"=" {
    if (textBefore) printf("\n");
    printf("%-10s ASSIGN", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"+=" {
    if (textBefore) printf("\n");
    printf("%-10s ADD_ASSIGN", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"-=" {
    if (textBefore) printf("\n");
    printf("%-10s MINUS_ASSIGN", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
";" {
    if (textBefore) printf("\n");
    printf("%-10s SEMICOLON", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"," {
    if (textBefore) printf("\n");
    printf("%-10s COMMA", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
":" {
    if (textBefore) printf("\n");
    printf("%-10s COLON", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"(" {
    if (textBefore) printf("\n");
    printf("%-10s L_PAREN", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
")" {
    if (textBefore) printf("\n");
    printf("%-10s R_PAREN", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"{" {
    if (textBefore) printf("\n");
    printf("%-10s L_CURLY_BRACKET", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"}" {
    if (textBefore) printf("\n");
    printf("%-10s R_CURLY_BRACKET", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"[" {
    if (textBefore) printf("\n");
    printf("%-10s L_SQUARE_BRACKET", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"]" {
    if (textBefore) printf("\n");
    printf("%-10s R_SQUARE_BRACKET", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"?" {
    if (textBefore) printf("\n");
    printf("%-10s TERNARY_CONDITION", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"#" {
    if (textBefore) printf("\n");
    printf("%-10s NUMBER_SIGN", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"->" {
    if (textBefore) printf("\n");
    printf("%-10s POINTER", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"printf" {
    if (textBefore) printf("\n");
    printf("%-10s PRINTF", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"scanf" {
    if (textBefore) printf("\n");
    printf("%-10s SCANF", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"define" {
    if (textBefore) printf("\n");
    printf("%-10s DEFINE", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
"exit" {
    if (textBefore) printf("\n");
    printf("%-10s EXIT", yytext); 
    textBefore = 1;
    yycolumn += strlen(yytext);
}
" " { yycolumn++; }
\n { yycolumn = 1; }
. { 
    if (textBefore) printf("\n");
    printf("error:lexical:%d:%d", yylineno, yycolumn);
    textBefore = 1;
    yycolumn++;
}

%%

int yywrap() {}

int main(int argc, char *argv[]) {
    yylex();
    return 0;
}