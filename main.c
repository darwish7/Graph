#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Q.h"
#include "Q.c"
#include "Graph.h"


int ScanGraph(char FileName[],Graph *G){
int src,End,weight;
FILE *pf = fopen(FileName,"r");
    if (pf == NULL)
        return 0;

    else {
    while(fscanf(pf,"%d",&src)==1){
            fscanf(pf,"%d%d",&End,&weight);
            addEdge(G,src,End,weight);
    }
    }
    fclose(pf);
    return 1;
}


void getPath(int parent[],Queue *pq,int path[],int j)
{
    int i =99;
    while(parent[j] != - 1){
    path[j]=1;
    Enqueue(pq,j,i);
    j = parent[j];
    i--;
    }
    Enqueue(pq,j,0);
    path[j]=1;
    }

void Dijkstra(int N,Graph *g,int src,int End){
        int dis[N],previous[N],Visited[N],track[N],path[N],U;
        Queue q;
        CreateQueue(&q);
        for(int i=0; i<N; i++){
            dis[i]=INT_MAX;
            previous[i]=-1;
            Visited[i]=0;
            track[i]=0;
            path[i] = 0;
        }
        dis[src]=0;
        Enqueue(&q,src,dis[src]);
        while(!QueueEmpty(q)){
            Dequeue(&q,&U);
            Visited[U]=1;
            for(AdjNode *pn=g->array[U].head;pn;pn=pn->next){
                if(dis[pn->End] > dis[U]+pn->weight&& !Visited[pn->End]){
                    dis[pn->End]=dis[U]+pn->weight;
                    previous[pn->End]=U;
                    Enqueue(&q,pn->End,dis[pn->End]);
                    }
                }
            }
        int x;
        getPath(previous,&q,path,End);
        while(!QueueEmpty(q)){
            Dequeue(&q,&x);
            path[x]=1;
            printf("-->%d",x);
        }
        int Flag = 0;
        //track is supposed to be an array that tracks the user so if he did went to a random planet dijkstra algorithm runs again
        for(int i=0;i<N;i++){
            if(track[i] && !path[i]){
                printf("\nThe Time From Planet[%d] to Reach Your Distension = %d\n",src,dis[End]);
                Dijkstra(N,g,i,End);
                Flag++;
                }
        }
        if (Flag==0)
            printf("\nThe Time From Planet[%d] to Reach Your Distension = %d\n",src,dis[End]);

    }

int main()
{
   int size,src,dist;
   char FileName[20];
    printf("Enter The Number Of Plants\n");
    scanf("%d",&size);
    Graph* G = createGraph(size);
    printf("Enter the File name that has the Graph\n");
    scanf("%s",&FileName);
    ScanGraph(FileName,G);
    printf("Enter The Source Planet\n");
    scanf("%d",&src);
    printf("Enter The Destination Planet\n");
    scanf("%d",&dist);
    Dijkstra(size,G,src,dist);


    return 0;
}
