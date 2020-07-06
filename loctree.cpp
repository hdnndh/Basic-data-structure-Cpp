#include <bits/stdc++.h> 
#include <stdio.h>      /* #// // printf\, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std; 

#include "loctree.h"
#include "pointerlist.h"

#define MAX 64000


extern List *initList();
extern void insert(uint64_t data, NodeL* p);
extern void del(NodeL* p);
extern NodeL* locate(uint64_t data, List *l);
extern uint64_t retrieve(NodeL* p);
extern NodeL* next(NodeL* p);
extern NodeL* prev(NodeL* p, List *l);
extern NodeL* first (List *l);
extern NodeL* end (List *l);
extern List* makenull (List *l);
extern bool empty(List *l);


LocTree *initTree(){
    LocTree *lt = (LocTree *)malloc(sizeof(LocTree));
    lt->size = 0;
    lt->headers = (List **)malloc(MAX * sizeof(List *));
    lt->labels = (uint64_t *)malloc(MAX * sizeof(uint64_t )); 
    lt->maxNode = MAX ;
    return lt;
}


// Return leftmost child of node n of Loctree T
uint64_t leftmost_child(uint64_t n, LocTree* T){
    List *L = T->headers[n];
    if (empty(L)){
        return 0;
    } else {
        return retrieve(first (L));
    }
}


uint64_t parent(uint64_t n, LocTree* T){
    for (uint64_t p = (uint64_t)1; p <= T->size; p++){
        List *L = T->headers[p];
        NodeL *node = first(L);

        while (node != end(L)){
            if (retrieve(node) == n){
                return p;
            } else {
                node = next(node);
            }
        }
        // printf("ending for, p= %d\n", p);
        fflush(stdout);
    }
    
    return 0;
}


uint64_t right_sibling(uint64_t n, LocTree* T){
    uint64_t p = parent(n, T);
    if (p != 0){     
        List *L = T->headers[p];
        NodeL *node = first(L);
        while (node != end(L)){
            if (retrieve(node) == n){
                if (node->next->next != NULL){
                    // printf("right_sibling for, out= %d\n", node->next->next->data);
                    fflush(stdout);
                    return node->next->next->data;
                } else {
                    return 0;
                }
            } else {
                node = next(node);
            }
        } 
        return 0;
    } else {
        return 0;
    }
    return 0;
}


uint64_t label(uint64_t n, LocTree* T){
    if ((n >= (uint64_t)1) && (n <= T->size)){
        return T->labels[n];
    } else {
        return -MAX;
    }
}


LocTree * create0(uint64_t v){
    uint64_t n = 1;
    LocTree *T = initTree();
    T->headers[n] = initList();
    T->labels[n] = v;
    T->size = 1;
    return T;
}

LocTree * create1(uint64_t v, LocTree* T1){
    uint64_t n = 1;
    LocTree *T = initTree();
    T->headers[n] = initList();
    T->labels[n] = v;
    T->size = (uint64_t)1;
    insert(T->size+(uint64_t)1, T->headers[n]->head);
    for (uint64_t i = (uint64_t)1; i <= T1->size; i++){
        T->headers[i+T->size] = T1->headers[i];
        if (!empty(T->headers[i+T->size])){
            NodeL* node = next(first(T->headers[i+T->size]));       
            while (node != NULL) {
                node->data = T->size + node->data;
                node = node->next;
            }
        }
        T->labels[i+T->size] = T1->labels[i];
    }
    T->size = T1->size + T->size;
    return T;
}


LocTree * create2(uint64_t v, LocTree* T1, LocTree* T2){
    uint64_t n = 1;
    LocTree *T = initTree();
    T->headers[n] = initList();
    T->labels[n] = v;
    T->size = (uint64_t)1;

    insert(T->size+(uint64_t)1, end(T->headers[n]));
    for (uint64_t i = (uint64_t)1; i <= T1->size; i++){
        T->headers[i+T->size] = T1->headers[i];
        if (!empty(T->headers[i+T->size])){
            NodeL* node = next(first(T->headers[i+T->size]));       
            while (node != NULL) {
                node->data = T->size + node->data;
                node = node->next;
            }
        }
        T->labels[i+T->size] = T1->labels[i];
    }
    T->size = T1->size + T->size;

    insert(T->size+(uint64_t)1, end(T->headers[n]));
    for (uint64_t i = (uint64_t)1; i <= T2->size; i++){
        T->headers[i+T->size] = T2->headers[i];
        if (!empty(T->headers[i+T->size])){
            NodeL* node = next(first(T->headers[i+T->size]));       
            while (node != NULL) {
                node->data = T->size + node->data;
                node = node->next;
            }
        }
        T->labels[i+T->size] = T2->labels[i];
    }
    T->size = T2->size + T->size;
    return T;
}


LocTree * create3(uint64_t v, LocTree* T1, LocTree* T2, LocTree* T3){
    uint64_t n = 1;
    LocTree *T = initTree();
    T->headers[n] = initList();
    T->labels[n] = v;
    T->size = (uint64_t)1;

    insert(T->size+(uint64_t)1, end(T->headers[n]));
    
    for (uint64_t i = (uint64_t)1; i <= T1->size; i++){
        T->headers[i+T->size] = T1->headers[i];
        if (!empty(T->headers[i+T->size])){
            NodeL* node = next(first(T->headers[i+T->size]));  
            // // // printf("Starting while\n");
            fflush(stdout);     
            while (node != NULL) {
                // // printf("Iter----\n");
                fflush(stdout);    
                node->data = T->size + node->data;
                node = node->next;
            }
        }
        T->labels[i+T->size] = T1->labels[i];
        // // printf("iteration-label: %d - ""%"PRIu64" \n",i+T->size , T1->labels[i]);
    }
    T->size = T1->size + T->size;

    insert(T->size+(uint64_t)1, end(T->headers[n]));
    for (uint64_t i = (uint64_t)1; i <= T2->size; i++){
        T->headers[i+T->size] = T2->headers[i];
        if (!empty(T->headers[i+T->size])){
            NodeL* node = next(first(T->headers[i+T->size]));       
            while (node != NULL) {
                node->data = T->size + node->data;
                node = node->next;
            }
        }
        T->labels[i+T->size] = T2->labels[i];
        // // printf("iteration-label: %d - ""%"PRIu64" \n",i+T->size , T2->labels[i]);
    }
    T->size = T2->size + T->size;

    insert(T->size+(uint64_t)1, end(T->headers[n]));
    for (uint64_t i = (uint64_t)1; i <= T3->size; i++){
        T->headers[i+T->size] = T3->headers[i];
        if (!empty(T->headers[i+T->size])){
            NodeL* node = next(first(T->headers[i+T->size]));       
            while (node != NULL) {
                node->data = T->size + node->data;
                node = node->next;
            }
        }
        T->labels[i+T->size] = T3->labels[i];
        // // printf("iteration-label: %d - ""%"PRIu64" \n",i+T->size , T3->labels[i]);
    }
    T->size = T2->size + T->size;
    return T;
}


uint64_t root(LocTree *T){
    if(T->headers[(uint64_t)1] == NULL){
        return 0;
    } else {
        return (uint64_t)1;
    }
}


LocTree* makenull (LocTree *T){
    free(T);
    LocTree *newt = initTree();
    return newt;
}