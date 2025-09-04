/*=============================================================================
*       13.c
*       timwking1
*       30-Aug 2025
*       Leetcode 13 - Roman to Integer
=============================================================================*/

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>

typedef struct
{
    char sym;
    int value;
} Numeral;

Numeral table[] = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

int valFromNumeral(char n)
{
    size_t tableLen = sizeof(table)/sizeof(table[0]);
    n = toupper(n);
    for(uint32_t i = 0; i < tableLen; i++)
    {
        if(table[i].sym == n)
        {
            return table[i].value;
        }
    }
    return 0;
}

int romanToInt(char* s) 
{
    int result = 0;
    size_t len = strlen(s);
    int maxOfThree = 0;

    for(uint32_t i = 0; i < len; i++)
    {
        int cur = valFromNumeral(toupper(s[i]));
        int next = valFromNumeral(toupper(s[i + 1]));
        if(cur < next)
        {
            result -= cur;
        }
        else
        {
            result += cur;
        }
    }
    return result;
}

int main()
{
    int n = romanToInt("IV");
    printf("%d\n", n); 
}