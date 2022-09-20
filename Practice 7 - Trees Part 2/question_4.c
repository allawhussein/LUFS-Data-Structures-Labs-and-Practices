int width(Btree B)
{
    if (B.root_index < 1) return 0;
    queue q = CreateQueue();
    int currWidth = 0, maxWidth = 1;
    int currLevel = 1;
    element1 node, temp;
    node.tree = B;
    node.level = 1;
    node.root = B.root_index;
    EnQueue(&q, node);
    while(Front(q, &node)){
        if (node.level == currLevel) currWidth++;
        else {
            if (currWidth > maxWidth) maxWidth = currWidth;
            currLevel = node.level;
            currWidth = 1;
        }
        temp.tree = node.tree;
        temp.level = node.level + 1;
        temp.root = node.tree.data[node.root].left_subtree;
        if (temp.root) EnQueue(&q, temp);
        temp.root = node.tree.data[node.root].right_subtree;
        if (temp.root) EnQueue(&q, temp);
        DeQueue(&q);
    }
    if (currWidth > maxWidth) maxWidth = currWidth;
    return maxWidth;
}