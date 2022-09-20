int width(Btree B)
{
    if (!B) return 0;
    int currWidth = 0;
    int maxWidth = 0;
    queue q1 = CreateQueue(), q2 = CreateQueue();
    EnQueue(&q1, B);
    while (!isEmptyQueue(q1) || !isEmptyQueue(q2)){
        currWidth = 0;
        while (Front(q1, &B)) {
            currWidth++;
            DeQueue(&q1);
            if (B->left) EnQueue(&q2, B->left);
            if (B->right) EnQueue(&q2, B->right);
        }
        if (currWidth > maxWidth) maxWidth = currWidth;
        currWidth = 0;
        while (Front(q2, &B)){
            currWidth = 0;
            DeQueue(&q2);
            if (B->left) EnQueue(&q1, B->left);
            if (B->right) EnQueue(&q1, B->right);
        }
        if (currWidth > maxWidth) maxWidth = currWidth;
    }
    return maxWidth;
}