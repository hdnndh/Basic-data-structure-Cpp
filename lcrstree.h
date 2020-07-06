#ifndef LCRSTREE_H
#define LCRSTREE_H

#include <bits/stdc++.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "pointerlist.h"

using namespace std; 

#define MAX 64000



struct NodeT
{
    uint64_t label;
    uint64_t header;
};
typedef struct NodeT NodeT;


struct CellT
{
    uint64_t lc;
    uint64_t rs;
    uint64_t label;
    uint64_t pr;
};
typedef struct CellT CellT;


struct LcrsTrees
{
    CellT** cell;
    uint64_t size; // Current size of the Stack
    uint64_t maxNode;
};
typedef struct LcrsTrees LcrsTrees;


LcrsTrees *initLRTree();
uint64_t leftmost_child(uint64_t n, LcrsTrees* T);
uint64_t parent(uint64_t n, LcrsTrees* T);
uint64_t right_sibling(uint64_t n, LcrsTrees* T);
uint64_t label(uint64_t n, LcrsTrees* T);
uint64_t root(LcrsTrees *T);
void create0(uint64_t v, LcrsTrees* T);
void create1(uint64_t v, uint64_t T1, LcrsTrees* T);
void create2(uint64_t v, uint64_t T1, uint64_t T2, LcrsTrees* T);
void create3(uint64_t v, uint64_t T1, uint64_t T2, uint64_t T3, LcrsTrees* T);


#endif