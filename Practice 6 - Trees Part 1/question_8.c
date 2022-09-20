int isPairPresent(Btree root, int target , int *nb1, int *nb2)
{
    stack s1 = CreateStack(), s2 = CreateStack();
    Btree temp1 = root, temp2 = root;
    //printf("%d\n", target);
    do {
        while (temp1 != NULL){
            Push(&s1, temp1);
            temp1 = temp1->left;
        }
        while (temp2 != NULL){
            Push(&s2, temp2);
            temp2 = temp2->right;
        }
        if (!Top(s1, &temp1)) return 0;
        if (!Top(s2, &temp2)) return 0;
        //printf("%d %d \n", temp1->data, temp2->data);
        if (temp1->data + temp2->data == target){
            if (temp1->data != temp2->data){
                *nb1 = temp1->data;
                *nb2 = temp2->data;
                return 1;
            }
            else return 0;
        }
        else if (temp1->data + temp2->data > target){
            if (!Pop(&s2)) return 0;
            temp1 = NULL;
            temp2 = temp2->left;
        }
        else {
            if (!Pop(&s1)) return 0;
            temp1 = temp1->right;
            temp2 = NULL;
        }
    } while(!isEmptyStack(s1) || !isEmptyStack(s2));
    return 0;
}