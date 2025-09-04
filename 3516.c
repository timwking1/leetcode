/*=============================================================================
*       3516.c
*       timwking1
*       4-Sep 2025
*       Leetcode 3516 - Find Closest Person
=============================================================================*/

#include <stdint.h>

int findClosest(int x, int y, int z) 
{
    uint32_t xDist = (z < x) ? (x - z) : (z - x);
    uint32_t yDist = (z < y) ? (y - z) : (z - y);

    if(xDist == yDist)
    {
        return 0;
    }
    return (xDist < yDist) ? 1 : 2;
}
