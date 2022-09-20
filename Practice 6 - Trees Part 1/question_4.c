int isBST(Btree tree, int *dump, Btree leftNode = NULL, Btree rightNode = NULL)
{
    if(tree == NULL)
        return 1;
    
    if (leftNode != NULL && tree->data <= leftNode->data) return 0;
    if (rightNode != NULL && tree->data >= rightNode->data) return 0;
    return (isBST(tree->left, dump, leftNode, tree) && isBST(tree->right, dump, tree, rightNode));
}