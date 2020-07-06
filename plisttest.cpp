#include <bits/stdc++.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <assert.h>
using namespace std; 

#include "pointerlist.h"


/*  This test is the basic sanity test for pointeralist struct

*/    
int test_sanity(){
    int out = 0;
    List *l = initList();
    // printf("insert done\n");
    // fflush(stdout);
    makenull(l);
    
    insert((uint64_t)3, l->head);
    // printf("insert done\n");
    // fflush(stdout);
    assert(locate((uint64_t)3, l) == l->head);
    insert((uint64_t)7, l->head->next);
    insert((uint64_t)5, l->head->next);
    assert(l->head->next->next->next->next == NULL);
    assert(l->head->next->next->next == end(l));

    assert(l->head->next->data == (uint64_t)3);
    assert(l->head->next->next->data == (uint64_t)5);
    assert(l->head->next->next->next->data == (uint64_t)7);

    assert(locate((uint64_t)3, l) == l->head);
    assert(locate((uint64_t)5, l) == l->head->next);
    assert(locate((uint64_t)7, l) == l->head->next->next);
    assert(locate((uint64_t)9, l) == end(l));

    assert(retrieve(l->head) == (uint64_t)3);
    assert(retrieve(l->head->next) == (uint64_t)5);
    assert(retrieve(l->head->next->next) == (uint64_t)7);
    
    assert(prev(l->head->next, l) == l->head);
    assert(prev(l->head->next->next, l) == l->head->next);
    assert(prev(l->head->next->next->next, l) == l->head->next->next);
    
    del(first(l));
    assert(l->head->next->data == (uint64_t)5);
    del(prev(end(l), l));
    assert(l->head->next == end(l));
    assert(first(l) == l->head);
    l = makenull(l);
    assert(l->head->next == NULL);
    assert(l->head == end(l));
    free(l);
    return 0;
}


int main(int argc, const char *argv[])
{	
    printf("Running test for pointer list\n");
    assert(test_sanity() == 0);
    printf("Passed comprehensive sanity test\n");

}

