#include <bits/stdc++.h> 
#include <stdio.h>      /* #printf\, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std; 
#include "pointerlist.h"

List *initList(){
    // printf("init start\n");
    // fflush(stdout);
    List *l = (List *)malloc(sizeof(List));
    // printf("malloc done\n");
    // fflush(stdout);
    l->head = (NodeL *)malloc(sizeof(NodeL));
    l->head->next = NULL;
    // printf("set next done\n");
    // fflush(stdout);
    l->size = 0;
    return l;
}

void insert(uint64_t data, NodeL* p){
    NodeL* temp = p->next;
    NodeL* newN = (NodeL *)malloc(sizeof(NodeL));
    p->next = newN;
    newN->data = data;
    newN->next = temp;
}

void del(NodeL* p){
    p->next = p->next->next;
}

NodeL* locate(uint64_t data, List *l){
    NodeL *p = l->head;
    while (p->next != NULL){
        if (p->next->data == data){
            return p;
        } 
        p = p->next;
    }
    return p;
}

uint64_t retrieve(NodeL* p){
    if (p->next!=NULL){
        return p->next->data;
    }
}

NodeL* next(NodeL* p){
    return p->next;
}

NodeL* prev(NodeL* p, List *l) {
    NodeL *q = l->head;
    while (q->next != NULL){
        if (q->next == p){
            return q;
        } else {
            q = q->next;
        }
    }
    return p;
}
NodeL* first (List *l){
    return l->head;
}

NodeL* end (List *l){
    NodeL* first = l->head;
    while (first->next != NULL){
        first = first->next;
    }
    return first;
}

List* makenull (List *l){
    free(l);
    List *newl = initList();
    return newl;
}

bool empty (List *l){
    if (l->head->next == NULL){
        return true;
    }
    return false;
}

void printlist (List *l){
    NodeL* node = first(l);
    while(node != end(l)){
        cout << retrieve(node) << ", ";
        node = next(node);
    }
    cout << endl;
}
