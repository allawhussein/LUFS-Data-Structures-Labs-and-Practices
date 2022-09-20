#include <stdlib.h>

typedef struct node1
{
	int data;
	int col_num;
	struct node1 *next;
} entry;

typedef struct node2
{
	int row_num;
	entry *start;
	struct node2 *next;
} row;

row **createNewRow(row **sparseRef, int row_num)
{
    if (!*sparseRef){
        *sparseRef = (row *)malloc(sizeof(row));
        (*sparseRef)->row_num = row_num;
        (*sparseRef)->start = NULL;
        (*sparseRef)->next = NULL;
        return sparseRef;
    }
    row *rowIter = NULL;
    for (
        rowIter = *sparseRef; 
        rowIter->next || rowIter->row_num == row_num;
        rowIter = rowIter->next
        ){
            if (rowIter->row_num == row_num) return &rowIter;
            if (
                    (
                        rowIter->next 
                        && rowIter->next->row_num < row_num 
                        && rowIter->row_num > row_num
                    ) 
                    || (
                        !rowIter->next
                        )
                    ){
                        row *temp = (row *)malloc(sizeof(row));
                        temp->next = rowIter->next;
                        rowIter->next = temp;
                        rowIter->row_num = row_num;
                        rowIter->start = NULL;
                        return &rowIter;
            }
        }
    return NULL;
}

entry *createNewEntry(row **targetRow, int col_num)
{
    return NULL;
}
void transpose(row **sparseRef)
{
    row **sparseTransRef = (row **)malloc(sizeof(row *));

    for (row *rowIter = *sparseRef; rowIter; rowIter = rowIter->next){
        for (entry *entryIter = rowIter->start; entryIter; entryIter = entryIter->next){
            row **newRow = createNewRow(sparseTransRef, entryIter->col_num);
            createNewEntry(newRow, (*newRow)->row_num);
        }
    }
    deleteMatrix(sparseRef);
    sparseRef = sparseTransRef;
}