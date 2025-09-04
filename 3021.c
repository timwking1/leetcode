/*=============================================================================
*       3021.c
*       timwking1
*       29-Aug 2025
*       Leetcode 3021 - Alice and Bob Playing Flower Game
=============================================================================*/

#include <stdint.h>
#include <stdio.h>

/*
    given two rows of flowers (n and m) compute the number of pairs
    that allow alice to win

    the pairs represent the positive number of flowers in each lane

    if the sum  of flowers is odd (since alice goes first...)
*/

long long flowerGame(int n, int m) 
{
    //check if it satisfies the conditions
    if(n <= 0 || m <= 0)
    {
        return 0;
    }
    if(n + m == 2 || n + m % 2 == 0)
    {
        return 0;
    }

    long long evenN = (n + 1) / 2;
    long long oddN = n / 2;
    long long evenM = (m + 1) / 2;
    long long oddM = m / 2;

    long long result = evenN * oddM + oddN * evenM;
    return result;
}

int main()
{
    long long res = flowerGame(4, 4);
    printf("%d\n", res);
}
