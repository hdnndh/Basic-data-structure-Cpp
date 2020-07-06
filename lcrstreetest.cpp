#include <bits/stdc++.h> 
#include <stdio.h>      /* // printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <assert.h>

#include "lcrstree.h"
#include "treeutil.h"

using namespace std; 
   
int test_sanity(){
    int out = 0;
    LcrsTrees *T = initLRTree();
    if (root(T) == 0){
        // // printf("####################\n");
        // fflush(stdout);
        out ++;
        //above value is actually NULL
    }
    return out;

}


int test_create(){
    LcrsTrees *lT = initLRTree();
    create0(5, lT);
    create0(6, lT);
    create0(7, lT);
    create0(8, lT); 
    create0(9, lT);
    create0(10, lT);
    create0(11, lT);
    create0(12, lT);
    create0(13, lT);
    create3(2, 1, 2, 3, lT);
    create3(3, 4, 5, 6, lT);
    create3(4, 7, 8, 9, lT);
    create3(1, 10, 11, 12, lT);

    printf("\n---- PRE ORDER ----\n");
    preorder(13, lT);
    printf("\n---- POST ORDER ----\n");
    postorder(13, lT);
    printf("\n---- LEVEL ORDER ----\n");
    levelorder(13, lT);
    printf("\n-\n");    
    
    free(lT);
    
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

