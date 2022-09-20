//The problem is not clear on how to structure the down pointer, and the example have some ambigious connections
#include <stdlib.h>
typedef struct {
     int row, col, value;
} element;

typedef struct matrix{
     element data;
     struct matrix *down, *right;
}matrix;

matrix *buildMatrix()
{
    int n, m, r;
    scanf("%d%d%d", &n, &m, &r);
    if (n < 1 || m < 1) return NULL;
    matrix *result = (matrix *)malloc(sizeof(matrix));
    result->data.row = 0;
    result->data.col = 0;
    result->data.value = 0;
    result->down = NULL;
    result->right = (matrix *)malloc(sizeof(matrix));
    result->right->data.row = n;
    result->right->data.col = m;
    result->right->data.value = 0;
    result->right->down = NULL;
    result->right->right = NULL;
    matrix *temp = result->right;
    for (int i = 0; i < r; i++){
        temp->right = (matrix *)malloc(sizeof(matrix));
        temp = temp->right;
        scanf("%d%d%d", 
            &(temp->data.row), 
            &(temp->data.col), 
            &(temp->data.value));
        temp->right = result->right;
        temp->down = NULL;
    }
    for (matrix *iter = result->right->right;
        iter != result->right;
        iter = iter->right){
            for (matrix *nestedIter = iter->right;
            nestedIter != result->right;
            nestedIter = nestedIter->right){
                if (nestedIter->data.col == iter->data.col){
                    iter->down = nestedIter;
                    break;
                }
            }
        }
    return result;
}