typedef struct 
{
	stack s1, s2;
} queue;

queue CreateQueue()
{
    queue q;
    q.s1 = CreateStack();
    q.s2 = CreateStack();
    return q;
}

int isEmptyQueue(queue q)
{
    return isEmptyStack(q.s1);
}

int isFullQueue(queue q)
{
    return isFullStack(q.s1);
}

int EnQueue(queue *q, element e)
{
    return Push(&(q->s1), e);
}

int DeQueue(queue *q)
{
    if (isEmptyQueue(*q)) return 0;
    element e;
    while (Top(q->s1, &e)){
        Pop(&(q->s1));
        Push(&(q->s2), e);
    }
    Pop(&(q->s2));
    while (Top((*q).s2, &e)){
        Pop(&(q->s2));
        Push(&(q->s1), e);
    }
    return 1;
}

int Front(queue q, element *e1)
{
    if (isEmptyQueue(q)) return 0;
    element e;
    while (Top(q.s1, &e)){
        Pop(&(q.s1));
        Push(&(q.s2), e);
    }
    Top(q.s2, e1);
    while (Top(q.s2, &e)){
        Pop(&(q.s2));
        Push(&(q.s1), e);
    }
    return 1;
}
