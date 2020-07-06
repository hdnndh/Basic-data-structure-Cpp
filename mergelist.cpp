#include <bits/stdc++.h> 
#include <stdio.h>      /* 
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "pointerlist.h"
#include "arraylist.h"



List* sortedMerge(List* a, List* b){
    List* result = initList();
    NodeL* na = first(a);
    NodeL* nb = first(b);
	while( (na != end(a)) || (nb != end(b)) ){
        if ( (na == end(a)) && (nb!= end(b)) ){ 
            insert(retrieve(nb), end(result));
            nb = next(nb);
            
        }
        else if ((na != end(a)) && (nb == end(b))){ 
            insert(retrieve(na), end(result));
            na = next(na);
            
        }
        else if (retrieve(na) <= retrieve(nb)){ 
            insert(retrieve(na), end(result));
            na = next(na);
            
        }
        else{ 
            insert(retrieve(nb), end(result));
            nb = next(nb);
            
        }
    }
    return result;
}


ListA* sortedAMerge(ListA * a, ListA * b){ 
	ListA* result = initListA();
    uint64_t na = next(first(a), a);
    uint64_t nb = next(first(b), b);
	while( (na != end(a)) || (nb != end(b)) ){
        if ( (na == end(a)) && (nb!= end(b)) ){ 
            insert(retrieve(nb, b), end(result), result);
            nb = next(nb, b);
            
            
        }
        else if ((na != end(a)) && (nb == end(b))){ 
            insert(retrieve(na, result), end(result), result);
            na = next(na, a);
            
        }
        else if ((retrieve(na, a)) <= retrieve(nb, b)){ 
            insert(retrieve(na, a), end(result), result);
            na = next(na, a);
            
        }
        else{ 
            insert(retrieve(nb, b), end(result), result);
            nb = next(nb, b);
            
        }
    }
    return result;
}

List* mergeNLists(List *arr[], int n){ 
	List *out = initList();
    for (int i = 0; i < n; i++){ 
		out = sortedMerge(out, arr[i]);
	}
	return out;
}

ListA* mergeNALists(ListA * arr[], int n){ 
	ListA *out = initListA();
	for (int i = 0; i < n; i++){
		out = sortedAMerge(out, arr[i]);
	}
	return out;
}

int main(){
	List* l1 = initList();
    List* l2 = initList();
    List* l3 = initList();
	List* arr1[3];
	for (int i = 1; i <= 30; i = i + 3){ 
		insert(i, end(l1));
	}
	for (int i = 2; i <= 30; i = i + 3){ 
		insert(i, end(l2));
	}
    for (int i = 3; i <= 30; i = i + 3){ 
		insert(i, end(l3));
	}
	cout << "My original pointer lists are: " << endl;
    printlist(l1);
    printlist(l2);
    printlist(l3);
	arr1[0] = l1; 
	arr1[1] = l2;
	arr1[2] = l3;
	List* out1 = mergeNLists(arr1, 3);
    
	cout << "My merged pointer list is: " << endl;
    printlist(out1);
    NodeL* node = first(out1);
    int j = 1;
    printf("Running test\n");
    while(node != end(out1)){
        assert(retrieve(node) == j);
        node = next(node);
        j ++;
    }
    printf("Each values is correct.\n");
    free(l1);
    free(l2);
    free(l3);
    
	
	ListA* l4 = initListA();
    ListA* l5 = initListA();
    ListA* l6 = initListA();
	ListA* arr2[3];
	for (int i = 1; i <= 30; i = i + 3){ 
		insert(i, end(l4), l4);
	}
	for (int i = 2; i <= 30; i = i + 3){ 
		insert(i, end(l5), l5);
	}
    for (int i = 3; i <= 30; i = i + 3){ 
		insert(i, end(l6), l6);
	}
	cout << "My original arr lists are: " << endl;
    printlist(l4);
    printlist(l5);
    printlist(l6);
	arr2[0] = l4; 
	arr2[1] = l5;
	arr2[2] = l6;
	ListA* out2 = mergeNALists(arr2, 3);
    
	cout << "My merged arr list is: " << endl;
    printlist(out2);
    printf("Running test\n");
    for (int i = 2; i < end(out2); i ++){
        assert(retrieve(i, out2) == i - 1);
    }
    
    printf("Each values is correct.\n");
	free(l4);
    free(l5);
    free(l6);
	return 0;
}