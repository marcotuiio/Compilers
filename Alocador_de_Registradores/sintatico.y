%{

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"

extern int yylex();
void yyerror(void *s);

%}

%token MyEof
%token GRAFO
%token K
%token ASSIGN
%token COLON
%token ARROW
%token REG

%start RegAlloc

%%

RegAlloc: GRAFO REG COLON RegAmount MyEof {
    printf("RegAlloc ID %d\n", $2);
} ;

RegAmount: K ASSIGN REG RegInterference { } ;

RegInterference: REG ARROW REG RepeatReg { } ;

RepeatReg: REG RepeatReg { } ;
    | { } ;

%%

void yyerror(void *s) {
    printf("Error: %s\n", (char*)s);
}

int main() {
    yyparse();
    return 0;
}
