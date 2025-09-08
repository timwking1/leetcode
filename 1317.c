/*=============================================================================
*       1317.c
*       timwking1
*       8-Sep 2025
*       Leetcode 1317 - Convert Integer to the Sum of Two No-Zero Integers
=============================================================================*/

#include <stdint.h>     //uint32_t
#include <stdlib.h>     //malloc
#include <stdbool.h>    //bool


bool isNoZero(int n)
{
    while(n > 0)
    {
        if(n % 10 == 0)
        {
            return false;
        }
        n/=10;
    }
    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getNoZeroIntegers(int n, int* returnSize)
{
    uint32_t i = 0;

    int* results = malloc(sizeof(int) * 2);
    if(!results)
    {
        //alloc fail
        return NULL;
    }

    for(i = 1; i < n; i++)
    {
        if(isNoZero(i) && isNoZero(n - i))
        {
            results[0] = i;
            results[1] = n-i;
            *returnSize = 2;
            return results;
        }
        else
        {
            continue;
        }
    }
    
    free(results);
    return NULL;
}
