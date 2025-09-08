/*=============================================================================
*       1337.c
*       timwking1
*       8-Sep 2025
*       Leetcode 1337 - The K Weakest Rows in a Matrix
=============================================================================*/

#include <stdlib.h>     //malloc, free, qsort
#include <stdint.h>     //uint32_t

typedef struct {
    int index;
    int value;
} Row;

int cmp(const void* a, const void* b)
{
    const Row *A = (Row*)a;
    const Row *B = (Row*)b;
    if (A->value != B->value)
    {
        return A->value - B->value;
    }
    return A->index - B->index;
}

int strength(int* row, int rowColSize)
{
    int s = 0;
    uint32_t i = 0;
    for(i = 0; i < rowColSize; i++)
    {
        if(row[i] == 1)
        {
            s++;
        }
        else
        {
            break;
        }
    }
    return s;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize)
{
    uint32_t i = 0;

    //strength values
    Row* rowStrengths = malloc(sizeof(Row) * matSize);
    //indicies of weakest rows
    int* weakestRows = malloc(sizeof(int) * k);
    if(!rowStrengths && !weakestRows)
    {
        //alloc fail
        return NULL;
    }

    for(i = 0; i < matSize; i++)
    {
        rowStrengths[i].index = i;
        rowStrengths[i].value = strength(mat[i], matColSize[i]);
    }
    qsort(rowStrengths, matSize, sizeof(Row), cmp);
    
    for(i = 0; i < k; i++)
    {
        weakestRows[i] = rowStrengths[i].index;
    }
    free(rowStrengths);

    *returnSize = k;
    return weakestRows;
}
