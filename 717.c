/*=============================================================================
*       717.c
*       timwking1
*       18-Nov 2025
*       Leetcode 717 - 1-bit and 2-bit Characters
=============================================================================*/
#include <stdbool.h>    /*boolean type*/
#include <stdint.h>     /*uint32_t*/

bool isOneBitCharacter(int* bits, int bitsSize)
{
    if(bits[bitsSize] == 0)
    {
        int sum = 0;
        for(int i = bitsSize - 1; i > 0; i--)
        {
            if(bits[i] == 1)
            {
                sum++;
            }
            else break;
        }
        if(sum % 2 == 0)
        {
            return true;
        }
        return false;
    }
    return false;
}
