// This is an invalid code, as it doesn't use deques to solve the problem
// Using plain arrays just seemed more effective

// A possible approach is to insertFront A[i], and deleteRear
// and use a helper function to get the max of the deque
// but here we are effectively using a queue not a deque

void MaxSlidingWindow(int A[], int n , int w, int B[])
{
    Deque q = CreateDeque();
    element temp;
    for (int i = 0; i + w <= n; i++){
        B[i] = A[i];
        temp = A[i];
        insertFront(&q, temp);
        for (int j = i; j < i + w; j++) if (A[j] > B[i]) B[i] = A[j];
    }
}