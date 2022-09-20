#include "Stack.h"

int add(stack s, double *size)
{
    if (isEmptyStack(s)) return 0;
    element number = 0;
    Top(s, &number);
    Pop(&s);
    (*size)++;
    return number + add(s, size);
}

double average(stack s)
{
    double size = 0;
    int sum = add(s, &size);
    return (double)sum / size;
}