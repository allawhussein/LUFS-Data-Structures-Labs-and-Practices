int belongr(Btree B, element e)
{
    if (!B) return 0;
    if (B->data == e) return 1;
    return belongr(B->left, e) || belongr(B->right, e);
}

int belong(Btree A, Btree B)
{
	// recursive function: checking whether left and right subtrees of A belongs to B, check A root too 
	if (!B) return 0;
	if (!A) return 1;
	if (!belongr(B, A->data)) return 0;
	return belong(A->left, B) && belong(A->right, B);
}

int same(Btree A, Btree B)
{
	return (belong(A, B) && belong(B, A));
}