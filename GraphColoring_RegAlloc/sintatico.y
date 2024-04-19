%{

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"
#include "math.h"

extern int yylex();
void yyerror(void *s);
extern void yylex_destroy();

Graph *graph = NULL;
Graph *auxGraph = NULL;
Stack *stack = NULL;
int currentVertex = -1;
int availRegs = -1;
int id = -1;

int *results = NULL;

%}

%token MyEof
%token MyEol
%token GRAFO
%token K
%token ASSIGN
%token COLON
%token ARROW
%token NUM_INT

%start RegAlloc

%%

RegAlloc: GraphId RegAmount RegInterferences MyEof {
    if (graph) {
        graph->availableRegs = availRegs;
        graph->id = id;
    }
    return 0;
} ;

GraphId: GRAFO NUM_INT COLON MyEol { 
    // printf("GraphId %d\n", $2); 
    id = $2;
} ;

RegAmount: K ASSIGN NUM_INT MyEol { 
    // printf("AvailableRegs K %d\n", $3); 
    availRegs = $3;
} ;

RegInterferences: DeclareVertexAndEdges MyEol RegInterferences { } 
    | DeclareVertexAndEdges { } ;

DeclareVertexAndEdges: NUM_INT { 
        if (!graph) {
            graph = createGraph();
        }
        currentVertex = insertVertex(graph, $1, 0); 
    } 
    ARROW RepeatReg { } ;

RepeatReg: NUM_INT RepeatReg { insertEdge(graph, currentVertex, $1); } ;
    | { } ;

%%

void yyerror(void *s) {
    printf("Error: %s\n", (char*)s);
}

int calcSpaces(int total, int current) {
    int cDigits = 0;
    int tDigits = 0;
    if (current == 0) {
        cDigits = 1;
    } else {
        cDigits = floor(log10(abs(current))) + 1;
    }   
    if (total == 0) {
        tDigits = 1;
    } else {
        tDigits = floor(log10(abs(total))) + 1;
    }

    if (cDigits == tDigits) 
        return 0;
    else 
        return 1;
}

int main() {
    yyparse();
    auxGraph = createGraph();
    results = calloc(graph->availableRegs-1, sizeof(int));

    cloneGraph(graph, auxGraph);
    auxGraph->availableRegs = graph->availableRegs;

    printf("Graph %d -> Physical Registers: %d\n", graph->id, graph->availableRegs);
    printf("----------------------------------------\n");

    for (int lim = auxGraph->availableRegs; lim > 1; lim--) {
        /* printGraph(graph); */
        stack = createStack();

        printf("----------------------------------------\n");
        printf("K = %d\n\n", lim);
        for (int i = graph->qntdVertex; i > 0 ; i--) {
            removeMinDegreeVertex(graph, stack);
        }
        /* printf("\n%d Printing Stack\n", lim);
        printStack(stack); */

        rebuildGraph(graph, stack, results);
        /* printGraph(graph); */

        freeGraph(graph);
        graph = createGraph();
        cloneGraph(auxGraph, graph);
        graph->availableRegs = lim - 1;        
    }

    printf("----------------------------------------\n");
    printf("----------------------------------------");
    for (int i = auxGraph->availableRegs-1; i >= 0; i--) {
        if (results[i] == 2) {
            printf("\nGraph %d -> K = %s%d: Successful Allocation", auxGraph->id, calcSpaces(auxGraph->availableRegs, i+1) ? " " : "", i+1);
        } else if (results[i] == 1) {
            printf("\nGraph %d -> K = %s%d: SPILL", auxGraph->id, calcSpaces(auxGraph->availableRegs, i+1) ? " " : "", i+1);
        }
    }
    free(results);
    freeGraph(auxGraph);
    freeGraph(graph);
    yylex_destroy();

    return 0;
}
