# Problem 1

**This is an easy lab, that I'll skip**
We want to manage a set of processes in a computer système. Each process has a unique id and une priorité. It is obvious that the processes having highest priority will be executed premier. The processes with equal priority will be executed in FIFO. The maximum priorité in the system is a constant N: The highest priority is therefore N-1, the lowest is 0. Assume that the execution of a process consists of printing his id.

Such system will be represented by the following figure :

![figure](.\image.png)

Our system is thus an array of N queues, each corresponding to a priority.

```C
typedef int element;
typedef element process;
typedef queue systemQ[N];
```
Write the following functions allowing to:

1. Create the previously described structure  
2. Display the content of the structure  
3. Add a process  
4. Delete the process with the highest priority   
5. Calculate the number of processes for a given priority   
6. Modify the priority of processes of priority i to priority j.  
Input Format  
1 integer n followed by n lines. Each line consists of one of the following cases:
<br />
1.  (it calls the function display)  
2. e p, where p is priority and e an id (it calls the functions add)  
3. (it calls the function deletePri)  
4. e, where e is a priority (it calls the function nb_elements)  
5. p1 p2, where p1 and p2 are priorities (it calls the function modify)  
Output Format  
For each function, display:

`create_system`: nothing to display  
`display`: display all the ids from the highest priority to the lowest separated by a space  
`add`: nothing to display  
`deletePri`: nothing to display  
`nb_elements`: nothing to display  
`modify`: nothing to display  
You may note the following:

Queue ADT is available:  
Type: queue  
Operations: 
```C
queue CreateQueue()
int isEmptyQueue(queue)
int isFullQueue(queue)
int EnQueue(queue*, element )
int DeQueue(queue*)
int Front(queue, element *)
```

Prototypes:
```C
void create_system(systemQ t)
void display(systemQ t)
int add(systemQ t, process e, element priority)
int deletePri(systemQ t)
int nb_elements(systemQ t, element e)
void modify(int priority1, int priority2, systemQ t)
```