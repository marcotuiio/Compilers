%{

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"

extern int yylex();
void yyerror(void *s);
extern void yylex_destroy();

Graph *graph = NULL;
Graph *auxGraph = NULL;
Stack *stack = NULL;
Stack *potencialSpills = NULL;
int currentVertex = -1;
int availRegs = -1;
int id = -1;

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

int main() {
    yyparse();
    auxGraph = createGraph();

    /* printf("\n---- MAIN %p\n\n", graph); */
    cloneGraph(graph, auxGraph);
    auxGraph->availableRegs = graph->availableRegs;

    /* printGraph(graph);
    printf("\nCLONE\n");
    printGraph(auxGraph); 
    exit(0); */

    for (int lim = auxGraph->availableRegs; lim > 1; lim--) {
        printGraph(graph);
        stack = createStack();
        potencialSpills = createStack();

        for (int i = graph->qntdVertex; i > 0 ; i--) {
            removeMinDegreeVertex(graph, stack, potencialSpills);
        }
        printf("\n%d Printing Stack\n", lim);
        printStack(stack);
        printf("\n%d Printing Potencial Spills Stack\n", lim);
        printStack(potencialSpills);

        printf("\nRebuilding graph with k = %d\n\n", graph->availableRegs);
        if (rebuildGraph(graph, stack, potencialSpills) == -1) break;
        /* printGraph(graph); */

        freeGraph(graph);
        graph = createGraph();
        cloneGraph(auxGraph, graph);
        graph->availableRegs = lim - 1;        
    }
    
    freeGraph(auxGraph);
    freeGraph(graph);
    yylex_destroy();

    return 0;
}
