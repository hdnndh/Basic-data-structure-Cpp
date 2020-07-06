#ifndef TREEUTIL_H
#define TREEUTIL_H

#include <bits/stdc++.h> 
#include <stdio.h>      /* // printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "pointerlist.h"
#include "loctree.h"
#include "lcrstree.h"
#include "pointerqueue.h"



void preorder(uint64_t n, LocTree *Tr){ //traverses preorder
	cout << label(n, Tr) << ", ";
    uint64_t c = leftmost_child(n, Tr);
    while (c!= 0) {
        
        preorder(c, Tr);


        c = right_sibling(c, Tr);

    }
}


void preorder(uint64_t n, LocTree *Tr, bool ch){ //traverses preorder
    uint64_t out = label(n, Tr);
    if ((ch == true) && (out > 40)){
	    cout << (char)out << ", ";
    }else{
        cout << out << ", ";
    }
    uint64_t c = leftmost_child(n, Tr);
    while (c!= 0) {
        
        preorder(c, Tr, ch);


        c = right_sibling(c, Tr);

    }
}


void preorder(uint64_t n, LcrsTrees *Tr){ //traverses preorder
	cout << label(n, Tr) << ", ";
    
    uint64_t c = leftmost_child(n, Tr);
    // printf("\n---- %d\n", n);
    // fflush(stdout);
    while (c!= 0) {
        // printf("\n---- %d\n", c);
        // fflush(stdout);
        preorder(c, Tr);
        c = right_sibling(c, Tr);

    }
}


void postorder(uint64_t n, LocTree *Tr){ //traverses postorder
    uint64_t c = leftmost_child(n, Tr);
    while (c!= 0) {
        
        postorder(c, Tr);


        c = right_sibling(c, Tr);

    }
    cout << label(n, Tr) << ", ";
}


void postorder(uint64_t n, LocTree *Tr, bool ch){ //traverses postorder
    uint64_t c = leftmost_child(n, Tr);
    while (c!= 0) {
        
        postorder(c, Tr, ch);


        c = right_sibling(c, Tr);

    }
    uint64_t out = label(n, Tr);
    if ((ch == true) && (out > 40)){
	    cout << (char)out << ", ";
    }else{
        cout << out << ", ";
    }
}


void postorder(uint64_t n, LcrsTrees *Tr){ //traverses postorder
    uint64_t c = leftmost_child(n, Tr);
    while (c!= 0) {
        
        postorder(c, Tr);


        c = right_sibling(c, Tr);

    }
    cout << label(n, Tr) << ", ";
}


void levelorder(uint64_t n, LocTree *Tr){ //traverses postorder
    Queue * q = initQueue();
    uint64_t c = n;
    enqueue(q, c);
    while (c != 0){
        if (empty(q)){
            c = 0;
        } else {
            c = front(q)->data;
            dequeue(q);
            cout << label(c, Tr) << ", ";
            uint64_t l = leftmost_child(c, Tr);
            if (l != 0){
                enqueue(q, l);
            }
            uint64_t r = right_sibling(l, Tr); 
            while (r != 0){
                enqueue(q, r);
                r = right_sibling(r, Tr); 
            }
        }
    }
}


void levelorder(uint64_t n, LcrsTrees *Tr){ //traverses postorder
    Queue * q = initQueue();
    uint64_t c = n;
    enqueue(q, c);
    while (c != 0){
        if (empty(q)){
            c = 0;
        } else {
            c = front(q)->data;
            dequeue(q);
            cout << label(c, Tr) << ", ";
            uint64_t l = leftmost_child(c, Tr);
            if (l != 0){
                enqueue(q, l);
            }
            uint64_t r = right_sibling(l, Tr); 
            while (r != 0){
                enqueue(q, r);
                r = right_sibling(r, Tr); 
            }
        }
    }
}


#endif