int delete_BST(BST *B , element e)
{
    if (!B || !*B) return 0;
    if ((*B)->data == e){
        if ((*B)->left && (*B)->right){
            // find the max node in the left subtree
            element max;
            BST maxNode = (*B)->left;
            while (maxNode->right) maxNode = maxNode->right;
            max = maxNode->data;
            if (delete_BST(&((*B)->left), max)){
                (*B)->data = max;
                return 1;
            }
            return 0;
        }
        else if ((*B)->left){
            BST temp = *B;
            *B = (*B)->left;
            free(temp);
            return 1;
        }
        else if ((*B)->right){
            BST temp = *B;
            *B = (*B)->right;
            free(temp);
            return 1;
        }
        else{
            free(*B);
            *B = NULL;
            return 1;
        }
    }
    else if ((*B)->data < e)
        return delete_BST(&((*B)->right), e);
    return delete_BST(&((*B)->left), e);
}
