#include <bits/stdc++.h> 
#include <stdio.h>      /* #printf\, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "pointerqueue.h"

using namespace std; 



Queue* initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = (NodeQ *)malloc(sizeof(NodeQ));
    q->rear = (NodeQ *)malloc(sizeof(NodeQ));
    q->front->next = NULL;
    q->rear = q->front;
    q->size = 0;
    return q;
}	


Queue *makenull(Queue *q)
{
    free(q);
    Queue *newQ = initQueue();
    return newQ;
}


bool empty(Queue *q)
{
    if (q->front == q->rear){
        return true;
    }
    return false;
}


NodeQ* front(Queue *q){
    if (empty(q)){
        printf("Error Queue is empty\n");
        exit(1);
    } else {
        return q->front->next;
    }
}


void enqueue(Queue *q, uint64_t _data){
    NodeQ *node = (NodeQ *)malloc(sizeof(NodeQ));
    node->data = _data;
    q->rear->next = node;
    q->rear = q->rear->next;
    q->rear->next = NULL;
}


void enqueue2(Queue *q, uint64_t _data, uint64_t id){
    NodeQ *node = (NodeQ *)malloc(sizeof(NodeQ));
    node->data = _data;
    node->id = id;
    q->rear->next = node;
    q->rear = q->rear->next;
    q->rear->next = NULL;
}


void dequeue(Queue *q){
    if (empty(q)){
        printf("Error Queue is empty\n");
        exit(1);
    } else {
        free(q->front);
        q->front = q->front->next;
    }
}

