/*=============================================================================
*       3005.c
*       timwking1
*       22-Sep 2025
*       Leetcode 3005 - Count Elements With Maximum Frequency
=============================================================================*/

#include <stdint.h>         //uint32_t
#include <stdlib.h>         //calloc, free

int maxFrequencyElements(int* nums, int numsSize) 
{
    size_t max = 0;
    uint32_t i = 0;
    long long maxFreq = 0;
    int numMaxFreq = 0;

    for(i = 0; i < numsSize; i++)
    {
        if(max < nums[i])
        {
            max = nums[i];
        }
    }

    int* freq = calloc(max + 1, sizeof(int));
    if(!freq)
    {
        //alloc fail
        return -1;
    }

    for(i = 0; i < numsSize; i++)
    {
        freq[nums[i]]++;
    }

    for(i = 0; i <= max; i++)
    {
        if(freq[i] == maxFreq)
        {
            numMaxFreq++;
        }
        if(freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            numMaxFreq = 1;
        }
    }
    free(freq);
    return maxFreq * numMaxFreq;
}
