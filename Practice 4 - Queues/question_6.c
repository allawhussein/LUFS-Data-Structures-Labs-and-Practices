int isEmptyStack(stack p)
{
	return isEmptyQueue(p.L);
}

int isFullStack(stack p)
{
	return isFullQueue(p.L);
}

int Pop(stack *p)
{
    if (isEmptyStack(*p)) return 0;
	element e;
	int counter = 0;
	while (Front(p->L, &e)){
	    DeQueue(&(p->L));
	    EnQueue(&(p->R), e);
	    counter++;
	}
	while (--counter){
	    Front(p->R, &e);
	    DeQueue(&(p->R));
	    EnQueue(&(p->L), e);
	}
	DeQueue(&(p->R));
	return 1;
}

int Top(stack p, element *e)
{
    if (isEmptyStack(p)) return 0;
	element e1;
	while (Front(p.L, &e1)){
	    DeQueue(&(p.L));
	    EnQueue(&(p.R), e1);
	}
	*e = e1;
	while (Front(p.R, &e1)){
	    DeQueue(&(p.R));
	    EnQueue(&(p.L), e1);
	}
	return 1;
}

