/*=============================================================================
*       3350.c
*       timwking1
*       15-Oct 2025
*       Leetcode 3350 - Adjacent Increasing Subarrays Detection II
=============================================================================*/
#include <stdint.h>         /*uint32_t*/

int maxIncreasingSubarrays(int* nums, int numsSize)
{
    uint32_t i = 0;
    int result = 0;
    size_t count = 1;
    size_t prev = 0;
    size_t min = 0;
    size_t half = 0;

    for(i = 1; i < numsSize; i++)
    {
        if(nums[i] > nums[i-1])
        {
            count++;
        }
        else
        {
            prev = count;
            count = 1;
        }
        half = count / 2;
        min = prev < count ? prev : count;
        result = result > min ? result : min;
        result = result > half ? result : half;
    }
    return result;
}
