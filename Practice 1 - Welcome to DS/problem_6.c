#include <stdio.h>
#include <stdlib.h>

char *convert(int num, int base, char *str)
{
    if (num == 0){
        *str = '0';
        *(str + 1) = '\0';
        return str;
    }
    
    int digit = num % base;
    str = convert(num / base, base, str);
    
    if (digit < 10) *str = digit + '0';
    else *str = digit - 10 + 'A';
    *(str + 1) = '\0';
    return str + 1;
}

int main()
{
    char *str = (char *)malloc(sizeof(char) * 50);
    convert(0, 8, str);
    puts(str);
    return 0;
}
