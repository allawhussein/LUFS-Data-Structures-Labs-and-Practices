element maxBSTElement(BST B){
    if (!B) return -1;
    if (B->right) return maxBSTElement(B->right);
    return B->data;
}

int delete_BST(BST *B , element e)
{
    if (!B || !*B) return 0;
    BST curr = *B, prev = NULL;
    while (curr != NULL && curr->data != e){
        prev = curr;
        if (curr->data < e) curr = curr->right;
        else curr = curr->left;
    }
    if (curr == NULL) return 0;
    if (!curr->left && !curr->right){
        if (!prev){
            *B = NULL;
            return 1;
        }
        if (prev->left == curr) prev->left = NULL;
        else prev->right = NULL;
        free(curr);
        return 1;
    }
    else if (!curr->left || !curr->left){
        if (!prev){
            if (curr->left) *B = curr->left;
            else *B = curr->right;
            free(curr);
            return 1;
        }
        if (prev->left == curr){
            if (curr->left){
                prev->left = curr->left;
                free(curr);
                return 1;
            }
            else {
                prev->left = curr->right;
                free(curr);
                return 1;
            }
        }
        else {
            if (curr->left){
                prev->right = curr->left;
                free(curr);
                return 1;
            }
            else {
                prev->right = curr->right;
                free(curr);
                return 1;
            }
        }
    }
    else {
        element maxLeft = maxBSTElement(curr->left);
        curr->data = maxLeft;
        BST temp = curr->left;
        prev = curr;
        while (temp->data != maxLeft){
            prev = temp;
            temp = temp->right;
        }
        if (prev == curr){
            prev->left = temp->left;
            free(temp);
            return 1;
        }
        prev->right = temp->left;
        free(temp);
        return 1;
    }
}
