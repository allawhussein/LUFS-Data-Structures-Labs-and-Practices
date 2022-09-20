#include "Stack.h"

typedef struct  {
	stack s; 
	int nb_elements;
} Array;

Array CreateArray(int size)
{
	Array arr;
	arr.s = CreateStack();
	for (int i = 0; i < size; i++) Push(&(arr.s), 0);
	arr.nb_elements = size;
    return arr;
}

int Assign(Array *A, element n, int index)
{
    if (index < 0 || index > A->nb_elements) return 0;
    element e;
	stack aux = CreateStack();
	int i;
	for (i = (A->nb_elements - 1); i > index; i++){
	    Top(A->s, &e);
        Pop(&(A->s));
	    Push(&aux, e);
	}
    Pop(&(A->s));
    Push(&(A->s), n);
    while (Top(aux, e)){
        Pop(&aux);
        Push(&(A->s), e);
    }
    return 1;
}

void printR(Array A)
{
    if (isEmptyStack(A.s)) return;
    element e;
    Top(A.s, &e);
    Pop(&(A.s));
    printR(A);
    printf("%d ", e);
    Push(&(A.s), e);
}
void printArray(Array A, int size)
{
    for (int i = 1; i <= (A.nb_elements - size); i++)
        Pop(&(A.s));
    printR(A);
}