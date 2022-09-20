#include "Stack.h"

void switchSign(stack *s)
{
    if (isEmptyStack(*s)) return;
    element top;
    Top(*s, &top);
    Pop(s);
    switchSign(s);
    Push(s, -top);
}