int abs(int a)
{
    if (a < 0) return -a;
    return a;
}

// Or we can use
//#define abs(a) (a > 0)?a:-a

int height(Btree B) // This function should be recursive
{
    if (!B) return 0;
    return 1 + max(height(B->left), height(B->right));
}


int balanced(Btree B) // This function should be recursive
{
    if (!B) return 1;
    if (abs((height(B->left) - height(B->right) > 1))) return 0;
    return balanced(B->right) && balanced(B->left);
}