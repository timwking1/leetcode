/*=============================================================================
*       3100.c
*       timwking1
*       2-Oct 2025
*       Leetcode 3100 - Water Bottles II
=============================================================================*/

int maxBottlesDrunk(int numBottles, int numExchange)
{
    int nDrank = numBottles;
    for(; numBottles >= numExchange; numExchange++)
    {
        numBottles = numBottles - numExchange + 1;
        nDrank++;
    }
    return nDrank;
}
