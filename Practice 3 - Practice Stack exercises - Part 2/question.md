# Problem 1

Write a C function that interchanges the top two numbers on the stack. 

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
Type element is of type integer.  
Prototype: `void interchange(stack *s)`

# Problem 2

Write a C function that adds all the numbers on the stack together.

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
Type element is of type integer.  
Prototype: `void interchange(stack *s)`

# Problem 3

Write a C function that computes the average of all numbers on the stack.

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
Type element is of type integer.  
Prototype: `void interchange(stack *s)`

# Problem 4

Write a C function that reverses the order of elements on stack using 2 additional stacks.

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
Type element is of type integer.  
Prototype: `void interchange(stack *s)`

# Problem 5

Suppose we add a new operation to the stack ADT called 'findMinimum' that returns a reference to the smallest element in the stack. Show that it is possible to provide an exécution for 'findMinimum' that has a worst case running time of O(1).

Hint: Keep two stack. One will be general stack, which will just keep the elements. The second will keep the min value.

Push: Push an element to the top of stack1. Compare the new value with the value at the top of the stack2. If the new value is smaller, then push the new value into stack2. Alternatively, push the value at the top of the stack2 to itself once more.
Pop: Pop an element from top of stack1 and return. Pop an element from top of stack2 too.
Min: Read from the top of the stack2 this value will be the min.

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
Type element is of type integer.

# Problem 6

