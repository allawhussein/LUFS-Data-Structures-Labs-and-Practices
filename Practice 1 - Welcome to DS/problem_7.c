#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void printLinkedList(node *head)
{
    if (!head) return;
    printf("%d ", head->data);
    if (head->next) printf("-> ");
    else printf("\n");
    printLinkedList(head->next);
}

node *createLinkedListHelper(int num, int ctr)
{
    if (num < ctr) return NULL;
    node *temp = (node *)malloc(sizeof(node));
    temp->data = ctr;
    temp->next = createLinkedListHelper(num, ctr + 1);
    return temp;
}

node *createLinkedList(int num)
{
    return createLinkedListHelper(num, 1);
}

void reorder(node **headRef)
{
    if (!headRef || !*headRef || !(*headRef)->next) return;
    node *preLast = *headRef, *last = (*headRef)->next, *first = *headRef;
    while (preLast->next->next) preLast = preLast->next;
    last = preLast->next;
    preLast->next = NULL;
    last->next = first;
    *headRef = last;
    reorder(&(first->next));
}

int main()
{
    node *linkedList = createLinkedList(14);
    printLinkedList(linkedList);
    reorder(&linkedList);
    printLinkedList(linkedList);
    return 0;
}
