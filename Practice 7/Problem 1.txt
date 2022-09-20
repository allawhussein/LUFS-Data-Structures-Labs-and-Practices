int insert_Balanced(Btree *B, element e)
{
    if(!insert_BST(B, e)) return 0;
    if (e < (*B)->data){//element should be inserted to the left
        if(right_lean((*B)->left))
            left_right_rotation(B);
        else
            right_rotation(B);
        
    }
    else{//element should be inserted to the right
        if (left_lean((*B)->right))
            right_left_rotation(B);
        else
            left_rotation(B);
    }
    return 1;
}