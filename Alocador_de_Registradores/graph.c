#include "graph.h"

void *createGraph(){
    Graph *graph = calloc(1, sizeof(Graph));
    return graph;
}

void insertVertex(void *graph, int node) {
    Graph *g = graph;
    Vertex *v = calloc(1, sizeof(Vertex));
    v->node = node;

    if (!g->vertexHeader) {
        g->vertexHeader = v;
        g->qntdVertex++;

    } else {
        Vertex *aux = g->vertexHeader;
        while (aux->next) {
            aux = aux->next;
        }
        aux->next = v;
        g->qntdVertex++;
    }
}

void insertEdge(void *graph, int origin, int destiny) {
    if (!graph) return;

    Graph *g = graph;
    Vertex *aux = g->vertexHeader;
    while (aux) {
        if (aux->node == origin) {
            Edge *e = calloc(1, sizeof(Edge));
            e->origin = origin;
            e->destiny = destiny;

            if (!aux->edgeList) {
                aux->edgeList = e;
                aux->degree++;

            } else {
                Edge *auxEdge = aux->edgeList;
                while (auxEdge->next) {
                    auxEdge = auxEdge->next;
                }
                auxEdge->next = e;
                aux->degree++;
            }
            break;
        }
        aux = aux->next;
    }
}

void *getVertex(void *graph, int node) {
    if (!graph) return NULL;

    Graph *g = graph;
    Vertex *aux = g->vertexHeader;
    while (aux) {
        if (aux->node == node) {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

void printGraph(void *graph) {
    if (!graph) return;

    Graph *g = graph;
    Vertex *aux = g->vertexHeader;
    while (aux) {
        printf("Node: %d\n", aux->node);
        Edge *auxEdge = aux->edgeList;
        while (auxEdge) {
            printf("Edge: %d -> %d\n", auxEdge->origin, auxEdge->destiny);
            auxEdge = auxEdge->next;
        }
        aux = aux->next;
    }
}