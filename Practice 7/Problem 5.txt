int Complete(Btree tree)
{
    if (!tree.root_index) return 1;
    int root_index = tree.root_index;
    if (!tree.data[root_index].left_subtree && !tree.data[root_index].right_subtree)
        return 1;
    if (!tree.data[root_index].left_subtree || !tree.data[root_index].right_subtree)
        return 0;
    
    int leftStatus = 0, rightStatus = 0;
    tree.root_index = tree.data[root_index].left_subtree;
    leftStatus = Complete(tree);
    tree.root_index = tree.data[root_index].right_subtree;
    rightStatus = Complete(tree);
    return leftStatus && rightStatus;
}
