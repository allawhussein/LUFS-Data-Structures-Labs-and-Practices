int countReversalsHelper(char *str, int openBracketsCounter, int closeBracketsCounter)
{
    if (*str == '\0'){
        if (!(openBracketsCounter % 2 || closeBracketsCounter % 2))
            return (openBracketsCounter + closeBracketsCounter) / 2;
        else if (openBracketsCounter % 2 && closeBracketsCounter % 2)
            return (openBracketsCounter + closeBracketsCounter) / 2 + 1;
        return -1;
    }
    else if (*str == '('){
        return countReversalsHelper(str + 1, openBracketsCounter + 1, closeBracketsCounter);
    }
    else if (*str == ')'){
        if (openBracketsCounter > 0)
            return countReversalsHelper(str + 1, openBracketsCounter - 1, closeBracketsCounter);
        return countReversalsHelper(str + 1, 0, closeBracketsCounter + 1);
    }
    else return countReversalsHelper(str + 1, openBracketsCounter, closeBracketsCounter);
}

int countReversals(char *str)
{
    return countReversalsHelper(str, 0, 0);
}