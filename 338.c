/*=============================================================================
*       338.c
*       timwking1
*       5-Sep 2025
*       Leetcode 338 - Counting Bits
=============================================================================*/

#include <stdint.h>     //uint32_t
#include <stdlib.h>     //malloc

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize)
{
    uint32_t i;
    int* arr = malloc(sizeof(int) * n + 1);
    if(!arr)
    {
        //alloc fail
        return NULL;
    }
    for(i = 0; i < n; i++)
    {
        arr[i] = __builtin_popcount(i);
    }
    *returnSize = n+1;
    return arr;
}
