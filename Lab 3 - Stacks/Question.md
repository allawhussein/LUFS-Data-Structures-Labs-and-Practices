# Problem 1

We are interested in evaluating mathematical expressions containing different operators and integer operands. Mathematical expressions are usually written in infix notation, and in order to the computer to evaluate its value, it needs to rewrite the expression in postfix notation. So your job is to read an infix expression, then convert it to a postfix expression, then evaluate the resulting postfix expression. 

The input expression is a string composed of digits (0 till 9) and operators (/, *, -, +, ^ (denotes exponentiation) and # (denotes unary minus)).

The output should be the value of the postfix expression.

Example 1:  
Infix Expression: ((6 - (2 + 3)) * (3 + 8 / 2)) ^ 2 + 3  
Postfix Expression: 6 2 3 + - 3 8 2 / + * 2 ^ 3 +  
Value: 52  

Example 2:
Infix Expression: 7-( #( #(2 + 3))) ^ 2  
Postfix Expression: 7 2 3 + # # 2 ^ -  
Value: -18  

stackable function is available in the code (no need to rewrite it).
```C
int stackable(char o1, char o2)
{
    switch (o1)
    {
        case '(': return 1;
        case '+': case '-': return (o2 == '(');
        case '#': return (o2 != '#');
        case '*':case '/': return (o2 == '(' || o2 == '+' || o2 == '-');
        case '^': return (o2 != '#' && o2 != '^');
        case ')': return (o2 == '(');
    }
    return 0;
}
```
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
Type element is of type float.  
Write the function `float infix_evaluation(char * )` that evaluates an infix expression and returns its value.