# Problem 1
Write a recursive function that given a stack as parameter, switches the sign of its elements.

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
Write the function `void switchSign(stack *)` that switches the sign of the element of the stack..  
Attention: No printf inside the switchSign function !

# Problem 2

We want to sort an array of N integers in ascending order using a stack. To do this, you should use two stacks: a current stack S1 and an auxiliary stack S2 that will be used temporary for eventual pops. 

You may note the following:  
Stack ADT is available:  
Type: stack   
Operations:   
stack CreateStack()
`int isEmptyStack(stack)`  
`int isFullStack(stack)`  
`int Push(stack *, element )`  
`int Pop(stack *)`  
`int Top(stack, element *)`  
Type element is of type integer.  
Write the function `void sort(int * , int )` that sorts the array according to the above method.  
Attention: No printf inside the sort function !

# Problem 3

Dating back to Ancient Egypt, the Egyptian multiplication méthode does not require memorization of all multiplication tables. It relies only on the ability to add and to divide by 2.

Your DS teacher was so gentle with you, he wrote a recursive function implementing the mentioned méthode.
```C
int egyptian_rec(int a, int b) 
{ 
    int res;   
    if (a == 1) 
        return b; 
    res = egyptian_rec(half(a), b + b);
    if (odd(a)) 
        res += b;
    return res; 
}
```
You are asked to derecursivate this function (not other versions found on the internet) using a stack. To do that, start by drawing its memory state, what happens during the winding and unwinding, then translate it to a code using a stack.

Prototype: `int egyptian_it(int a, int b)`

Input format:  
The first line contains the number of tests, for each test: 2 numbers a and b to be multiplied a is toujours positive.  

Output format:  
For each test case, output the value of the Egyptian Multiplication between a and b