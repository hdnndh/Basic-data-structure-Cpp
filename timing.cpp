#include <ctime>

#include "loctree.h"
#include "treeutil.h"
#include "pointerlist.h"
#include "lcrstree.h"


using namespace std; 



/*
---- PRE ORDER LOC TREE ----
1, 2, 5, 6, 7, 3, 8, 9, 10, 4, 11, 12, 13, 
[Timing]
0.024 milliseconds


---- POST ORDER LOC TREE----
5, 6, 7, 2, 8, 9, 10, 3, 11, 12, 13, 4, 1, 
[Timing]
0.024 milliseconds


----------------------------------------

---- PRE ORDER LCRS TREE----
1, 2, 5, 6, 7, 3, 8, 9, 10, 4, 11, 12, 13, 
[Timing]
0.003 milliseconds


---- POST ORDER LCRS TREE----
5, 6, 7, 2, 8, 9, 10, 3, 11, 12, 13, 4, 1, 
[Timing]
0.003 milliseconds

----------------------------------------
    We can cleary see that LCRS tree implementation with Parent collumn within cell space
performed supperior against LOC tree.
    Both left child and parent call for LCRS tree are O(n) for LocTree, while LCRS tree search
time is only O(1) as those are already stored within the table.
    Roughly 8 times as fast for both traversal operations

*/


int traverse(){
    clock_t start, stop;
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
    printf("\n---- PRE ORDER LOC TREE ----\n");
    start = clock();
    preorder(1, T1);
    stop  = clock();
    cout << "\n[Timing]\n";
    cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n\n";

    printf("\n---- POST ORDER LOC TREE----\n");
    start = clock();
    postorder(1, T1);
    stop  = clock();
    cout << "\n[Timing]\n";
    cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n\n";
    printf("\n----------------------------------------\n");
    

    printf("\n---- PRE ORDER LCRS TREE----\n");
    fflush(stdout);
    start = clock();
    preorder(13, lT);
    stop  = clock();
    cout << "\n[Timing]\n";
    cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n\n";

    printf("\n---- POST ORDER LCRS TREE----\n");
    fflush(stdout);
    start = clock();
    postorder(13, lT);
    stop  = clock();
    cout << "\n[Timing]\n";
    cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n\n";
    printf("----------------------------------------\n");


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


int main (void)
{
  
    traverse();

    return 0;
}
