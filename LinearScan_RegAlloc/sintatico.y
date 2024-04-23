%{

#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include <string.h>
#include "list.h"

extern int yylex();
void yyerror(void *s);
extern void yylex_destroy();

List *list = NULL;
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

    /* printList(list); */
    /* exit(0); */

    char *results = calloc(8192, sizeof(char));

    for (int k = list->availableRegs; k > 1; k--) {

        int *available = calloc(list->availableRegs, sizeof(int));
        for (int i = 0; i < list->availableRegs; i++) {
            available[i] = 0;
        }

        int *spills = calloc(list->size, sizeof(int));
        int qntdSpills = 0;
        int spillIteration = 0;

        Node *curr = list->head;
        while (curr) {

            int used = -1;
            // ALLOCATING
            for (int i = 0; i < list->availableRegs; i++) {
                /* Node *alloc = getNode(list, available[i]);
                if (alloc) {
                    printf("Trying to alloc vr%d on %d (vr%d %d, %d)\n", curr->id, i, alloc->id, alloc->start, alloc->end);
                } else {
                    printf("Trying to alloc vr%d on %d\n", curr->id, i);
                } */
                if (!available[i]) {
                    used = i;
                    available[i] = curr->id;
                    curr->assignedReg = i;
                    /* printf("Easy alloc: vr%d -> %d\n", curr->id, i); */
                    break;
                } else {
                    if (getNode(list, available[i])->end <= curr->id) {
                        used = i;
                        available[i] = curr->id;
                        curr->assignedReg = i;
                        /* printf("Alloc: vr%d -> %d\n", curr->id, i); */
                        break;
                    }
                }
            }            

            // SPILL
            if (used == -1) {
                spills[spillIteration] = 1;
                qntdSpills++;
                Node *toSpill = curr;
                int spilled = -1;
                int greatestEnd = curr->end;
                int smallestSpan = curr->lifeSpan;
                int mostRecent = curr->id;

                for (int i = 0; i < list->availableRegs; i++) {
                    Node *onUse = getNode(list, available[i]);
                    // Criterio 1. Spill no registrador com maior end
                    if (onUse->end > greatestEnd) {
                        /* printf("spill on 1st %d\n", onUse->id); */
                        spilled = i;
                        toSpill = onUse;
                        greatestEnd = onUse->end;
                    } else {
                        // Criterio 2. Spill no registrador com menor lifeSpan
                        if (onUse->end == greatestEnd && onUse->lifeSpan < smallestSpan) {
                            /* printf("spill on 2nd %d\n", onUse->id); */
                            spilled = i;
                            toSpill = onUse;
                            smallestSpan = onUse->lifeSpan;
                        } else {
                            // Criterio 3. Spill no registrador com id mais recente
                            if (onUse->end == greatestEnd && onUse->lifeSpan == toSpill->lifeSpan && onUse->id > mostRecent) {
                                /* printf("spill on 3rd %d\n", onUse->id); */
                                spilled = i;
                                toSpill = onUse;
                                mostRecent = onUse->id;
                            }
                        }
                    }
                    /* printf("So far spilled: vr%d\n", toSpill->id); */
                }
                toSpill->assignedReg = -1;
                if (spilled != -1) {
                    available[spilled] = curr->id;
                    curr->assignedReg = spilled;
                } else {
                    /* printf("Spilled current %d %p %p\n", curr->id, toSpill, curr); */
                }
            }

            curr = curr->next;
            spillIteration++;
        }

        printf("K = %d\n\n", k);
        for (int i = 0; i < list->size; i++) {
            Node *curr = getNode(list, i+1);
            if (curr->assignedReg == -1) {
                printf("vr%d: SPILL\n", i+1);
            } else {
                printf("vr%d: %d\n", i+1, curr->assignedReg);
            }
        }

        printf("----------------------------------------\n");
        
        char *auxStr = calloc(1024, sizeof(char));
        if (qntdSpills == 0) {
            sprintf(auxStr, "K = %d: Successful Allocation", k);
        } else {
            sprintf(auxStr, "K = %d: Spill on iteration(s): ", k);
            int rep = 0;
            for (int s = 0; s < list->size; s++) {
                if (spills[s] == 0) continue;
                char *numStr = calloc(5, sizeof(char));
                rep++;
                sprintf(numStr, "%d", s);
                if (rep == qntdSpills) {
                    strcat(auxStr, numStr);
                } else {
                    strcat(auxStr, numStr);
                    strcat(auxStr, ", ");
                }
                free(numStr);
            }
        }
        strcat(results, auxStr);
        strcat(results, ".\n");
        free(auxStr);
        list->availableRegs = k - 1;
        free(spills);
        free(available);
    }

    printf("----------------------------------------\n");
    printf("%s", results);
    free(results);
    
    freeList(list);
    
    yylex_destroy();

    return 0;
}
