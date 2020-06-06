#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

AdjNode* newAdjListNode(int End,int weight)
{
    AdjNode* newNode =
     (AdjNode*) malloc(sizeof(AdjNode));
    newNode->End = End;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}


Graph * createGraph(int V)
{
    Graph *graph =
        (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->array =
      (struct AdjList*) malloc(V * sizeof(struct AdjList));

    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
        return graph;
}


void addEdge(Graph* graph, int src, int End,int weight)
{
    AdjNode* newNode = newAdjListNode(End,weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;


    newNode = newAdjListNode(src,weight);
    newNode->next = graph->array[End].head;
    graph->array[End].head = newNode;
}

