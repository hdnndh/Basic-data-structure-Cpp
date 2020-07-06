#include <bits/stdc++.h> 
#include <stdio.h>      /* // printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <assert.h>

#include "loctree.h"
#include "lcrstree.h"

#include "treeutil.h"



int main(int argc, const char *argv[])
{	
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

    printf("Making lcrs tree\n");
    fflush(stdout);
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
    // printf("label = %d, parent = %d, lc = %d, rs = %d", lT->cell[10]->label, lT->cell[lT->cell[10]->pr]->label, lT->cell[lT->cell[10]->lc]->label, lT->cell[lT->cell[10]->rs]->label);
    printf("Tree:\n");
    printf("	           1 \n");
    printf("	     /     |     \\ \n");
    printf("	    2      3      4 \n");
    printf("	   /|\\    /|\\    /|\\ \n");
    printf("	  5 6 7  8 910  111213 \n");

    printf("\n---- LEVEL ORDER LOC TREE ----\n");
    levelorder(1, T1);

    printf("\n----------------------------------------\n");
    

    printf("\n---- LEVEL ORDER LCRS TREE----\n");
    levelorder(13, lT);

    printf("\n----------------------------------------\n");


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
    free(lT);
    
    return 0;
}