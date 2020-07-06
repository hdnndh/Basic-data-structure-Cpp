#include <bits/stdc++.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std; 
#include "arraystack.h"
#define MAX 64000

StackA *initStackA(){
    StackA *s = (StackA *)malloc(sizeof(StackA));
    s->size = MAX;
    s->arrayL = (uint64_t*)malloc(s->size * sizeof(uint64_t)); 
    s->top = MAX + 1;
    return s;
}

void push(StackA *s, uint64_t _data){
    if (s->top == 1){
        printf("Error stack is full\n");
        exit(1);
    }
    s->top --;
    s->arrayL[s->top] = _data;
}

void pop(StackA *s){
    if (empty(s)){
        printf("Error stack is empty\n");
        exit(1);
    }
    s->top++;
}

uint64_t top(StackA *s){
    if (empty(s)){
        printf("Error stack is empty\n");
        exit(1);
    }
    return s->arrayL[s->top];
}

void makenull(StackA *s){
    s->top = MAX + 1;
}

bool empty(StackA *s){
    if (s->top > MAX){
        return true;
    }
    return false;
}