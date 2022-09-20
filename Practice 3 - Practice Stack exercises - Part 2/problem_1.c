#include "Stack.h"

void interchange(stack *s)
{
    if (!s) return;
    element e1, e2;
    if (!Top(*s, &e1) || !Pop(s)) return;
    if (!Top(*s, &e2) || !Pop(s)){
        Push(s, e1);
        return;
    }
    Push(s, e1);
    Push(s, e2);
}