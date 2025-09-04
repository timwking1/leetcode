/*=============================================================================
*       326.c
*       timwking1
*       14-Aug 2025
*       Leetcode 326 - Power of Three
=============================================================================*/
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

bool isPowerOfThree(int n) 
{
    if(n <= 0)
    {
        return false;
    }

    int result = n;
    while(result % 3 == 0)
    {
        result /= 3;
    }
    return result == 1;
}

//test case
int main()
{
    int n;
    printf("n:");
    scanf("%d", &n); 
    
    if(isPowerOfThree(n))
    {
        printf("true");
        return 0;
    }
    printf("false");
    return 0;
}
