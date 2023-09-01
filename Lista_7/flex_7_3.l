%{
int textBefore = 0;
%}

%%

(aba)+ { 
    if (textBefore) {
        printf("\n");
    } 
    printf("%s action 1", yytext); 
    textBefore = 1;
}
ab*a {
    if (textBefore) {
        printf("\n");
    } 
    printf("%s action 2", yytext); 
    textBefore = 1;
}
[a|b] {
    if (textBefore) {
        printf("\n");
    } 
    printf("%s action 3", yytext); 
    textBefore = 1;
}
. { 
    if (textBefore) {
        printf("\n");
    } 
    printf("%s error", yytext); 
    textBefore = 1;
}

%%

int yywrap() {return 0;}

int main() {
    yylex();
    return 0;
}