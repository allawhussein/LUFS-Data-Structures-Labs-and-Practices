void level_order(Btree B)
{
    if (!B) return;
    queue q1 = CreateQueue(), q2 = CreateQueue();
    EnQueue(&q1, B);
    while (!isEmptyQueue(q1) || !isEmptyQueue(q2)){
        while (Front(q1, &B)) {
            printf("%d ", B->data);
            DeQueue(&q1);
            if (B->left) EnQueue(&q2, B->left);
            if (B->right) EnQueue(&q2, B->right);
        }
        while (Front(q2, &B)){
            printf("%d ", B->data);
            DeQueue(&q2);
            if (B->left) EnQueue(&q1, B->left);
            if (B->right) EnQueue(&q1, B->right);
        }
    }
}