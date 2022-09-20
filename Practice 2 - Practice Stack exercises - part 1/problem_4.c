#include "stack.h"

int isPalindrome(char *str)
{
    stack s = CreateStack();
    for (int i = 0; *(str + i) != '\0'; i++){
        Push(&s, *(str + i));
    }
    
    for (int i = 0; *(str + i) != '\0'; i++){
        char temp;
        if (!Top(s, &temp)) return 0;
        if (temp != *(str + i)) return 0;
        Pop(&s);
    }
    return 1;
}