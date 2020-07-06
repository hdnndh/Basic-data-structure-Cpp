#include <bits/stdc++.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <assert.h>
#include "pointerqueue.h"

using namespace std; 


/*  This test is the basic sanity test for pointerqueue struct
    Follow these steps:
        push 2 number in the queue
        compare if the second number is infact on top
        pop that number and check if the first number is on top
        makenull and check if the queue is empty
        return the number of good check
*/    
int test_sanity(){
    int out = 0;
    Queue *queue = initQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    NodeQ* a = front(queue);
    if (a->data == (uint64_t)1){
        out++;
    }
    dequeue(queue);
    a = front(queue);
    if (a->data == (uint64_t)2){
        out++;
    }
    makenull(queue);
    if (empty(queue)){
        out++;
    }
    free(queue);
    return out;
}



/*  This test is the mass data test for pointerqueue struct
    Follow these steps:
        random a number of time data will be pushed in the queue between 10000 and 40000
            push to queue a random number between 0 and 1000 
        continuously querying the top node and pop the values
        check if the total pop is equal to the total number of push
        check if the queue is empty
*/    
bool test_mass(){
    Queue *queue = initQueue();
    srand(1);
    int num = rand() % 64000 + 0;
    for (int i = 0; i < num; i++){
        enqueue(queue, (uint64_t) rand() % 1000);
    }
    int total = 0;
    while (!empty(queue)){
        NodeQ* _front = front(queue);
        dequeue(queue);
        total ++;
    }
    if ((total == num) && (empty(queue))){
        free(queue);
        return true;
    }
    free(queue);
    return false;
}



int main(int argc, const char *argv[])
{	
    printf("Running test for pointer queue\n");
    assert(test_sanity() == 3);
    printf("Passed 1st test - sanity test\n");
    assert(test_mass() == true);
    printf("Passed 2nd test - mass data test\n");
    return 0;
}

