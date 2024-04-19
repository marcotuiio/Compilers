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

    char *results = calloc(4096, sizeof(char));
    // TODO CRIAR VETOR QUE CONTROLA E PRINTA ITERAÇÕES COM SPILL

    for (int k = list->availableRegs; i > 0; i--) {

        int *available = calloc(list->availableRegs-1, sizeof(int));
        for (int i = 0; i < k; i++) {
            available[i] = 1;
        }

        Node *curr = list->head;
        while (curr) {

            int used = -1
            // ALLOCATING
            for (int j = 0; j < list->availableRegs; j++) {
                if (available[j]) {
                    used = j;
                    available[j] = curr->id;
                    break;
                }
            }

            // SPILL
            if (used == -1) {
                Node *toSpill = NULL;
                int greatestEnd = -1;
                int smallestSpan = 999999;
                int mostRecent = -1;

                for (int i = 0; i < k; i++) {
                    Node *onUse = getNode(list, available[i]);
                    // Criterio 1. Spill no registrador com maior end
                    if (onUse->end > greatestEnd) {
                        toSpill = onUse;
                        greatestEnd = onUse->end;
                    } else {
                        // Criterio 2. Spill no registrador com menor lifeSpan
                        if (onUse->end == greatestEnd && onUse->lifeSpan < smallestSpan) {
                            toSpill = onUse;
                            smallestSpan = onUse->lifeSpan;
                        } else {
                            // Criterio 3. Spill no registrador com id mais recente
                            if (onUse->end == greatestEnd && onUse->lifeSpan == n1->lifeSpan && onUse->id > mostRecent) {
                                toSpill = onUse;
                                mostRecent = onUse->id;
                            }
                        }
                    }
                    onUse = onUse->next;
                }

            }

            curr = curr->next;
        }
        // TODO RESETAR LISTA PARA PROXIMA ITERAÇÃO E CONTROLAR QUANTIDADE DE REGS DISPONIVEIS AGORA
        list->availableRegs = k - 1;
        free(available);
    }    

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
