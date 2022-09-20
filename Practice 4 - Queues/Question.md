# Problem 1

Consider a queue of objects each having an identifier (integer) and a color among the three values (blue, white, red). We want to change the queue so that the blue elements are in the beginning of queue, followed by white elements, and finally red ones, without changing the order in which elements of the same color are enqueued.

Write a function that converts such a queue so it can verify the above property.  
Use exclusively the operations of the abstract data type queue.

You may note the following:  
Queue ADT is available:  
Type: queue  
Operations:   
`queue CreateQueue()`  
`int isEmptyQueue(queue)`  
`int isFullQueue(queue)`  
`int EnQueue(queue*, element )`  
`int DeQueue(queue*)`  
`int Front(queue, element *)`  
Type element is defined as follows:
```C
typedef struct 
{
	int id; 
	char *color;
} element;
```
Prototype: `void sort(queue *)`

# Problem 2

Write a C function that reverts a queue.

You may note the following:  
Queue ADT is available:  
Type: queue  
Operations:   
`queue CreateQueue()`  
`int isEmptyQueue(queue)`  
`int isFullQueue(queue)`  
`int EnQueue(queue*, element )`  
`int DeQueue(queue*)`  
`int Front(queue, element *)`  
Stack ADT is available:  
Type: stack   
Operations:   
`stack CreateStack()`  
`int isEmptyStack(stack)`  
`int isFullStack(stack)`  
`int Push(stack *, element )`  
`int Pop(stack *)`  
`int Top(stack, element *)`  

Type element is of type int.
Prototype: `void reverts(queue *)`

# Problem 3

Write a C function that reverses a stack using a queue.

You may note the following:  
Queue ADT is available:  
Type: queue  
Operations:   
`queue CreateQueue()`  
`int isEmptyQueue(queue)`  
`int isFullQueue(queue)`  
`int EnQueue(queue*, element )`  
`int DeQueue(queue*)`  
`int Front(queue, element *)`   

Stack ADT is available:  
Type: stack   
Operations:   
`stack CreateStack()`  
`int isEmptyStack(stack)`  
`int isFullStack(stack)`  
`int Push(stack *, element )`  
`int Pop(stack *)`  
`int Top(stack, element *)`  

Type element is of type int.  
Prototype: `void reverse(stack *)`

# Problem 4

Consider a queue of tasks each having an identifier (integer) and a priority between 0 and N-1 (where N is a constant)

We want to transform the queue so that the tasks of priority 0 are at the front, followed by tasks of priority 1 and so on. Tasks of same priority must be stored in reverse order of their arrival
Write a function that converts such a queue so that it can verify the above priority

The following queue:

| ID | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Pr | 5 | 3 | 1 | 3 | 3 | 5 | 2 | 1 |

Becomes:

ID | 8 | 3 | 7 | 5 | 4 | 2 | 6 | 1
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
Pr | 1 | 1 | 2 | 3 | 3 | 3 | 5 | 5

=> priority in increasing order, for same priorites, use ids by decrease order

# Problem 5

Implement a queue using two stacks.

You may note the following:   
Stack ADT is available:  
Type: stack   
Operations:   
`stack CreateStack()`  
`int isEmptyStack(stack)`  
`int isFullStack(stack)`  
`int Push(stack *, element )`  
`int Pop(stack *)`  
`int Top(stack, element *)`  
Type element is of type int.

# Problem 6

Implement a stack using two queues.

You may note the following:  
Queue ADT is available:  
Type: queue  
Operations:   
`queue CreateQueue()`  
`int isEmptyQueue(queue)`  
`int isFullQueue(queue)`  
`int EnQueue(queue*, element )`  
`int DeQueue(queue*)`  
`int Front(queue, element *)`  
Type element is of type int.

The following code is embedded in the solution.
```C
stack CreateStack()
{
	stack s;
	s.L = CreateQueue();
	s.R = CreateQueue();
	return s;
}
int Push(stack *s, element e)
{
	if (isFullStack(*s)) return 0;
	EnQueue(&(s->L),e) ;
	return 1;
}
```

# Problem 7

A priority queue is an abstract data type which is like a regular queue, but where additionally each element has a "priority" associated with it. In a priority queue, an element with high priority is served before an element with low priority. In some implementations, if two elements have the same priority, they are served according to the order in which they were enqueued, while in other implementations, ordering of elements with the same priority is undefined.

A priority queue must at least support the following operations:

`CreateQueue` to create a priority queue  
`EnQueue` according to a priority  
`DeQueue` the front element (highest priority)  
Check the `Front` element  
`isEmptyQueue` to check if the priority queue is empty  
`update_priority` for a given element  
Implement a priority queue using a linked list.

Type element is of type int.

Input/Output: element e, then priority alternating between EnQueue and update_priority. After each operation, the PQ is displayed.

The following code is embedded in the solution.
```C
#define N 20
typedef int element;
struct cell { 
	element data; 
	int priority;
	struct cell *next; 
};
typedef  struct { 
	struct cell *front; 
} queue;
```

# Problem 8

A deque is a data structure that allows both deletion as well as insertion of elements to be done at both ends of a queue. 

Implement a deque using a circular array.

Type element is of type int.

Input/Output: integer randomizer. then elements, alternating between insertFront, insertRear, deleteFront and deleteRear. After each operation, the deque is displayed.

The following code is embedded in the solution.

```C
#define N 10
typedef int element;
typedef struct 
{
	element  data[N];
    	int  front;
    	int  rear;
} Deque;
```

# Problem 9

Given array A[] with sliding window of size w which is moving from the very left of the array to the very right. Assume that we can only see the w numbers in the window. Each time the sliding window moves rightwards by one position. For example: the array is [1 3 -1 -3 5 3 6 7], and w is 3.


|Window position | Max |
|---|---|
| **[1 3 -1]** -3 5 3 6 7 | 3 |
| 1 **[3 -1 -3]** 5 3 6 7 | 3 |
| 1 3 **[-1 -3 5]** 3 6 7 | 5 |
| 1 3 -1 **[-3 5 3]** 6 7 | 5 |
| 1 3 -1 -3 **[5 3 6]** 7 | 6 |
| 1 3 -1 -3 5 **[3 6 7]** | 7 |
 
Input: A window width w then a long array A[].
Output: An array B[], B[i] is the maximum value of from A[i] to A[i+w-1].
Requirement: Find a good optimal way to get B[i].

You may note the following:

Deque ADT is available:  
Type: Deque  
Operations:   
`Deque CreateDeque()`  
`int isFullDeque(Deque )`   
`int isEmptyDeque(Deque )`   
`int insertFront(Deque *, element)`   
`int insertRear(Deque *, element)`   
`int deleteFront(Deque *)`   
`int deleteRear(Deque *)`   
`int Front(Deque, element *)`   
`int Rear(Deque, element *)`   
Type element is of type int.