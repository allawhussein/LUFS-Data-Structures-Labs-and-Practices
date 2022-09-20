void sort(int *arr, int size)
{
    if (size <= 1) return;
    stack s = CreateStack();
    stack aux = CreateStack();
    Push(&s, *arr);
    element temp;
    for (int i = 1; i < size; i++){
        while(Top(s, &temp)){
            if (temp < *(arr + i))
            {
                Push(&s, *(arr + i));
                break;
            }
            else {
                Push(&aux, temp);
                Pop(&s);
            }
        }
        if (isEmptyStack(s)) Push(&s, *(arr + i));
        while (Top(aux, &temp)){
            Pop(&aux);
            Push(&s, temp);
        }
    }
    
    for (int i = size - 1; i >= 0; i--){
        Top(s, &temp);
        Pop(&s);
        *(arr + i) = temp;
    }
}