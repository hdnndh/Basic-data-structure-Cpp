#include <bits/stdc++.h> 
#include <stdio.h>      /* #// // printf\, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std; 

#include "pointerlist.h"
#include "lcrstree.h"

#define MAX 64000



LcrsTrees *initLRTree(){
    LcrsTrees *lt = (LcrsTrees *)malloc(sizeof(LcrsTrees));
    lt->size = 0;
    lt->cell = (CellT **)malloc(MAX * sizeof(CellT*));
    lt->maxNode = MAX ;
    return lt;
}

CellT *initCellT(){
    CellT *ct = (CellT *)malloc(sizeof(CellT));
    ct->label = 0;
    ct->lc = 0;
    ct->rs = 0;
    ct->pr = 0;
    return ct;
}


// Return leftmost child of node n of Loctree T
uint64_t leftmost_child(uint64_t n, LcrsTrees* T){
    CellT* cell = T->cell[n];
    if (cell == NULL){
        return 0;
    } else {
        return cell->lc;
    }
    return 0;
}


uint64_t parent(uint64_t n, LcrsTrees* T){
    CellT* cell = T->cell[n];
    if (cell == NULL){
        return 0;
    } else {
        return cell->pr;
    }
    return 0;
}


uint64_t right_sibling(uint64_t n, LcrsTrees* T){
    CellT* cell = T->cell[n];
    if (cell == NULL){
        return 0;
    } else {
        return cell->rs;
    }
    return 0;
}


uint64_t label(uint64_t n, LcrsTrees* T){
    CellT* cell = T->cell[n];
    if (cell == NULL){
        return 0;
    } else {
        return cell->label;
    }
    return 0;
}


void create0(uint64_t v, LcrsTrees* T){
    uint64_t n = ++T->size;
    // printf("----------------%d\n", n);
    // fflush(stdout);
    CellT *ct = initCellT();
    T->cell[n] = ct;
    T->cell[n]->label = v;
}

void create1(uint64_t v, uint64_t T1, LcrsTrees* T){
    uint64_t n = ++T->size;
    CellT *ct = initCellT();
    T->cell[n] = ct;

    T->cell[n]->lc = T1;
    T->cell[n]->label = v;

    T->cell[T1]->pr = n;
    T->cell[T1]->rs = 0;
}


void create2(uint64_t v, uint64_t T1, uint64_t T2, LcrsTrees* T){
    uint64_t n = ++T->size;
    CellT *ct = initCellT();
    T->cell[n] = ct;

    T->cell[n]->lc = T1;
    T->cell[n]->label = v;

    T->cell[T1]->rs = T2;
    T->cell[T2]->rs = 0;

    T->cell[T1]->pr = n;
    T->cell[T2]->pr = n;
}


void create3(uint64_t v, uint64_t T1, uint64_t T2, uint64_t T3, LcrsTrees* T){
    uint64_t n = ++T->size;
    CellT *ct = initCellT();
    T->cell[n] = ct;

    T->cell[n]->lc = T1;
    T->cell[n]->label = v;

    T->cell[T1]->rs = T2;
    T->cell[T2]->rs = T3;
    T->cell[T3]->rs = 0;

    T->cell[T1]->pr = n;
    T->cell[T2]->pr = n;
    T->cell[T3]->pr = n;
}

uint64_t root(LcrsTrees *T){
    return T->size;
}


LcrsTrees* makenull (LcrsTrees *T){
    free(T);
    LcrsTrees *newt = initLRTree();
    return newt;
}