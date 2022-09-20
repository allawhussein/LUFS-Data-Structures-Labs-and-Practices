int isBalancedHelper(char str[], int openBracketsCounter)
{
    if (*str == '\0') return !openBracketsCounter;
    else if (*str == '(') return isBalancedHelper(str + 1, openBracketsCounter + 1);
    else if (*str == ')'){
        if (!openBracketsCounter) return 0;
        return isBalancedHelper(str + 1, openBracketsCounter - 1);
    }
    else if (*str == ','){
        if (openBracketsCounter) return 0;
        return isBalancedHelper(str + 1, 0);
    }
    else return isBalancedHelper(str + 1, openBracketsCounter);
}

int isBalanced(char str[])
{
    return isBalancedHelper(str, 0);
}