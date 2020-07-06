#include <bits/stdc++.h> 
#include <stdio.h>      /* #printf\, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std; 
#include "pointerstack.h"

Stack* initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));

    s->first = NULL;
    s->last = NULL;
    s->size = 0;
    return s;
}	

// Push a request to the Stack
void push(Stack *s, uint64_t _data)
{
    NodeS *node = (NodeS *)malloc(sizeof(NodeS));
    node->data = _data;
    node->prev = NULL;
    node->next = NULL;

    // Check if the Stack is empty.
    if (s->first == NULL && s->last == NULL)
    {
        s->first = node;
        s->last = node;
        s->size = 1;
    }
    else
    {
        // Now, the new node becomes the first node of the Stack.
        node->next = s->first;
        s->first->prev = node;

        s->first = node;
        s->size = s->size + 1;
    }
}

void pop(Stack *s)
{
    if (empty(s)){
        printf("Error stack is empty\n");
        exit(1);
    }
    //printf("--StartedPoping--");
    NodeS *node = s->first;
    //printf("got top node--");
    // Check if the Stack is empty.
    if (node == NULL)
    {
        //printf("Error, stack is empty");
        exit(1);
    }
    else
    {
        if (node->next == NULL){
            s->first = NULL;
            s->last = NULL;
            s->size = 0;
        } else {
            s->first = node->next;
            s->first->prev = NULL;

            s->size = s->size - 1;
        }
        free(node);

    }
}

NodeS* top(Stack *s)
{
    if (empty(s)){
        printf("Error stack is empty\n");
        exit(1);
    }
    NodeS *node = s->first;
    return node;
}

void makenull(Stack *s)
{
    s->first = NULL;
    s->last = NULL;
    s->size = 0;
}

bool empty(Stack *s)
{
    if (s->first == NULL && s->last == NULL){
        return true;
    }
    return false;
}