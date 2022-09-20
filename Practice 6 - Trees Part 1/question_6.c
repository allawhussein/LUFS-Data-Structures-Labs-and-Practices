void inorderTraversal(Btree B, stack *s){
    if (B == NULL) return;
    inorderTraversal(B->left, s);
    Push(s, B);
    inorderTraversal(B->right, s);
}

int same(Btree A, Btree B)
{
    stack nodesA = CreateStack();
    stack nodesB = CreateStack();
    inorderTraversal(A, &nodesA);
    inorderTraversal(B, &nodesB);
    
    while(Top(nodesA, &A) && Top(nodesB, &B)){
        if (A->data != B->data) return 0;
        Pop(&nodesA);
        Pop(&nodesB);
    }
    if (!isEmptyStack(nodesA) && !isEmptyStack(nodesB)) return 0;
    return 1;
}