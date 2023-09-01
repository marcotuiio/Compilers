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
\n|\r\n? { continue; }
<<EOF>> {printf("socror"); return 0; }
. { 
    if (textBefore) {
        printf("\n");
    } 
    printf("ERRO"); 
    textBefore = 1;
}

%%

int yywrap() {return 0;}

int main() {
    yylex();
    return 0;
}