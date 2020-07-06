#include <bits/stdc++.h> 
#include "pointerstack.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <assert.h>
using namespace std; 

extern Stack *initStack();
extern void push(Stack *s, uint64_t _data);
extern void pop(Stack *s);
extern NodeS* top(Stack *s);
extern void makenull(Stack *s);
extern bool empty(Stack *s);

/*  This test is the basic sanity test for pointerstack struct
    Follow these steps:
        push 2 number in the stack
        compare if the second number is infact on top
        pop that number and check if the first number is on top
        makenull and check if the stack is empty
        return the number of good check
*/    
int test_sanity(){
    int out = 0;
    Stack *stack = initStack();
    push(stack, 1);
    push(stack, 2);
    NodeS* a = top(stack);
    if (a->data == (uint64_t)2){
        out++;
    }
    pop(stack);
    a = top(stack);
    if (a->data == (uint64_t)1){
        out++;
    }
    makenull(stack);
    if (empty(stack)){
        out++;
    }
    free(stack);
    return out;

}

/*  This test is the mass data test for pointerstack struct
    Follow these steps:
        random a number of time data will be pushed in the stack between 10000 and 40000
            push to stack a random number between 0 and 1000 
        continuously querying the top node and pop the values
        check if the total pop is equal to the total number of push
        check if the stack is empty
*/    
bool test_mass_pushPop(){
    Stack *stack = initStack();
    srand(1);
    int num = rand() % 30000 + 10000;
    for (int i = 0; i < num; i++){
        push(stack, (uint64_t) rand() % 1000);
    }
    int total = 0;
    while (!empty(stack)){
        NodeS* first = top(stack);
        pop(stack);
        total ++;
    }
    if ((total == num) && (empty(stack))){
        free(stack);
        return true;
    }
    free(stack);
    return false;
}

int main(int argc, const char *argv[])
{	
    printf("Running test for pointer stack\n");
    assert(test_sanity() == 3);
    printf("Passed 1st test - sanity test\n");
    assert(test_mass_pushPop() == true);
    printf("Passed 2nd test - mass data test\n");
    return 0;
}

