#include <stdio.h>
#include "stack.h"
// It is unknown why this simple program is exceeding time limit
/*int insert(stack *s, element e, int k)
{
    if (isEmptyStack(*s) || !k) return -1;
    if (k == 1){
        Push(s, e);
        return 1;
    }
    int topElement = -1;
    Top(*s, &topElement);
    Pop(s);
    int result = insert(s, e, k - 1);
    Push(s, e);
    return result;
}*/

// The solution provided by the trainer doesn't take into consideration bad cases, like out of bound position
int insert(stack *s, element e, int k)
{
    int counter = 1;
    stack aux = CreateStack();
    element temp;

    if (isFullStack(*s)) return 0;

    while (Top(*s, &temp) && counter++ < k){
        Pop(s);
        Push(&aux, temp);
    }
    Push(s, e);
    while (Top(aux, &temp)){
        Pop(&aux);
        Push(s, temp);
    }
    return 1;
}

int main()
{
    stack s = CreateStack();
    for (int i = 1; i < 5; i++)
        Push(&s, i);
    insert(&s, 2, 4);
    int temp;
    while (Top(s, &temp)){
        printf("%d ", temp);
        Pop(&s);
    }
    return 0;
}