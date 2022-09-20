#include "Stack.h"

void reverse(stack *s)
{
    stack aux1 = CreateStack(), aux2 = CreateStack();
    element e;
    while (Top(*s, &e)){
        Pop(s);
        Push(&aux1, e);
    }
    while (Top(aux1, &e)){
        Pop(&aux1);
        Push(&aux2, e);
    }
    while (Top(aux2, &e)){
        Pop(&aux2);
        Push(s, e);
    }
}