#ifndef POINTERLIST_H
#define POINTERLIST_H

#include <bits/stdc++.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std; 

struct NodeL
{
    uint64_t data;
    NodeL *next;
};
typedef struct NodeL NodeL;

struct List
{
    NodeL *head;

    unsigned size; // Current size of the Stack
};
typedef struct List List;

List *initList();
void insert(uint64_t data, NodeL* p);
void del(NodeL* p);
NodeL* locate(uint64_t data, List *l);
uint64_t retrieve(NodeL* p);
NodeL* next(NodeL* p);
NodeL* prev(NodeL* p, List *l);
NodeL* first (List *l);
NodeL* end (List *l);
List* makenull (List *l);
bool empty(List *l);
void printlist(List *l);


#endif
