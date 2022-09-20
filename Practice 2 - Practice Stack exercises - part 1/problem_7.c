#include "Stack.h"

void addAtBottom(stack *s, element e)
{
    element temp;
    if (isEmptyStack(*s)){
        Push(s, e);
        return;
    }
    Top(*s, &temp);
    addAtBottom(s, e);
    Push(s, temp);
}

void reverseStack(stack *s)
{
    if (isEmptyStack(*s)) return;
    element e;
    Top(*s, &e);
    reverseStack(s);
    addAtBottom(s, e);
}