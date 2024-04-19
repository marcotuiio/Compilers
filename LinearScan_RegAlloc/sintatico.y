%{

#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "list.h"

extern int yylex();
void yyerror(void *s);
extern void yylex_destroy();

void *list = NULL;
int currentVertex = -1;

int *results = NULL;

%}

%token MyEof
%token K
%token ASSIGN
%token ARROW
%token REG_ID
%token NUM_INT

%start RegAlloc

%%

RegAlloc: K ASSIGN NUM_INT LifeSpans MyEof {
    if (list)
        list->availableRegs = $3;
    return 0;
} ;

LifeSpans: REG_ID ARROW NUM_INT NUM_INT  
    {
        if (!list) 
            list = createList();
        
        insertNode(list, $1, $3, $4);
    }
    LifeSpans { } 
    | { } ;

%%

void yyerror(void *s) {
    printf("Error: %s\n", (char*)s);
}

int main() {
    yyparse();

    printList(list);

    results = calloc(list->availableRegs, sizeof(int));

    

    /* for (int lim = auxGraph->availableRegs; lim > 1; lim--) {

        printf("----------------------------------------\n");
        printf("K = %d\n\n", lim);

    } */

    /* printf("----------------------------------------\n");
    printf("----------------------------------------");
    for (int i = auxGraph->availableRegs-1; i >= 0; i--) {
        if (results[i] == 2) {
            printf("\nGraph %d -> K = %s%d: Successful Allocation", auxGraph->id, calcSpaces(auxGraph->availableRegs, i+1) ? " " : "", i+1);
        } else if (results[i] == 1) {
            printf("\nGraph %d -> K = %s%d: SPILL", auxGraph->id, calcSpaces(auxGraph->availableRegs, i+1) ? " " : "", i+1);
        }
    } */

    /* free(results); */
    yylex_destroy();
    freeList(list);

    return 0;
}
