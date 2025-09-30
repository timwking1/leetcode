/*=============================================================================
*       2221.c
*       timwking1
*       30-Sep 2025
*       Leetcode 2221 - Find Triangular Sum of an Array
=============================================================================*/

/*
*   Why I use uint32_t instead of int:
*   1. Sign safety: use unsigned int if indicies should never be negative
*   2. Size safety: sizeof(uint32_t) should always be 4 bytes on any platform
*   3. Bounds safety: upper/lower bound is ALWAYS consistently: 0 - 4294967295
*   4. Readability: typedefs that indicate size and signedness should be used in place of the basic types
*/

#include <stdlib.h>     //malloc
#include <stdint.h>     //uint32_t
#include <stdbool.h>    //bool

static bool runFlag = false;
static int* newNums = NULL;
int triangularSum(int* nums, int numsSize)
{
    uint32_t i = 0;
    int result;

    if(!runFlag)
    {
        newNums = malloc(sizeof(int) * (numsSize));
        if(!newNums)
        {
            //alloc fail
            return -1;
        }
        runFlag = true;
    }

    if(numsSize > 1 && newNums != NULL)
    {
        for(i = 0; i < numsSize - 1; i++)
        {
            newNums[i] = (nums[i] + nums[i + 1]) % 10;
        }
        //recursion go brrrr :3
        result = triangularSum(newNums, numsSize - 1);
        return result;
    }
    else
    {
        result = nums[0];
        free(newNums);
        newNums = NULL;
        runFlag = false;
        return result;
    }
}
