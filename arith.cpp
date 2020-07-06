#include "pointerstack.h"
#include "treeutil.h"
#include "loctree.h"

int postorderEval(List *operands, Stack *operation){
	uint64_t a, b, result;
	char c;
	while (!empty(operation)){
		a = retrieve(first(operands)); //first number
		del(first(operands));
		b = retrieve(first(operands)); //second number
		del(first(operands));
		c = (char) top(operation)->data; //first operator
		pop(operation);
		if (c == '+'){ //check for operator and perform that operation
			result = a + b;
			
		}
		if (c == '-'){
			result = a - b;
		}
		if (c == '*'){
			result = a * b;
		}
		if (c == '/'){
			result = a / b;
		}
        insert(result, end(operands));
	}
	return result;
}

int preorderEval(List *operands, Queue *operation){
	uint64_t a, b, result;
	char c;
	while (!empty(operation)){
		a = retrieve(first(operands)); //first number
		del(first(operands));
		b = retrieve(first(operands)); //second number
		del(first(operands));
		c = (char) front(operation)->data; //first operator
		dequeue(operation);
		if (c == '+'){ //check for operator and perform that operation
			result = a + b;
		}
		if (c == '-'){
			result = a - b;
		}
		if (c == '*'){
			result = a * b;
		}
		if (c == '/'){
			result = a / b;
		}
        insert(result, end(operands));
	}
	return result;
}

int main(){
    cout << "(1 + 2)*(1 + 3)" << endl;
    LocTree *T4 = create0(1);
	LocTree *T5 = create0(2);
    LocTree *T6 = create0(1);
    LocTree *T7 = create0(3);
    LocTree *T2 = create2((uint64_t)'+', T4, T5);
    LocTree *T3 = create2((uint64_t)'+', T6, T7);
    LocTree *T1 = create2((uint64_t)'*', T2, T3);
    cout << "preorder expression is ";
    preorder(1, T1, true);
    printf("\n----------------------------------------\n");
    cout << "Postorder expression is ";
    postorder(1, T1, true);
    printf("\n----------------------------------------\n\n");
    
    List* operands = initList();
    Stack* operation = initStack();
    Queue* operation1 = initQueue();
    insert(1, end(operands));
	insert(2, end(operands));
    insert(1, end(operands));
    insert(3, end(operands));
	enqueue(operation1, (uint64_t)'*');
	enqueue(operation1, (uint64_t)'+');
	enqueue(operation1, (uint64_t)'+');
	uint64_t result1 = preorderEval(operands, operation1);
	cout << "Result of preorder is " << result1 << endl;

    makenull(operands);
    makenull(operation);
	insert(1, end(operands));
	insert(2, end(operands));
    insert(1, end(operands));
    insert(3, end(operands));
	push(operation, (uint64_t)'+');
	push(operation, (uint64_t)'+');
	push(operation, (uint64_t)'*');
	uint64_t result2 = postorderEval(operands, operation);
	cout << "Result of postorder is " << result2 << endl;

	printf("Running test\n");
	assert(result1 == 6);
    assert(result2 == 6);
	printf("Both values are correct.\n");
	return 0;
}