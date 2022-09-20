#include "stack.h"

int nth(stack s, int n)
{
    if (isEmptyStack(s)) return -1;
    if (n < 0) return -1;
    
    int element = -1;
    Top(s, &element);
    if (n == 1)
        return element;
    Pop(&s);
    int result = nth(s, n - 1);
    Push(&s, element);
    return result;
}