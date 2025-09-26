/*=============================================================================
*       611.c
*       timwking1
*       26-Sep 2025
*       Leetcode 611 - Valid Triangle Number
=============================================================================*/

#include <stdbool.h>        //bool
#include <stdint.h>         //uint32_t
#include <stdlib.h>         //qsort

bool isValid(int a, int b, int c)
{
    return a + b > c;
}

int cmp(const void* a, const void* b)
{
    int A = *(const int*)a;
    int B = *(const int*)b;

    if(A == B)
    {
        return 0;
    }
    int res = A < B ? -1 : 1;
    return res;
}

int triangleNumber(int* nums, int numsSize)
{
    uint32_t i = 0;
    uint32_t j = 0;
    int result = 0;

    qsort(nums, numsSize, sizeof(int), cmp);
    int iGreatest = numsSize - 1;
    int greatest = 0;

    for(iGreatest; iGreatest >= 2; iGreatest--)
    {
        greatest = nums[iGreatest];

        i = 0;
        j = iGreatest -1;
        while(i < j)
        {
            if(isValid(nums[i], nums[j], greatest))
            {
                result += j - i;
                j--;
            }
            else
            {
                i++;
            }
        }
    }
    return result;
}
