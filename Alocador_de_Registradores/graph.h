#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    void *vertexHeader;
    int maxVertex;
    int qntdVertex;
} Graph;

typedef struct vertex {
    int node;
    int degree;
    void *edgeList;
    struct vertex *next;
} Vertex;

typedef struct edge {
    int origin;
    int destiny;
    struct edge *next;
} Edge;

void *createGraph();
void insertVertex(void *graph, int node);
void insertEdge(void *graph, int origin, int destiny);
void printGraph(void *graph);

#endif