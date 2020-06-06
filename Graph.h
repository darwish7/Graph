#ifndef Graph_H_
#define Graph _H_

typedef struct graph
{
    int V;
    struct AdjList* array;
}Graph;




typedef struct AdjListNode
{
    int End;
    int weight;
    struct AdjListNode* next;
}AdjNode;


struct AdjList
{
    struct AdjListNode *head;
};

struct AdjListNode* newAdjListNode(int End,int weight);
Graph * createGraph(int V);
void addEdge(Graph* graph, int src, int End,int weight);
void printGraph(Graph* graph);




#endif // Graph_H_
