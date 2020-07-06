#ifndef POINTERQUEUE_H
#define POINTERQUEUE_H

#include <bits/stdc++.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std; 

struct NodeQ;
typedef struct NodeQ NodeQ;
typedef struct NodeQ
{
    uint64_t data;

    NodeQ *next;
    char id;
}NodeQ;

typedef struct Queue
{
    NodeQ *front;
    NodeQ *rear;

    unsigned size; // Current size of the Queue
}Queue;


Queue *initQueue();
void dequeue(Queue *q);
void enqueue(Queue *q, uint64_t _data);
NodeQ* front(Queue *q);
Queue *makenull(Queue *q);
bool empty(Queue *q);
void enqueue2(Queue *q, uint64_t _data, uint64_t id);

#endif
