#include "Stack.h"
#define N 10

// DEFINE YOUR element BELOW
typedef struct element{
    int a, b;
}element;

/* DO NOT MODIFY THE FOLLOWING LINES */
typedef struct  {
	element data[N]; 
	int top;
} stack;
int isEmptyStack(stack p)
{
	return (p.top == -1);
}

int isFullStack(stack p)
{
	return (p.top == N-1);
}
stack CreateStack()
{
	stack p;
	p.top = -1;
	return p;
}
int Push(stack *p, element e)
{
	if (isFullStack(*p)) return 0;
	p->data[++p->top] = e;
	return 1;
}
int Pop(stack *p)
{
	if (isEmptyStack(*p)) return 0;
	p->top--;
	return 1;
}
int Top(stack p, element *e)
{
	if (isEmptyStack(p)) return 0;
	*e = p.data[p.top];
	return 1;
}
/* DO NOT MODIFY THE ABOVE LINES */

// COMPLETE THE FOLLOWING FUNCTION
int egyptian_it(int a, int b) 
{
    stack s = CreateStack();
    while (a > 0){
        Push(&s, (element){a, b});
        a /= 2;
        b *= 2;
    }
    element temp;
    int res = 0;
    while (Top(s, &temp)){
        Pop(&s);
        if (temp.a % 2) res += temp.b;
    }
    return res;
}