#include "Stack.h"

typedef struct  {
	stack stack1;
	stack stack2;
} theStack;


theStack CreatetheStack()
{
	theStack s;
	s.stack1 = CreateStack();
	s.stack2 = CreateStack();
	return s;
}

int PushtheStack(theStack *s, element e)
{
	Push(&(s->stack1), e);
    element currMin;
	if (!Top(s->stack2, &currMin)){
	    Push(&(s->stack2), e);
	    return 0;
	}
    if (currMin > e) Push(&(s->stack2), e);
    else Push(&(s->stack2), currMin);
    return 1;
}

int PoptheStack(theStack *p)
{
	if (!Pop(&(p->stack1))) return 0;
	if (!Pop(&(p->stack2))) return 0;
    return 1;
}

int ToptheStack(theStack p, element *e)
{
	return Top(p.stack1, e);
}

int getMin(theStack p, element *e)
{
	return Top(p.stack2, e);
}