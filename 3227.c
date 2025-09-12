/*=============================================================================
*       3227.c
*       timwking1
*       12-Sep 2025
*       Leetcode 3227 - Vowels Game in a String
=============================================================================*/

#include <stdbool.h>    //bool
#include <stdint.h>     //uint32_t
#include <string.h>     //strlen

bool doesAliceWin(char* s)
{
    uint32_t i = 0;
    size_t len = strlen(s);
    for(i = 0; i < len; i++)
    {
        if(s[i] == 'a'
        || s[i] == 'e'
        || s[i] == 'i'
        || s[i] == 'o'
        || s[i] == 'u'
        )
        {
            return true;
        }
    }
    return false;
}
