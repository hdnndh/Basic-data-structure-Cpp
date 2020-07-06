#include <bits/stdc++.h> 
#include <stdio.h>      /* // ////printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "pointerlist.h"
#include "arraylist.h"



List* concatList (List* a, List* b){
    List* result = initList();
    NodeL* na = first(a);
    NodeL* nb = first(b);
	result->head->next = na->next;
    end(result)->next = nb->next;
    return result;
}


ListA* concatAList(ListA * a, ListA * b){ //same as above, but for ListA *s
	ListA* result = initListA();
    uint64_t na = next(first(a), a);
    uint64_t nb = next(first(b), b);
    for (int i = 2; i < end(a); i ++){
        insert(retrieve(i, a), end(result), result);
    }
    for (int i = 2; i < end(b); i ++){
        insert(retrieve(i, b), end(result), result);
    }

    return result;
}

List* concatNLists(List *arr[], int n){ //takes in an array of Lists and n which is the size of the array
	List *out = initList();
    for (int i = 0; i < n; i++){ //merges all of the lists
		out = concatList(out, arr[i]);
	}
	return out;
}

ListA* concatNALists(ListA * arr[], int n){ //same as above but for ListA *s
	ListA *out = initListA();
	for (int i = 0; i < n; i++){
		out = concatAList(out, arr[i]);
	}
	return out;
}

int main(){
	List* l1 = initList();
    List* l2 = initList();
    List* l3 = initList();
	List* arr1[3];
	for (int i = 1; i <= 10; i++){ 
		insert(i, end(l1));
	}
	for (int i = 11; i <= 20; i++){ 
		insert(i, end(l2));
	}
    for (int i = 21; i <= 30; i++){ 
		insert(i, end(l3));
	}
	cout << "My original pointer lists are: " << endl;
    printlist(l1);
    printlist(l2);
    printlist(l3);
	arr1[0] = l1; //add the lists to an array
	arr1[1] = l2;
	arr1[2] = l3;
	List* out1 = concatNLists(arr1, 3);
    
	cout << "My concat pointer list is: " << endl;
    printlist(out1);
    free(l1);
    free(l2);
    free(l3);
    printf("\n-------------------------------------\n");
	
	ListA* l4 = initListA();
    ListA* l5 = initListA();
    ListA* l6 = initListA();
	ListA* arr2[3];
	for (int i = 1; i <= 10; i++){ 
		insert(i, end(l4), l4);
	}
	for (int i = 11; i <= 20; i++){ 
		insert(i, end(l5), l5);
	}
    for (int i = 21; i <= 30; i++){ 
		insert(i, end(l6), l6);
	}
	cout << "My original arr lists are: " << endl;
    printlist(l4);
    printlist(l5);
    printlist(l6);
	arr2[0] = l4; //add the lists to an array
	arr2[1] = l5;
	arr2[2] = l6;
	ListA* out2 = concatNALists(arr2, 3);
    
	cout << "My concat arr list is: " << endl;
    printlist(out2);
	free(l4);
    free(l5);
    free(l6);
	return 0;
}