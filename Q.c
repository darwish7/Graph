#include "Q.h"
#include <stdio.h>
#include <stdlib.h>

void CreateQueue(Queue *q){
    q->front=NULL;
    q->rear=NULL;
    q->size=0;
}

void Enqueue(Queue *q,EntryType e,int priority){
Node *pn=(Node *)malloc(sizeof(Node));
Node *temp = q->front;
pn->value=e;
pn->priority = priority;
pn->next=NULL;
if(!q->front)
    q->front=pn;
else{
    if(q->front->priority > priority){
        pn->next = q->front;
        q->front = pn;
    }
    else{
        while (temp->next &&
            temp->next->priority < priority) {
            temp=temp->next;
        }
        pn->next = temp->next;
        temp->next = pn;
    }
}
q->size++;
}

void Dequeue(Queue *q,EntryType *e){
Node *pn;
pn=q->front;
*e=pn->value;
q->front=q->front->next;
free(pn);
if(!q->front)
    q->rear=NULL;
q->size--;
}

int QueueEmpty(Queue q){
    return !q.size;
}

int QueueFull(Queue q){
    return 0;
}

void ClearQueue(Queue *q){
    while (q->front){
        q->rear=q->front->next;
        free(q->front);
        q->front=q->rear;
    }
    q->size=0;
}

EntryType LastElement(Queue *q){
    return (q->rear->value);
}

EntryType FirstElement(Queue q){
    return (q.front->value);
}
//pre cond: q and q2 are initialized and q is not empty
//post cond : q is copied into q2
void CopyQueue(Queue q,Queue *q2){
EntryType e;
for(int i=0;i<(q.size);i++){
    e=q.front->value;
    //Enqueue(q2,e);
    q.front=q.front->next;
}
}

int QueueSize(Queue q){
    q.size;
}
