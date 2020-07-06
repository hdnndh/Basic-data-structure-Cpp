#include <bits/stdc++.h> 
#include <stdio.h>      /* // printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <assert.h>

#include "loctree.h"
#include "treeutil.h"

using namespace std; 
   
int test_sanity(){
    int out = 0;
    LocTree *T = initTree();
    if (root(T) == 0){
        // // printf("####################\n");
        // fflush(stdout);
        out ++;
        //above value is actually NULL
    }
    return out;

}


int test_create(){
    // LocTree *T1 = create0(1);
    // LocTree *T2 = create0(2);
    // LocTree *T3 = create0(3);
    // LocTree *T4 = create0(4);
    LocTree *T5 = create0(5);
    LocTree *T6 = create0(6);
    LocTree *T7 = create0(7);
    LocTree *T8 = create0(8); 
    LocTree *T9 = create0(9);
    LocTree *T10 = create0(10);
    LocTree *T11 = create0(11);
    LocTree *T12 = create0(12);
    LocTree *T13 = create0(13);
    // printf("sizeofUINT: %d", sizeof(uint64_t *));
    // printf("done leafs\n");
    fflush(stdout);
    LocTree *T2 = create3(2, T5, T6, T7);
    LocTree *T3 = create3(3, T8, T9, T10);
    LocTree *T4 = create3(4, T11, T12, T13);

    LocTree *T1 = create3(1, T2, T3, T4);

    printf("\n---- PRE ORDER ----\n");
    preorder(1, T1);
    printf("\n---- POST ORDER ----\n");
    postorder(1, T1);
    printf("\n---- LEVEL ORDER ----\n");
    levelorder(1, T1);
    printf("\n-\n");    
    
    
    free(T1);
    free(T2);
    free(T3);
    free(T4);
    free(T5);
    free(T6);
    free(T7);
    free(T8);
    free(T9);
    free(T10);
    free(T11);
    free(T12);
    free(T13);
    
    return 0;
}


int main(int argc, const char *argv[])
{	
    printf("Running test for array stack\n");
    assert(test_sanity() == 1);
    printf("Passed 1st test - sanity test\n");
    assert(test_create() == 0);
    printf("Passed 2nd test - mass test\n");
    return 0;
}

