int belong(heap H, element e, int *count)  // This function should be recursive
{
    if (!H) return 0;
    (*count)++;
    if (H->data == e) return 1;
    if (H->data > e) return 0;
    return belong(H->left, e, count) || belong(H->right, e, count);
}

int maxheap(heap H, element *e)  // This function should be recursive
{
	if (!H) return 0;
	if (H->data > *e) *e = H->data;
	maxheap(H->left, e);
	maxheap(H->right, e);
	return 1;
}


int domain(heap A, heap B) 
{
    if (!A || !B) return -1;
    int maxA = A->data, maxB = B->data, minA = A->data, minB = B->data;
    maxheap(A, &maxA);
    maxheap(B, &maxB);
    return maxA <= maxB && minA >= minB;
    
}