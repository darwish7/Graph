#ifndef LINKED_BASED_Q_H
#define LINKED_BASED_Q_H
#define MAX 10

typedef int EntryType;
typedef struct QNode{
    EntryType value;
    int priority;
    struct QNode *next;
}Node;
typedef struct queue{
    Node *front;
    Node *rear;
    int size;
}Queue;
void CreateQueue(Queue *);
void Enqueue(Queue *,EntryType ,int);
void Dequeue(Queue *q,EntryType *e);
int QueueEmpty(Queue q);
int QueueFull(Queue q);
void ClearQueue(Queue *q);
EntryType LastElement(Queue *);
EntryType FirstElement(Queue);
void CopyQueue(Queue ,Queue*);
int QueueSize(Queue);
#endif //LINKED_BASED_Q_H
