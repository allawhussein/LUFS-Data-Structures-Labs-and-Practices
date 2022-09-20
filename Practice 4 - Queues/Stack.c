#include <stdio.h>
#include <stdlib.h>
#include  "Stack.h"

stack CreateStack()
{
	return NULL;
}

int Push(stack *p, element e)
{
	stack newEntry = (stack)malloc(sizeof(struct cell));
	if(newEntry == NULL)
		return 0;

	newEntry->data = e;
	newEntry->next = *p;
	*p = newEntry;

	return 1;
}

int Pop(stack *p)
{
	stack temp;

	if(isEmptyStack(*p))
		return 0;

	temp = *p;
	*p = (*p)->next;
	free(temp);
	return 1;
}

int Top(stack p, element *e)
{
	if(isEmptyStack(p))
		return 0;

	*e = p->data;
	return 1;
}

int isEmptyStack(stack p)
{
	return p == NULL;
}