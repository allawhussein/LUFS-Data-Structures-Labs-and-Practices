int insert(BST *B , element e)
{
    if (!B) return 0;
    if (!*B){
        *B = (BST)malloc(sizeof(struct node));
        (*B)->data = e;
        (*B)->left = NULL;
        (*B)->right = NULL;
        return 1;
    }
    BST temp = *B;
    while (temp){
        if (temp->data == e) return 0;
        else if (temp->data < e){
            if (temp->right) temp = temp->right;
            else {
                temp->right = (BST)malloc(sizeof(BST));
                temp->right->data = e;
                temp->right->right = NULL;
                temp->right->left = NULL;
            }
        }
        else {
            if (temp->left) temp = temp->left;
            else {
                temp->left = (BST)malloc(sizeof(BST));
                temp->left->data = e;
                temp->left->right = NULL;
                temp->left->left = NULL;
            }
        }
    }
    return 0;
}
