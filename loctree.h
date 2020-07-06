#ifndef LOCTREE_H
#define LOCTREE_H

#include <bits/stdc++.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "pointerlist.h"

using namespace std; 

#define MAX 64000



struct LocTree
{
    List** headers;
    uint64_t* labels;
    uint64_t* root;
    uint64_t size; // Current size of the Stack
    uint64_t maxNode;
};
typedef struct LocTree Loctree;


LocTree *initTree();
uint64_t leftmost_child(uint64_t node, LocTree* tree);
uint64_t parent(uint64_t n, LocTree* T);
uint64_t right_sibling(uint64_t n, LocTree* T);
uint64_t label(uint64_t n, LocTree* T);
uint64_t root(LocTree *T);
LocTree * create0(uint64_t v);
LocTree * create1(uint64_t v, LocTree* T1);
LocTree * create2(uint64_t v, LocTree* T1, LocTree* T2);
LocTree * create3(uint64_t v, LocTree* T1, LocTree* T2, LocTree* T3);

#endif