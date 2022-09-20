#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
} node;

void deleteLinkedList(node *headRef)
{
    if (!headRef) return;
    deleteLinkedList(headRef->next);
    free(headRef);
}

int isBalancedHelper(char *str, node **headRef)
{
   if (*str == '\0'){
       if (!headRef || !*headRef) return 1;
       deleteLinkedList(*headRef);
       *headRef = NULL;
       return 0;
   }
   else if (*str == '(' || *str == '[' || *str == '{'){
       node *temp = (node *)malloc(sizeof(node));
       temp->data = *str;
       temp->next = *headRef;
       *headRef = temp;
       return isBalancedHelper(str + 1, headRef);
   }
   else if (*str == ')'){
       if ((*headRef) && (*headRef)->data == '('){
            node *temp = *headRef;
            *headRef = temp->next;
            free(temp);
            return isBalancedHelper(str + 1, headRef);
       }
       return 0;
   }
   else if (*str == ']'){
       if ((*headRef) && (*headRef)->data == '['){
            node *temp = *headRef;
            *headRef = temp->next;
            free(temp);
            return isBalancedHelper(str + 1, headRef);
       }
       return 0;
   }
   else if (*str == '}'){
       if ((*headRef) && (*headRef)->data == '{'){
            node *temp = *headRef;
            *headRef = temp->next;
            free(temp);
            return isBalancedHelper(str + 1, headRef);
       }
       return 0;
   }
   else return isBalancedHelper(str + 1, headRef);
}

int isBalanced(char *str)
{
    node *head = NULL;
    return isBalancedHelper(str, &head);
}