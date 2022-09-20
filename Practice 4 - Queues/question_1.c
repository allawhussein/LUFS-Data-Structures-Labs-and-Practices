#include "Queue.h"

typedef struct 
{
	int id; 
	char *color;
} element;

void sort(queue *q)
{
	queue redQueue = CreateQueue(), blueQueue = CreateQueue(), whiteQueue = CreateQueue();
	element topEle;
	while (Front(*q, &topEle)){
	    if (*(topEle.color) == 'r'){
	        EnQueue(&redQueue, topEle);
	        DeQueue(q);
	    }
	    else if (*(topEle.color) == 'b'){
	        EnQueue(&blueQueue, topEle);
	        DeQueue(q);
	    }
	    else {
	        EnQueue(&whiteQueue, topEle);
	        DeQueue(q);
	    }
	}
	while (Front(blueQueue, &topEle)){
	    DeQueue(&blueQueue);
	    EnQueue(q, topEle);
	}
	while (Front(whiteQueue, &topEle)){
	    DeQueue(&whiteQueue);
	    EnQueue(q, topEle);
	}
	while (Front(redQueue, &topEle)){
	    DeQueue(&redQueue);
	    EnQueue(q, topEle);
	}
}