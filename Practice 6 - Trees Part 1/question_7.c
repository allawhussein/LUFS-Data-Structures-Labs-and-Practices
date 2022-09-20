void printLevelOrderZigZag(Btree B)
{
    if (!B) return;
    stack s1 = CreateStack(), s2 = CreateStack();
    Push(&s1, B);
    while (!isEmptyStack(s1) || !isEmptyStack(s2)){
        while (Top(s1, &B)) {
            printf("%d ", B->data);
            Pop(&s1);
            if (B->left) Push(&s2, B->left);
            if (B->right) Push(&s2, B->right);
        }
        while (Top(s2, &B)){
            printf("%d ", B->data);
            Pop(&s2);
            if (B->right) Push(&s1, B->right);
            if (B->left) Push(&s1, B->left);
        }
    }
}