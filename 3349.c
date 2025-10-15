/*=============================================================================
*       3349.c
*       timwking1
*       14-Oct 2025
*       Leetcode 3349 - Adjacent Increasing Subarrays Detection I
=============================================================================*/
#include <stdbool.h>        /*bool*/
#include <stdint.h>         /*uint32_t, size_t*/
bool hasIncreasingSubarrays(int* nums, int numsSize, int k)
{
    if(k <= 0 || k == 1)
    {
        return true;
    }
    /*edge case*/
    if(numsSize < 2)
    {
        return false;
    }
    uint32_t i = 0;
    size_t prev = 0;
    size_t cur = 1;
    size_t count = 0;
    int adj = 0;

    for(i = 1; i < numsSize; i++)
    {
        if(nums[i] > nums[i - 1])
        {
            cur++;
        }
        else
        {
            prev = cur;
            cur = 1;
        }
        adj = (prev < cur) ? prev : cur;
        if(count < adj)
        {
            count = adj;
        }
        int h = cur / 2;
        if(count < h)
        {
            count = h;
        }
        if(count >= k)
        {
            return true;
        }
    }
    return count >= k;
}
