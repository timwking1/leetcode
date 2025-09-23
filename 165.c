/*=============================================================================
*       165.c
*       timwking1
*       23-Sep 2025
*       Leetcode 165 - Compare Version Numbers
=============================================================================*/

#include <stdint.h>         //uint32_t
#include <stdlib.h>         //atoi, malloc, realloc
#include <string.h>         //strlen

int compareVersion(char* version1, char* version2)
{
    char* token;

    //define these as dup and sep since strsep moves the pointer
    //and we will need the start address saved to free later
    char* dupVersion1 = strdup(version1);
    char* dupVersion2 = strdup(version2);

    char* sepVersion1 = dupVersion1;
    char* sepVersion2 = dupVersion2;

    if(!sepVersion1 || !sepVersion2)
    {
        return -1;
    }

    int* arrVersion1 = malloc(sizeof(int));
    if(!arrVersion1)
    {
        //alloc fail
        return -1;
    }
    int* arrVersion2 = malloc(sizeof(int));
    if(!arrVersion2)
    {
        free(arrVersion1);
        //alloc fail
        return -1;
    }

    size_t nVersion1 = 0;
    size_t nVersion2 = 0;

    uint32_t i = 0;

    //parse
    while((token = strsep(&sepVersion1, ".")) != NULL)
    {
        arrVersion1 = realloc(arrVersion1, (nVersion1 + 1) * sizeof(int));
        if(!arrVersion1)
        {
            //realloc fail
            free(arrVersion2);
            free(dupVersion1); 
            free(dupVersion2);
            return -1;
        }
        arrVersion1[nVersion1] = atoi(token);
        nVersion1++;
    }

    while((token = strsep(&sepVersion2, ".")) != NULL)
    {
        arrVersion2 = realloc(arrVersion2, (nVersion2 + 1) * sizeof(int));
        if(!arrVersion2)
        {
            //realloc fail
            free(arrVersion1);
            free(dupVersion1); 
            free(dupVersion2);
            return -1;
        }
        arrVersion2[nVersion2] = atoi(token);
        nVersion2++;
    }

    //duplicated strings no longer needed...
    free(dupVersion1); 
    free(dupVersion2);

    //insert zeroes so that both versions are the same length
    if(nVersion1 > nVersion2)
    {
        arrVersion2 = realloc(arrVersion2, nVersion1 * sizeof(int));
        if(!arrVersion2)
        {
            //realloc fail
            free(arrVersion1);
            return -1;
        }
        for(i = nVersion2; i < nVersion1; i++)
        {
            arrVersion2[i] = 0;
        }
        nVersion2 = nVersion1;
    }
    else if(nVersion2 > nVersion1)
    {
        arrVersion1 = realloc(arrVersion1, nVersion2 * sizeof(int));
        if(!arrVersion1)
        {
            //realloc fail
            free(arrVersion2);
            return -1;
        }
        for(i = nVersion1; i < nVersion2; i++)
        {
            arrVersion1[i] = 0;
        }
        nVersion1 = nVersion2;
    }

    size_t max = nVersion1 > nVersion2 ? nVersion1 : nVersion2;

    for(i = 0; i < max; i++)
    {
        int v1 = (i < nVersion1) ? arrVersion1[i] : 0;
        int v2 = (i < nVersion2) ? arrVersion2[i] : 0;
        if(v1 > v2)
        {
            free(arrVersion1);
            free(arrVersion2);
            return 1;
        }
        if(v1 < v2)
        {
            free(arrVersion1);
            free(arrVersion2);
            return -1;
        }
    }
    free(arrVersion1);
    free(arrVersion2);
    return 0;
}
