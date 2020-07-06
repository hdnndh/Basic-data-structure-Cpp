#include <bits/stdc++.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std; 
#include "arraylist.h"
#define MAX 64000

ListA *initListA(){
    ListA *l = (ListA *)malloc(sizeof(ListA));
    l->arrayL = (uint64_t*)malloc(MAX * sizeof(uint64_t)); 
    l->last = 1;
    return l;
}

int insert(uint64_t data, uint64_t p, ListA *l){
    if (l->last >= (uint64_t)MAX){
        printf("____Error stack is full\n");
        return 1;
    } else if ((p > end(l)) || (p < (uint64_t) 1)){
        printf("____Position does not exist\n");
        return 1;
    } else {
        for (uint64_t q = l->last; q >= p; q --){
            l->arrayL[q + 1] = l->arrayL[q];
        }
        l->last++;
        l->arrayL[p] = data;
        return 0;
    }
}

int del(uint64_t p, ListA *l){
    if (p > l->last || (p < (uint64_t) 1)){
        printf("Position does not existl\n");
        return 1;
    } else {
        l->last --;
        for (uint64_t q = p; q <= l->last; q++){
            l->arrayL[q] = l->arrayL[q+1];
        }
        return 0;
    }
}

uint64_t locate(uint64_t data, ListA *l){
    for (uint64_t q = (uint64_t)1; q <= l->last; q++){
        // printf("finding %d, compare %d %d\n",(int)data, (int)l->arrayL[q], (int)data);
        if (l->arrayL[q] == data){
            return (q);
        }
        
    }
    return end(l);
}

uint64_t retrieve(uint64_t p, ListA *l){
    if ((p >= end(l)) || (p < (uint64_t) 1)){
        printf("Position does not existl\n");
        exit(1);
    }
    return l->arrayL[p];
}


/*
 NEXT(p, L) and PREVIOUS(p, L) return the positions following and preceding 
    position p on list L.  

If p is the last position on L, then NEXT(p, L) = END(L). 
    NEXT is undefined if p is END(L). 

PREVIOUS is undefined if p is 1. 

Both functions are undefined if L has no position p
*/
uint64_t next(uint64_t p, ListA *l){
    if (p == end(l)){
        return 0;
    }
    if (p == l->last){
        return end(l);
    }
    if (p > l->last || (p < (uint64_t) 1)){
        return 0;
    }
    return p + (uint64_t)1;
}

uint64_t prev(uint64_t p, ListA *l){
    if (p == 1){
        return 0;
    }
    if (p > end(l) || (p < (uint64_t) 1)){
        return 0;
    }
    return p - (uint64_t)1;

}

uint64_t first (ListA *l){
    return 1;
}

uint64_t end (ListA *l) {
    return l->last + (uint64_t)1;
}

void makenull (ListA *l){
    l->last = 0;
}

bool empty(ListA *l) {
    if(l->last == 0){
        return true;
    }
    return false;
}

void printlist (ListA *l){
    for (int i = 2; i < end(l); i ++){
        cout << retrieve(i, l) << ", ";
    }
    cout << endl;
}
