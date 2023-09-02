%{
int textBefore = 0;
%}

%%

if { 
    if (textBefore) {
        printf("\n");
    } 
    printf("%s IF", yytext); 
    textBefore = 1;
}
i {
    if (textBefore) {
        printf("\n");
    } 
    printf("%s ID", yytext); 
    textBefore = 1;
}
if[a-z0-9]+ {
    if (textBefore) {
        printf("\n");
    } 
    printf("%s ID", yytext); 
    textBefore = 1;
}
i[a-eg-z0-9][a-z0-9]* {
    if (textBefore) {
        printf("\n");
    } 
    printf("%s ID", yytext); 
    textBefore = 1;
}
[a-hj-z][a-z0-9]* {
    if (textBefore) {
        printf("\n");
    } 
    printf("%s ID", yytext); 
    textBefore = 1;
}
(([0-9]+"."[0-9]*)|([0-9]*"."[0-9]+)) {
    if (textBefore) {
        printf("\n");
    } 
    printf("%s REAL", yytext); 
    textBefore = 1;
}   
[0-9]+ {
    if (textBefore) {
        printf("\n");
    } 
    printf("%s NUM", yytext); 
    textBefore = 1;
}
"." {
    if (textBefore) {
        printf("\n");
    } 
    printf("%s error", yytext); 
    textBefore = 1;
}
--([a-z]+)\n {
    if (textBefore) {
        printf("\n");
    } 
    for (int i = 0; i < strlen(yytext); i++) {
        if (yytext[i] != '\n') {
            printf("%c", yytext[i]);
        }
    }
    printf(" comment"); 
    textBefore = 1;
}
"-" {
    if (textBefore) {
        printf("\n");
    } 
    printf("%s error", yytext); 
    textBefore = 1;
}
[" "]+ {
    if (textBefore) {
        printf("\n");
    } 
    printf("white space"); 
    textBefore = 1;
}
\n|\r\n? {}
<<EOF>> { return 0; }
. { 
    if (textBefore) {
        printf("\n");
    } 
    printf("%s error", yytext); 
    textBefore = 1;
}

%%

int yywrap() {}

int main() {
    yylex();
    return 0;
}