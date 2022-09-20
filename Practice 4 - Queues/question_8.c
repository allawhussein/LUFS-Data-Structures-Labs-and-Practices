// This code is bugged logically, skipped as the task is easy once I understand queue static implementation
#define N 10
typedef int element;
typedef struct 
{
	element  data[N];
    	int  front;
    	int  rear;
} Deque;

Deque CreateDeque()
{
	Deque dq;
	dq.front = 1;
	dq.rear = 0;
	return dq;
}

int isFullDeque(Deque q)
{
	return q.front == q.rear + 1;
}

int isEmptyDeque(Deque q)
{
	return q.front == q.rear + 2;
}

int insertFront(Deque *q, element e)
{
    if (isFullDeque(*q)) return 0;
    q->rear = (q->rear + 1) % N;
    q->data[q->rear] = e;
    return 1;
}

int insertRear(Deque *q, element e)
{
   if (isFullDeque(*q)) return 0;
   q->front = (q->front - 1) % N;
   q->data[q->front] = e;
   return 1;
}

int deleteFront(Deque *q)
{
	if (isEmptyDeque(*q)) return 0;
	q->front = (q->front + 1) % N;
	return 1;
}

int deleteRear(Deque *q)
{
	if (isEmptyDeque(*q)) return 0;
	q->rear = (q->rear - 1) % N;
	return 1;
}

int Front(Deque q, element *e)
{
	if (isEmptyDeque(q)) return 0;
	*e = q.data[q.front];
	return 1;
}

int Rear(Deque q, element *e)
{
	if (isEmptyDeque(q)) return 0;
	*e = q.data[q.rear];
	return 1;
}