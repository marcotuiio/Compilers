#include "graph.h"

#include "stack.h"

void *createGraph() {
    Graph *graph = calloc(1, sizeof(Graph));
    return graph;
}

int insertVertex(void *graph, int node, int color) {
    Graph *g = graph;
    Vertex *v = calloc(1, sizeof(Vertex));
    v->node = node;
    v->color = color;

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

void *removeVertex(void *graph, int removingNode) {
    if (!graph) return NULL;

    Graph *g = graph;
    Vertex *toReturn = NULL;
    Vertex *prevVertex = NULL;
    for (Vertex *aux = g->vertexHeader; aux; aux = aux->next) {
        // This is the node to be removed
        if (aux->node == removingNode) {
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
            if (e->destiny == removingNode) {
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

void removeMinDegreeVertex(void *graph, void *stack) {
    if (!graph) return;

    Graph *g = graph;
    Vertex *head = g->vertexHeader;
    int minNode = head->node;
    int minDegree = head->degree;
    Vertex *aux = head->next;

    // Getting the minimum degree vertex
    // printf("Getting min degree vertex %d\n", g->availableRegs);
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

    // Checking for potencial spill
    if (minDegree >= g->availableRegs) {
        removeMaxDegreeVertex(g, stack);

    } else {
        // Removing references to the minimum degree vertex, storing it and returning it to be stored in the stack
        Vertex *toReturn = removeVertex(g, minNode);
        push(stack, toReturn);
        printf("Push: %d\n", minNode);
    }
}

void removeMaxDegreeVertex(void *graph, void *potencialSpills) {
    if (!graph) return;

    Graph *g = graph;
    Vertex *head = g->vertexHeader;
    int maxNode = head->node;
    int maxDegree = head->degree;
    Vertex *aux = head->next;

    // Getting the maximum degree vertex
    while (aux) {
        if (aux->degree == maxDegree) {
            if (aux->node < maxNode) {
                maxNode = aux->node;
                maxDegree = aux->degree;
            }

        } else if (aux->degree > maxDegree) {
            maxNode = aux->node;
            maxDegree = aux->degree;
        }
        aux = aux->next;
    }

    // Removing references to the maximum degree vertex, storing it and returning it to be stored in the memory
    Vertex *toReturn = removeVertex(g, maxNode);
    push(potencialSpills, toReturn);
    ((Node *)peek(potencialSpills))->isPotencialSpill = 1;
    printf("Push: %d*\n", maxNode);
}

int rebuildGraph(void *graph, void *stack) {
    if (!graph) return -1;

    Graph *g = graph;
    Node *top = pop(stack);
    if (!top) top = pop(stack);
    int interferenceColor = -1;
    g->vertexHeader = NULL;
    
    while (top) {
        if (top->isPotencialSpill) {
            free(top);
            top = pop(stack);
            continue;   
        }
        Vertex *v = top->data;
        Edge *e = v->edgeList;
        insertVertex(g, v->node, v->color);
        v->edgeList = NULL;

        int available[g->availableRegs];
        for (int i = 0; i < g->availableRegs; i++) {
            available[i] = 1;
        }
        while (e) {

            // Checking the available colors and the maximum color used
            Vertex *v = getVertex(g, e->destiny);
            if (v) {
                insertEdge(g, e->origin, e->destiny);
                interferenceColor = v->color;
                if (interferenceColor < g->availableRegs)
                    available[interferenceColor] = 0;
            }

            e = e->next;
        }

        // Coloring the vertex
        int toColorIn = -1;
        for (int i = 0; i < g->availableRegs; i++) {
            if (available[i]) {
                toColorIn = i;
                break;
            }
        }
        if (toColorIn == -1) {
            // SPILL
            printf("Pop: %d -> NO COLOR AVAILABLE\n", v->node);
            printf("\nGraph %d -> K = %d: SPILL\n", g->id, g->availableRegs);
            freeStack(stack);
            return -1;
        }

        ((Vertex *)getVertex(g, v->node))->color = toColorIn;
        printf("Pop: %d -> %d\n", v->node, toColorIn);
        free(v);
        free(top);
        top = pop(stack);
    }
    printf("\nGraph %d -> K = %d: Successful Allocation\n\n", g->id, g->availableRegs);
    freeStack(stack);
    return 0;
}

void cloneGraph(void *g1, void *g2) {
    if (!g1 || !g2) return;

    Graph *g = g1;
    Graph *gClone = g2;
    gClone->id = g->id;
    Vertex *aux = g->vertexHeader;
    while (aux) {
        insertVertex(gClone, aux->node, 0);
        Edge *auxEdge = aux->edgeList;
        while (auxEdge) {
            insertEdge(gClone, auxEdge->origin, auxEdge->destiny);
            auxEdge = auxEdge->next;
        }
        aux = aux->next;
    }
}

void printGraph(void *graph) {
    if (!graph) return;

    Graph *g = graph;
    Vertex *aux = g->vertexHeader;
    while (aux) {
        printf("\nNode: %d (color %d)(degree %d) %p --> ", aux->node, aux->color, aux->degree, aux);
        Edge *auxEdge = aux->edgeList;
        while (auxEdge) {
            printf("%d ", auxEdge->destiny);
            auxEdge = auxEdge->next;
        }
        aux = aux->next;
    }
    printf("\n");
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