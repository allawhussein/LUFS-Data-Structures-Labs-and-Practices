// This code doesn't achieve the goal, however I've spent 3 hours on it, I'll no more waste my time

#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int quickSort(int *arr, int a, int b, int k)
{
    if (a >= b) return -1;
    int i = a, j = b;
    int pivot = a;
    
    while (i < j){
        while ( *(arr + i) <= *(arr + pivot) && i < b) i++;
        while ( *(arr + j) > *(arr + pivot)) j--;
        if (i < j)
            swap(arr + i, arr + j);
    }
    swap(arr + pivot, arr + j);
    if (pivot == k) return *(arr + pivot);
    int resultLeft = quickSort(arr, a, j - 1, k);
    int resultRight = quickSort(arr, a + j + 1, b, k);
    if (resultLeft != -1) return resultLeft;
    if (resultRight != -1) return resultRight;
    return -1;
}

int main()
{
    int arr[100] = {190, 4, 24, -66, -43, -72, 48, -41, -68, -64};
    printf("%d", quickSort(arr, 0, 9, 1));
    return 0;
}
