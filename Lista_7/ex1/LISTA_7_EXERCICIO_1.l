%{
int textBefore = 0;
%}

%%

[a-z]+[a-z0-9]* { 
    if (textBefore) {
        printf("\n");
    } 
    printf("%s", yytext); 
    textBefore = 1;
}
[0-9]+ { 
    if (textBefore) {
        printf("\n");
    }
    printf("%s", yytext); 
    textBefore = 1;
}
[0-9]+e[+|-]?[0-9]+ { 
    if (textBefore) {
        printf("\n");
    } 
    printf("%s", yytext); 
    textBefore = 1;
}
[+|-] { 
    if (textBefore) {
        printf("\n");
    } 
    printf("%s", yytext); 
    textBefore = 1;
}
\n {}
<<EOF>> { return 0; }
. { 
    if (textBefore) {
        printf("\n");
    } 
    printf("ERRO"); 
    textBefore = 1;
}

%%

int yywrap() {}

int main() {
    yylex();
    return 0;
}