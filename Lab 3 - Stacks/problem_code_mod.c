#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef float element;
typedef struct cell
{
	element data;
	struct cell* next;
} *stack;

stack CreateStack()
{
	return NULL;
}

int isEmptyStack(stack p)
{
	return p == NULL;
}

int Push(stack *p, element e)
{
	stack newEntry = (stack)malloc(sizeof(struct cell));
	if(newEntry == NULL)
		return 0;

	newEntry->data = e;
	newEntry->next = *p;
	*p = newEntry;

	return 1;
}

int Pop(stack *p)
{
	stack temp;

	if(isEmptyStack(*p))
		return 0;

	temp = *p;
	*p = (*p)->next;
	free(temp);
	return 1;
}

int Top(stack p, element *e)
{
	if(p == NULL)
		return 0;

	*e = p->data;
	return 1;
}

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

//I tried this code on my PC before opening the LAB, but with arrays
int isOperator(char op)
{
    if (op == '#' || op == '(' || op == ')' || op == '+' || op == '-' || op == '*' || op == '/' || op == '^') return 1;
    return 0;
}

float infix_evaluation(char *inFix)
{
    ////////////////////////////step 1: infix to postfix////////////////////////////
    //Parsing the string
    char *postFix = (char *)malloc(sizeof(char) * 200);
    int postFixCounter = 0;
    stack stackable_ops;
    for (int i = 0; *(inFix + i) != '\0'; i++){
        if (!isOperator(*(inFix + i)))
            *(postFix + postFixCounter++) = *(inFix + i);
        else{
            if (isEmptyStack(stackable_ops)) Push(&stackable_ops, (float)(*(inFix + i)));
            else{
                char topChar;
                float topFloat;
                Top(stackable_ops, &topFloat);
                topChar = (char)topFloat;
                if (stackable(*(inFix + i), topChar)){
                    if (*(inFix + i) == ')') Pop(&stackable_ops);
                    else Push(&stackable_ops, (float)(*(inFix + i)));
                }
                else{
                    *(postFix + postFixCounter++) = topChar;
                    Pop(&stackable_ops);
                    i--;
                }
            }
        }
    }
    while (!isEmptyStack(stackable_ops)){
        element topFloat;
        Top(stackable_ops, &topFloat);
        Pop(&stackable_ops);
        *(postFix + postFixCounter++) = (char)topFloat;
    }
    *(postFix + postFixCounter) = '\0';

    //step 2: postfix to evaluation
    stackable_ops = CreateStack();
    element answer;
    for (int i =0; *(postFix + i) != '\0'; i++){
        char currentChar = *(postFix + i);
        if (!isOperator(currentChar)) 
            Push(&stackable_ops, (float)(currentChar - '0'));
        else if (currentChar == '#'){
            Top(stackable_ops, &answer);
            Pop(&stackable_ops);
            Push(&stackable_ops, -answer);
        }
        else{
            float a, b;
            Top(stackable_ops, &b);
            Pop(&stackable_ops);
            Top(stackable_ops, &a);
            Pop(&stackable_ops);

            if (currentChar == '+') answer = a + b;
            else if (currentChar == '-') answer = a - b;
            else if (currentChar == '*') answer = a * b;
            else if (currentChar == '/') answer = a / b;
            else if (currentChar == '^') answer = pow(a, b);
            Push(&stackable_ops, answer);
        }
    }
    Top(stackable_ops, &answer);
    return answer;
}

int main()
{
    //"8"
    //((6-(2+3))*(3+8/2))^2+3
    //(((((1)))))
    //2^2^2^#2
    //7-(#(#(2+3)))^2
    //((4-1)/(#1-4)+5)*(2-1)-3
    printf("%f", infix_evaluation("((6-(2+3))*(3+8/2))^2+3"));
    return 0;
}
