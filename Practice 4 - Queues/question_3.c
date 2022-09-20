//Writes a C function that reverses a stack using a queue

#include "Queue.h"
#include "Stack.h"

void reverse(stack *s){
    queue q = CreateQueue();
    element e;

    while (Top(*s, &e)){
        EnQueue(&q, e);
        Pop(s);
    }

    while (Front(q, &e)){
        DeQueue(&q);
        Push(s, e);
    }
}
