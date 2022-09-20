void reversrorder(Btree B)
{
    if (B == NULL) return;
    stack treeData = CreateStack();
    queue treeTraverser = CreateQueue();
    
    EnQueue(&treeTraverser, B);
    while(Front(treeTraverser, &B)){
        DeQueue(&treeTraverser);
        if (B->right != NULL) EnQueue(&treeTraverser, B->right);
        if (B->left != NULL) EnQueue(&treeTraverser, B->left);
        Push(&treeData, B);
    }
    while(Top(treeData, &B)){
        Pop(&treeData);
        printf("%d ", B->data);
    }
}