/*=============================================================================
*       3542.c
*       timwking1
*       10-Nov 2025
*       Leetcode 3542 - Minimum Operations to Convert All Elements to Zero
=============================================================================*/
#include <stdint.h>     /*uint32_t*/
#include <stdlib.h>     /*calloc, free*/

int minOperations(int* nums, int numsSize)
{
    if(numsSize == 1)
    {
        /*edge cases*/
        return (nums[0] == 0) ? 0 : 1;
    }
    register int result = 0;
    int* stack = calloc(numsSize, sizeof(int));
    if(!stack)
    {
        /*alloc fail*/
        return -1;
    }
    
    stack[0] = nums[0];
    result += (nums[0] > 0);
    int st = 0; /*stack top*/
    for(uint32_t i = 0; i < numsSize; i++)
    {
        int x = nums[i];
        while(st >= 0 && x < stack[st])
        {
            st--;
        }
        if(st < 0 || x > stack[st])
        {
            result += (x > 0);
            st++;
            stack[st] = x;
        }
    }
    free(stack);
    return result;
}
