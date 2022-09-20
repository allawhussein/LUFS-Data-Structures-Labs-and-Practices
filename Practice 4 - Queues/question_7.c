// The code contain an unknown bug, because the the error message was ambigious
#include "Queue.h"
#include <stdlib.h>

queue CreateQueue()
{
	queue q;
	q.front = NULL;
	return q;
}

int isEmptyQueue(queue q)
{
	return !q.front;
}

int Front(queue q, element *e)
{
	if (isEmptyQueue(q)) return 0;
	*e = (q.front)->data;
	return 1;
}

int DeQueue(queue *q)
{
	if (isEmptyQueue(*q)) return 0;
	struct cell *temp = q->front;
	q->front = (q->front->next);
	free(temp);
	return 1;
}

int insertNode(struct cell **headRef, element e, int priority)
{
    if (!*headRef) {
        *headRef = (struct cell *)malloc(sizeof(struct cell));
        if (!*headRef) return 0;
        (*headRef)->data = e;
        (*headRef)->priority = priority;
        (*headRef)->next = NULL;
        return 1;
    }
    if ((*headRef)->priority < priority)
        return insertNode(&((*headRef)->next), e, priority);
    struct cell *temp = (struct cell *)malloc(sizeof(struct cell));
    if (!temp) return 0;
    temp->data = e;
    temp->priority = priority;
    temp->next = (*headRef)->next;
    *headRef = temp;
    return 1;
}

int EnQueue(queue *q, element e, int priority)
{
	return insertNode(&(q->front), e, priority);
}

int deleteNode(struct cell **headRef, element data)
{
    if (!*headRef) return 0;
    if ((*headRef)->data == data){
        struct cell *temp = (*headRef);
        *headRef = (*headRef)->next;
        free(temp);
        return 1;
    }
    return deleteNode(&((*headRef)->next), data);
}

void update_priority(queue *q, element data, int priority) {
    deleteNode(&(q->front), data);
	EnQueue(q, data, priority);
}