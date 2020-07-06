#include <bits/stdc++.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std; 


typedef struct StackA
{
    uint64_t top;
    unsigned size; // Current size of the StackA
    uint64_t* arrayL;
}StackA;


StackA *initStackA();
void push(StackA *s, uint64_t _data);
void pop(StackA *s);
uint64_t top(StackA *s);
void makenull(StackA *s);
bool empty(StackA *s);