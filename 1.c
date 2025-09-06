/*=============================================================================
*       1.c
*       timwking1
*       4-Sep 2025
*       Leetcode 1 - Two Sum
=============================================================================*/

#include <stdlib.h>     //malloc
#include <stdint.h>     //uint32_t
#include <stdbool.h>
//#include <uthash.h>     //hash table

typedef struct {
    int key;
    int index;
    UT_hash_handle hh;
} HashEntry;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int complement;
    uint32_t i;
    HashEntry* table = NULL;
    HashEntry* entry = NULL;
    HashEntry* found = NULL;

    int* indicies = malloc(2 * sizeof(int));

    for(i = 0; i < numsSize; i++)
    {
        complement = target - nums[i];
        HASH_FIND_INT(table, &complement, found);
        if(found)
        {
            indicies[0] = found->index;
            indicies[1] = i;
            *returnSize = 2;

            HASH_ITER(hh, table, entry, found)
            {
                HASH_DEL(table, entry);
                free(entry);
            }
            return indicies;
        }
        entry = malloc(sizeof(HashEntry));
        entry->key = nums[i];
        entry->index = i;
        HASH_ADD_INT(table, key, entry);
    }
    *returnSize = 0;
    return NULL;

//Brute force double loop method
/*
    int* indicies = calloc(numsSize, sizeof(int));
    uint32_t i = 0;
    uint32_t j = 0;

    for(i = 0; i < numsSize; i++)
    {
        for(j = 0; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                indicies[0] = j;
                indicies[1] = i;
                break;
            }
        }
    }
    *returnSize = 2;
    return indicies;
*/
}
