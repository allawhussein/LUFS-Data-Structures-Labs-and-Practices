#include "Btree.h"

Btree Create_Btree()
{
    return NULL;
}

int isEmpty_Btree(Btree B)
{
    return (B == NULL);
}

Btree Construct(element e, Btree L, Btree R)
{
    Btree temp;
    temp = (Btree)malloc(sizeof(struct node));
    if (!temp) return 0;
    temp->data = e;
    temp->left = L;
    temp->right = R;
    return temp;
}

int Root(Btree B, element *e)
{
    if (isEmpty_Tree(B)) return 0;
    *e = B->data;
    return 1;
}

int Left(Btree B, BTree *L)
{
    if (isEmpty_Tree(B)) return 0;
    *L = B->left;
    return 1;
}

int Right(Btree B, BTree *R)
{
    if (isEmpty_Tree(B)) return 0;
    *L = B->right;
    return 1;
}