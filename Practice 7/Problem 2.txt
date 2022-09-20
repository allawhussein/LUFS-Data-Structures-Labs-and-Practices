int max_rec(Btree B, int i)// i is the root index
{
    if (i == 0) return INT_MIN;
    if (B.data[i].left_subtree == 0 && B.data[i].right_subtree == 0)
        return B.data[i].root;
    return max(B.data[i].root, max(
                max_rec(B, B.data[i].left_subtree),
                max_rec(B, B.data[i].right_subtree)));
}
