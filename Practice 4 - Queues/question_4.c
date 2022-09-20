#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "Queue.h"

#define N 50

void sort(queue *q){
    //we need as much stacks as there is tasks. I might declare a new stack for every newly encountered priority.
    //Another approach is to use a function from the previous practice to insert the task into its appropriate place. I discourage this solution.
    element e;
    stack *s;
    
    s = (stack *)malloc(sizeof(stack) * N);
    for (int i = 0; i < N; i++)
        *(s + i) = CreateStack();
    
    while (Front(*q, e)){
        DeQueue(q);
        Push(s + e.priority, e);
    }

    for (int i = 0; i < N; i++){
        while (Top(*(s + i), &e)){
            Pop(s + i);
            EnQueue(q, e);
        }
    }
}