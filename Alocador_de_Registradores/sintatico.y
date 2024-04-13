%{

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"

extern int yylex();
void yyerror(void *s);

Graph *graph = NULL;
Stack *stack = NULL;
Stack *potencialSpills = NULL;
int currentVertex = -1;
int availRegs = -1;

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
    printf("EndParse\n");
    if (graph) {
        graph->availableRegs = availRegs;
    }
    return 0;
} ;

GraphId: GRAFO NUM_INT COLON MyEol { printf("Graph ID %d\n", $2); } ;

RegAmount: K ASSIGN NUM_INT MyEol { 
    printf("AvailableRegs K %d\n", $3); 
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
    potencialSpills = createStack();

    printf("\n---- MAIN %p\n\n", graph);

    for (int lim = graph->availableRegs; lim > 1; lim--) {
        stack = createStack();

        for (int i = graph->qntdVertex; i > 0 ; i--) {
            removeMinDegreeVertex(graph, stack, potencialSpills);
        }
        printf("\n%d Printing Stack\n", lim);
        printStack(stack);

        printf("\nRebuilding graph with k = %d - %d\n", graph->availableRegs, graph->qntdVertex);
        rebuildGraph(graph, stack, potencialSpills);
        printGraph(graph);
        graph->availableRegs--;
    }


    /* printf("Printing Regular Stack\n");
    printStack(stack);

    printf("Printing Potencial Spills Stack\n");
    printStack(potencialSpills); */

    /* freeStack(stack); */
    freeGraph(graph);
    return 0;
}
