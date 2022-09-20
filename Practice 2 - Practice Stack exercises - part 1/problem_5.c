#include "stack.h"

#define N 10
typedef int  element;
typedef struct  {
	element data[N]; 
	int top1,top2;
} stack;

stack CreateStack()
{
	stack created;
	created.top1 = -1;
	created.top2 = N;
	// I'll consider position indicated by top1 or top2 to be vacant
	// I'll detect stacks collision by comparing top1 and top2
	// If they're the same value then both are pointing to the same vacant position, and none is allowed to expand more
	return created;
}

int isEmptyStack(stack p, int stack_nb)
{
		if (stack_nb == 1) return p.top1 == -1;
		return p.top2 == N;
}

int isFullStack(stack p)
{
		return p.top1 == p.top2 - 1;
}

int Push(stack *p, element e, int stack_nb)
{
	if (isFullStack(*p)) return 0;
	if (stack_nb == 1){
	    p->data[++(p->top1)] = e;
	    return 1;
	}
	p->data[--(p->top2)] = e;
	return 1;
}

int Pop(stack *p, int n)
{
	if (isEmptyStack(*p, n)) return 0;
	if (n == 1){
	    (p->top1)--;
	    return 1;
	}
	(p->top2)++;
	return 1;
}

int Top(stack p, element *e, int stack_nb)
{
		if (isEmptyStack(p, stack_nb)) return 0;
		if (stack_nb == 1){
		    *e = p.data[p.top1];
		    return 1;
		}
		*e = p.data[p.top2];
		return 1;
}