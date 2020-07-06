#include <iostream>
#include "pointerqueue.h"
#include "loctree.h"
#include "treeutil.h"
#include "pointerlist.h"

using namespace std;

// 3.13 (assume that the label of each NodeQ* consists of two fields: 
    // a unique integer identifying the NodeQ* 
    // an identifier l or i indicating whether a NodeQ* is a leaf or an internal NodeQ*)

Queue *preToPost(Queue *pre){ //preorder to postorder
	Queue *post = initQueue();
    NodeQ *node= front(pre);
    while ((node->next != NULL) && (node->next->next != NULL)){
		if (node->next->id == 'l'){

			enqueue(post, node->next->data);

			enqueue(post, node->next->next->data);

			enqueue(post, node->data);

			node = node->next;
		}

		node = node->next;
	}

    enqueue(post, front(pre)->data);

	return(post);
}

Queue *postToPre(Queue *post){ //postorder to preorder
	Queue *pre = initQueue();
    NodeQ *node1= front(post);
	while (node1->next != NULL){
		node1 = node1->next;
	}
	enqueue(pre, node1->data);
	NodeQ *node= front(post);
	node = front(post);
    while ((node->next != NULL) && (node->next->next != NULL) ){
		if (node->next->next->id == 'i'){
			enqueue(pre, node->next->next->data);
			enqueue(pre, node->data);
			enqueue(pre, node->next->data);
			node = node->next;
		}
		node = node->next;
	}
	return(pre);
}

int main(){
//	      1
//	     /\
//	    2  3
//	   /\  /\
//	  4  5 6 7


	Queue *preorder = initQueue();
    enqueue2(preorder, 1, 'i');
    enqueue2(preorder, 2, 'i');
    enqueue2(preorder, 4, 'l');
    enqueue2(preorder, 5, 'l');
    enqueue2(preorder, 3, 'i');
    enqueue2(preorder, 6, 'l');
    enqueue2(preorder, 7, 'l');
    
	Queue *postorder = initQueue();
    enqueue2(postorder, 4, 'i');
    enqueue2(postorder, 5, 'i');
    enqueue2(postorder, 2, 'l');
    enqueue2(postorder, 6, 'i');
    enqueue2(postorder, 7, 'i');
    enqueue2(postorder, 3, 'l');
    enqueue2(postorder, 1, 'l');

	Queue *preToPostOutput = initQueue();
	Queue *postToPreOutput = initQueue();

	cout << "CONVERTED TO POST ORDER: ";
	preToPostOutput = preToPost(preorder);
	while(!empty(preToPostOutput)){
		cout << front(preToPostOutput)->data;
		dequeue(preToPostOutput);
	}
	cout <<endl;

	cout << "CONVERTED TO POST ORDER: ";
	postToPreOutput = postToPre(postorder);
	while(!empty(postToPreOutput)){
		cout << front(postToPreOutput)->data;
		dequeue(postToPreOutput);
	}
	cout <<endl;

	return 0;
}

