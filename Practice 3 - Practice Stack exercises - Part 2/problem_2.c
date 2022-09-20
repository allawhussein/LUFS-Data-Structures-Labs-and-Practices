#include "Stack.h"

int add(stack s)
{
    if (isEmptyStack(s)) return 0;
    element number = 0;
    Top(s, &number);
    Pop(&s);
    return number + add(s);
}