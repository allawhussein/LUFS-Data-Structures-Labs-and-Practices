#include "Queue.h"
#include "Stack.h"

void reverts(queue *q)
{
    if (!q) return;
	element e;
	stack s = CreateStack();
	while (Front(*q, &e)){
	    Push(&s, e);
	    DeQueue(q);
	}
	while (Top(s, &e)){
	    EnQueue(q, e);
	    Pop(&s);
	}
}