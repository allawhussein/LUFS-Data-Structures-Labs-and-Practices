#include "Stack.h"

void sum(char *str1, char *str2, char *str3)
{
    stack s1 = CreateStack();
    stack s2 = CreateStack();
    stack s3 = CreateStack();

    int i;
    element e1 = 0, e2 = 0, result = 0;
    for (i = 0; *(str1 + i); i++) Push(&s1, *(str1 + i) - '0');
    for (i = 0; *(str2 + i); i++) Push(&s2, *(str2 + i) - '0');
    for (i = 0; *(str3 + i); i++) Push(&s3, *(str3 + i) - '0');

    while (Top(s1, &e1) || Top(s2, &e2)){
        Pop(&s1);
        Pop(&s2);
        
        result += e1 + e2;
        Push(&s3, result % 10);
        result /= 10;

        e1 = 0;
        e2 = 0;
    }
    if (result) Push(&s3, result);

    for (i = 0; Top(s3, &e1); i++){
        Pop(&s3);
        *(str3 + i) = e1 + '0';
    }
    *(str3 + i) = '\0';
}