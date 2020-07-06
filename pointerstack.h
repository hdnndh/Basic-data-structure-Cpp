#include <bits/stdc++.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std; 

struct NodeS;
typedef struct NodeS NodeS;
typedef struct NodeS
{
    uint64_t data;

    NodeS *prev;
    NodeS *next;
}NodeS;

typedef struct Stack
{
    NodeS *first;
    NodeS *last;

    unsigned size; // Current size of the Stack
}Stack;


Stack *initStack();
void push(Stack *s, uint64_t _data);
void pop(Stack *s);
NodeS* top(Stack *s);
void makenull(Stack *s);
bool empty(Stack *s);