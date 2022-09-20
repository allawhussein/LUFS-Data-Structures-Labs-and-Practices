# Problem 1
Complete the following tail-recursive `void moveHeadToLast(node **headRef)` which given a linked list, it should move the head node to the last position in the linked list.
You're not allowed to use malloc, arrays, helper functions or loops. The nodes should be swapped not the data.

The node structure is defined as below
```C
typedef struct node{
    int data;
    struct node *next;
} node;
```

# Problem 2

Complete the following function `node *addNumbers(node *head1, node *head2)` which given two linked lists of equal length, each representing a number, it should return a new linked list with the sum of both. Each node should store one base-10 digit.

The node structure is defined as follows:
```C
typedef struct node{
    int data;
    struct node *next;
} node;
```

# Problem 3

Complete the recursive function `int toDecimal(node *head)` which given a linked list that represents a number written in base 2, should convert it into a base 10 decimal.

The use of arrays, malloc and power functions is forbidden. 

# Problem 4

A string of opening and closing brackets, consisting of the following (,) is said to be balanced, if each same pair of opening bracket and closing brackets are put in their correct position. Examples:

(), (()), ()(), (()()) are all balanced.
)(, ()(, (()() are all not balanced.

Given a string of characters str consisting of only (,), you are required to complete the following function `int isBalanced(char str[])`, which returns 1 if the string is balanced, 0 otherwise.

# Problem 5

x