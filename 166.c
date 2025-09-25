/*=============================================================================
*       166.c
*       timwking1
*       24-Sep 2025
*       Leetcode 166 - Fraction to Recurring Decimal
=============================================================================*/

#include <stdlib.h>     //malloc, free
#include <stdio.h>      //sprintf
#include <stdint.h>     //uint32_t, size_t
#include <string.h>     //strdup

#define MAX_STRLEN   2048

typedef struct
{
    long long val;
    int index;
} RemHash;

char* fractionToDecimal(int numerator, int denominator)
{
    if(numerator == 0)
    {
        return "0";
    }
    if(denominator == 0)
    {
        return NULL;
    }
    
    char str[MAX_STRLEN];
    //allocated on the stack so it needs to return using strdup()

    uint32_t i = 0;

    if(denominator == 1)
    {
        sprintf(str, "%d", numerator);
        return strdup(str);
    }

    if(numerator < 0 ^ denominator < 0)
    {
        str[i++] = '-';
    }

    //take absolute value since we already added negative sign
    long long n = llabs((long long)numerator);
    long long d = llabs((long long)denominator);

    long long dec = n / d;
    long long rem = n % d;

    i += sprintf(str + i, "%lld", dec);

    if(rem == 0)
    {
        str[i] = '\0';
        return strdup(str);
    }

    //insert decimal point
    str[i++] = '.';

    uint32_t j = 0;
    uint32_t k = 0;
    size_t mapSize = 0;

    RemHash* hashMap = malloc(sizeof(RemHash) * MAX_STRLEN);
    while(rem != 0)
    {
        for(j = 0; j < mapSize; j++)
        {
            if(hashMap[j].val == rem)
            {
                for(k = i; k >= hashMap[j].index; k--)
                {
                    str[k+1] = str[k];
                }
                str[hashMap[j].index] = '(';
                i++;
                str[i++] = ')';
                str[i] = '\0';
                free(hashMap);
                return strdup(str);
            }
        }
        hashMap[mapSize].val = rem;
        hashMap[mapSize].index = i;
        mapSize++;

        rem *= 10;
        str[i++] = (rem / d) + '0';
        rem %= d;
    }

    str[i] = '\0';
    free(hashMap);
    return strdup(str);
}
