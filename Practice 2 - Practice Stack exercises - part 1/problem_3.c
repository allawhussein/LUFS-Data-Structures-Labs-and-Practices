#include "stack.h"

int delete_pos(stack *s, int position)
{
    int counter = 1;
    stack aux = CreateStack();
    element e;

    while (Top(*s, &e) && counter++ < position){
        Pop(s);
        Push(&aux, e);
    }
    if (counter == position && Pop(s)){
        while (Top(aux, &e)){
            Pop(&aux);
            Push(s, e);
        }
        return 1;
    }
    while (Top(aux, &e)){
        Pop(&aux);
        Push(s, e);
    }
    return 0;
}