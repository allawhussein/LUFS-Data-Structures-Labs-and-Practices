typedef struct node{
    int data;
    struct node *next;
} node;

int toDecimalHelper(node *head, int result)
{
    if (!head) return result;
    result = result << 1;
    result |= head->data;
    return toDecimalHelper(head->next, result);
}

int toDecimal(node *head)
{
    if (!head) return 0;
    return toDecimalHelper(head, 0);
}