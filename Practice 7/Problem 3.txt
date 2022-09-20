int isBSTH(Btree tree, int i)
{
    if (i == 0) return 1;
    if (tree.data[i].left_subtree &&
        max_rec(tree, tree.data[i].left_subtree) > tree.data[i].root)
            return 0;
    if (tree.data[i].right_subtree &&
        min_rec(tree, tree.data[i].right_subtree) < tree.data[i].root)
            return 0;
    if (
        !isBSTH(tree, tree.data[i].left_subtree) || 
        !isBSTH(tree, tree.data[i].right_subtree)) return 0; 
    return 1;
}

int isBST(Btree tree)
{
    return isBSTH(tree, tree.root_index);
}
