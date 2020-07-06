#include <bits/stdc++.h> 
#include "arraylist.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <assert.h>
using namespace std; 



/*  This test is the basic sanity test for pointeralist struct

*/    
int test_sanity(){
    int out = 0;
    ListA *alist = initListA();
    makenull(alist);
    assert(insert((uint64_t)3, (uint64_t)1, alist) == 0);
    assert(insert((uint64_t)7, (uint64_t)2, alist) == 0);
    assert(insert((uint64_t)5, (uint64_t)2, alist) == 0);
    assert(insert((uint64_t)9, (uint64_t)0, alist) == 1);
    assert(insert((uint64_t)11, (uint64_t)5, alist) == 1);

    assert(locate((uint64_t)3, alist) == 1);
    // printf("--%d--\n", (int)locate((uint64_t)5, alist));
    // printf("--%d--\n", (int)retrieve((uint64_t)1, alist));
    // printf("--%d--\n", (int)retrieve((uint64_t)2, alist));
    // printf("--%d--\n", (int)retrieve((uint64_t)3, alist));
    // fflush(stdout);
    assert(locate((uint64_t)5, alist) == 2);
    assert(locate((uint64_t)7, alist) == alist->last);
    assert(locate((uint64_t)9, alist) == end(alist));

    assert(retrieve((uint64_t)1, alist) == 3);
    assert(retrieve((uint64_t)alist->last, alist) == 7);
    assert(retrieve(locate((uint64_t)5, alist), alist) == 5);

    assert(next((uint64_t)1, alist) == 2);
    assert(next((uint64_t)alist->last, alist) == end(alist));
    assert(next((uint64_t)-1, alist) == 0);

    assert(prev((uint64_t)3, alist) == 2);
    assert(prev(end(alist) + (uint64_t)1, alist) == 0);
    assert(prev(end(alist), alist) == alist->last);
    assert(prev((uint64_t)-131, alist) == 0);

    assert(first(alist) == 1);
    assert(end(alist) == 4);

    assert(del((uint64_t)1, alist) == 0);
    assert(first(alist) == 1);
    assert(locate((uint64_t)3, alist) == end(alist));
    assert(retrieve((uint64_t)1, alist) == 5);
    assert(retrieve(next(locate((uint64_t)5, alist), alist), alist) == 7);
    assert(insert((uint64_t)2, (uint64_t)1, alist) == 0);
    assert(del((uint64_t)2, alist) == 0);
    assert(retrieve(next(locate((uint64_t)2, alist), alist), alist) == 7);
    assert(retrieve(prev(locate((uint64_t)7, alist), alist), alist) == 2);
    
    makenull(alist);
    assert(alist->last == 0);
    free(alist);
    return 0;
}


int main(int argc, const char *argv[])
{	
    printf("Running test for array list\n");
    assert(test_sanity() == 0);
    printf("Passed comprehensive sanity test\n");

}

