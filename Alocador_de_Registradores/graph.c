#include "graph.h"

void *createGraph() {
    Graph *graph = calloc(1, sizeof(Graph));
    return graph;
}

int insertVertex(void *graph, int node) {
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
    return node;
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

void *removeMinDegreeVertex(void *graph) {
    if (!graph) return NULL;

    Graph *g = graph;
    Vertex *head = g->vertexHeader;
    int minNode = head->node;
    int minDegree = head->degree;
    Vertex *aux = head->next;

    // Getting the minimum degree vertex
    while (aux) {
        if (aux->degree == minDegree) {
            if (aux->node < minNode) {
                minNode = aux->node;
                minDegree = aux->degree;
            }

        } else if (aux->degree < minDegree) {
            minNode = aux->node;
            minDegree = aux->degree;
        }
        aux = aux->next;
    }

    // Removing references to the minimum degree vertex, storing it and returning it to be stored in the stack
    Vertex *toReturn = NULL;
    Vertex *prevVertex = NULL;
    for (aux = head; aux; aux = aux->next) {
        // This is the node to be removed
        if (aux->node == minNode) {
            toReturn = aux;
            if (prevVertex) {
                prevVertex->next = aux->next;
            } else {
                g->vertexHeader = aux->next;
            }
            g->qntdVertex--;
            continue;
        }

        Edge *prevEdge = NULL;
        for (Edge *e = aux->edgeList; e; e = e->next) {
            if (e->destiny == minNode) {
                if (prevEdge) {
                    prevEdge->next = e->next;
                } else {
                    aux->edgeList = e->next;
                }
                free(e);
                aux->degree--;
                break;
            }
            prevEdge = e;
        }
        prevVertex = aux;
    }
    return toReturn;
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

void freeGraph(void *graph) {
    if (!graph) return;

    Graph *g = graph;
    Vertex *aux = g->vertexHeader;
    while (aux) {
        Edge *auxEdge = aux->edgeList;
        while (auxEdge) {
            Edge *eToFree = auxEdge;
            auxEdge = auxEdge->next;
            if (eToFree) free(eToFree);
        }
        Vertex *vToFree = aux;
        aux = aux->next;
        if (vToFree) free(vToFree);
    }
    free(g);
}