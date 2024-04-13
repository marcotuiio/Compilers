%{

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"

extern int yylex();
void yyerror(void *s);

Graph *graph = NULL;
Stack *stack = NULL;
int currentVertex = -1;

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
    return 0;
} ;

GraphId: GRAFO NUM_INT COLON MyEol { printf("Graph ID %d\n", $2); } ;

RegAmount: K ASSIGN NUM_INT MyEol { printf("AvailableRegs K %d\n", $3); } ;

RegInterferences: DeclareVertexAndEdges MyEol RegInterferences { } 
    | DeclareVertexAndEdges { } ;

DeclareVertexAndEdges: NUM_INT { 
        if (!graph) {
            graph = createGraph();
        }
        currentVertex = insertVertex(graph, $1); 
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
    stack = createStack();
    printf("\n---- MAIN %p\n\n", graph);

    for (int i = graph->qntdVertex; i > 0 ; i--) {
        Vertex *min = removeMinDegreeVertex(graph);
        if (min) {
            printf("(%d) Min: %d\n", i, min->node);
            push(stack, min);
        }

    }
    printStack(stack);

    freeStack(stack);
    freeGraph(graph);
    return 0;
}
