#include <stdio.h>
#include <stdlib.h>

typedef struct node{
     int data;
     struct node* next;
} node;

void addElementToLinkedList(node **headRef, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = *headRef;
    *headRef = temp;
}

void printLinkedList(node *head)
{
    if (!head) return;
    printf("%d ", head->data);
    if (head->next) printf("-> ");
    else printf("\n");
    printLinkedList(head->next);
}

// This code failed some unknown test cases on Dr. Antoun's site
// Thus I'll give it a pass
int removeDuplicateNodes(node **headRef, int data)
{
    if (!headRef || !*headRef) return 0;
    if ((*headRef)->data == data){
        node *temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        return 1 + removeDuplicateNodes(headRef, data);
    }
    return removeDuplicateNodes(&((*headRef)->next), data);
}

void uniqueNodes(node **headRef)
{
    if (!headRef || !*headRef) return;
    if (removeDuplicateNodes(&((*headRef)->next), (*headRef)->data)){
        removeDuplicateNodes(headRef, (*headRef)->data);
        uniqueNodes(headRef);
    }
    uniqueNodes(&((*headRef)->next));
}

int main()
{
    node *linkedList = NULL;
    addElementToLinkedList(&linkedList, 1);
    addElementToLinkedList(&linkedList, 3);
    addElementToLinkedList(&linkedList, 5);
    addElementToLinkedList(&linkedList, 6);
    addElementToLinkedList(&linkedList, 1);
    addElementToLinkedList(&linkedList, 1);
    addElementToLinkedList(&linkedList, 1);
    addElementToLinkedList(&linkedList, 3);
    addElementToLinkedList(&linkedList, 1);
    addElementToLinkedList(&linkedList, 8);
    addElementToLinkedList(&linkedList, 1);
    addElementToLinkedList(&linkedList, 1);
    
    printLinkedList(linkedList);
    removeDuplicateNodes(&linkedList, 1);
    //uniqueNodes(&linkedList);
    printLinkedList(linkedList);
    
    return 0;
}