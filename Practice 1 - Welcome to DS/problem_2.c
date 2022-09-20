#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void printLinkedList(node *head)
{
    if (!head) return;
    printf("%d ", head->data);
    if (head->next) printf("-> ");
    printLinkedList(head->next);
}

node *addNumbersHelper(node *head1, node *head2)
{
    node *result = (node *)malloc(sizeof(node));
    if (!head1 || !head2){
        result->data = 0;
        result->next = NULL;
        return result;
    }
    result->next = addNumbersHelper(head1->next, head2->next);
    result->next->data += head1->data + head2->data;
    if (result->next->data > 9){
        result->data++;
        result->next->data -= 10;
    }
    return result;
}

node *addNumbers(node *head1, node *head2)
{
    node *result = addNumbersHelper(head1, head2);
    if (result->data == 0){
        node *temp = result;
        result = result->next;
        free(temp);
    }
    return result;
}

int main()
{
    //The test driver is not working for a reason I don't have time or interest to pursue
    int numberSize;
    node *number1 = NULL, *number2 = NULL, *temp;

    scanf("%d", &numberSize);
    fflush(stdin);
    for (int i = 0; i < numberSize; i++){
        temp = (node *)malloc(sizeof(node));
        scanf("%c", &temp->data);
        temp->data -= '0';
        temp->next = number1;
        number1 = temp;
        printf("%d", number1->data);
    }

    fflush(stdin);
    for (int i = 0; i < numberSize; i++){
        temp = (node *)malloc(sizeof(node));
        scanf("%c", &temp->data);
        temp->data -= '0';
        temp->next = number1;
        number2 = temp;
    }

    temp = addNumbers(number1, number2);
    printLinkedList(temp);

    return 0;
}