int isBST(Btree tree, Btree leftNode = NULL, Btree rightNode = NULL)
{
    if(tree == NULL)
        return 1;
    
    if (leftNode != NULL && tree->data <= leftNode->data) return 0;
    if (rightNode != NULL && tree->data >= rightNode->data) return 0;
    return (isBST(tree->left, leftNode, tree) && isBST(tree->right, tree, rightNode));
}