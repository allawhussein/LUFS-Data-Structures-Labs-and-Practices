#include "Stack.h"

typedef struct  {
	stack s;
	element minEle;
} theStack;

theStack CreatetheStack()
{
	theStack s;
	s.s = CreateStack();
	s.minEle = 0;
	return s;
}

int PushtheStack(theStack *s, element e)
{
	if (!s) return 0;
	if (isEmptyStack(s->s)){
	    Push(&(s->s), e);
	    s->minEle = e;
	    return 1;
	}
	if (s->minEle <= e){
	    Push(&(s->s), e);
	    return 1;
	}
	Push(&(s->s), 2 * e - s->minEle);
	s->minEle = e;
	return 1;
}

int PoptheStack(theStack *p)
{
    if (isEmptyStack(p->s)) return 0;
    int topEle;
    Top(p->s, &topEle);
    if (topEle < p->minEle) p->minEle = 2 * p->minEle - topEle;
    Pop(&(p->s));
    return 1;
}

int ToptheStack(theStack p, element *e)
{
    if (!Top(p.s, e)) return 0;
    if (*e >= p.minEle) return 1;
    *e = p.minEle;
    return 1;
}

int getMin(theStack p, element *e)
{
	if (isEmptyStack(p.s)) return 0;
	*e = p.minEle;
	return 1;
}