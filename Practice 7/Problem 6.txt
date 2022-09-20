int insert(BST *B , element e)
{
    if (!B) return 0;
    
    if (*B){
        if ((*B)->data == e) return 0;
        if (e < (*B)->data && (*B)->left) return insert(&((*B)->left), e);
        if (e > (*B)->data && (*B)->right) return insert(&((*B)->right), e);
    }
    
    BST newNode = (BST)malloc(sizeof(BST));
    newNode->data = e;
    newNode->left = NULL;
    newNode->right = NULL;
    
    if (!*B) *B = newNode;
    else if (e < (*B)->data) (*B)->left = newNode;
    else (*B)->right = newNode;
    
    return 1;
}
