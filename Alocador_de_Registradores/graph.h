#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int id;
    void *vertexHeader;
    int availableRegs;
    int qntdVertex;
} Graph;

typedef struct vertex {
    int node;
    int degree;
    int color;
    void *edgeList;
    struct vertex *next;
} Vertex;

typedef struct edge {
    int origin;
    int destiny;
    struct edge *next;
} Edge;

void *createGraph();
int insertVertex(void *graph, int node, int color);
void insertEdge(void *graph, int origin, int destiny);
void *getVertex(void *graph, int node);
void removeMinDegreeVertex(void *graph, void *stack);
void removeMaxDegreeVertex(void *graph, void *potencialSpills);
int rebuildGraph(void *graph, void *stack);
void cloneGraph(void *g1, void *g2);
void printGraph(void *graph);
void freeGraph(void *graph);

#endif