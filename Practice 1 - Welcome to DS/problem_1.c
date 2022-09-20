#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void moveHeadToLast(node **headRef)
{
    if (!headRef || !*headRef || !(*headRef)->next) return;
    node *temp = *headRef;
    *headRef = (*headRef)->next;
    temp->next = (*headRef)->next;
    (*headRef)->next = temp;
    moveHeadToLast(&((*headRef)->next));
}

void printLinkedList(node *head)
{
    if (!head) return;
    printf("%d ", head->data);
    if (head->next) printf("-> ");
    printLinkedList(head->next);
}

int main()
{
    node *linkedList = (node *)malloc(sizeof(node)), *iter;
    linkedList->data = 1;
    linkedList->next = NULL;
    iter = linkedList;

    for (int i = 2; i < 6; i++){
        iter->next = (node *)malloc(sizeof(node));
        iter = iter->next;
        iter->data = i;
        iter->next = NULL;
    }
    
    printLinkedList(linkedList);
    moveHeadToLast(&linkedList);
    printf("\n");
    printLinkedList(linkedList);
}