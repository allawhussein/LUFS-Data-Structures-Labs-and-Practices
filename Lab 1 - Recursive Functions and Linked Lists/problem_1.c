void min_max(int arr[], int sz, int *min, int *max)
{
    if (sz == 0) return;
    if (*min > *arr) *min = *arr;
    if (*max < *arr) *max = *arr;
    min_max(arr + 1, sz - 1, min, max);
}

// The above function should be renamed to min_max_helper
// The purpose of the helper function is memeory safety and correct min/max initialization
// but the tutor's compiler refused the helper function
/*void min_max(int arr[], int sz, int *min, int *max)
{
    if (sz == 0) return;
    *min = *arr;
    *max = *arr;
    min_max_helper(arr, sz, min, max);
}*/