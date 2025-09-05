/*=============================================================================
*       2749.c
*       timwking1
*       5-Sep 2025
*       Leetcode 2749 - Minimum Operations to Make the Integer Zero
=============================================================================*/

#include <stdint.h>

int makeTheIntegerZero(int num1, int num2)
{
    uint32_t i;
    for(i = 1; i <= 60; i++)
    {
        //cast to signed int64_t since i * num2 can be > num1
        int64_t x = (int64_t)num1 - (int64_t)i * (int64_t)num2;
        if(x < i)
        {
            break;
        }
        //if number of 1 bits <= i
        if(__builtin_popcount(x) <= i)
        {
            return i;
        }
    }
    return -1;
}
