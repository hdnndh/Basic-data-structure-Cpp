#include <bits/stdc++.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std; 


typedef struct ListA
{
    uint64_t last;
    uint64_t* arrayL;
}ListA;


ListA *initListA();
int insert(uint64_t data, uint64_t p, ListA *l);
int del(uint64_t p, ListA *l);
uint64_t locate(uint64_t data, ListA *l);
uint64_t retrieve(uint64_t p, ListA *l);
uint64_t next(uint64_t p, ListA *l);
uint64_t prev(uint64_t p, ListA *l);
uint64_t first (ListA *l);
uint64_t end (ListA *l);
void makenull (ListA *l);
bool empty(ListA *l);
void printlist(ListA* l);