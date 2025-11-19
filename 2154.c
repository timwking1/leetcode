/*=============================================================================
*       2154.c
*       timwking1
*       19-Nov 2025
*       Leetcode 2154 - Keep Multiplying Found Values by Two
=============================================================================*/
#include <stdint.h>     /*uint32_t*/
#include <stdlib.h>     /*malloc, free*/
#include <stdbool.h>    /*boolean type*/
typedef struct
{
    int *table;
    size_t size;
} HashSet;

static HashSet* ConstructHashSet(int* nums, size_t numsSize)
{
    size_t size = numsSize * 2 + 1;
    HashSet* new = malloc(sizeof(HashSet));
    if(!new)
    {
        /*alloc fail*/
        return NULL;
    }
    new->table = calloc(size, sizeof(int));
    if(!new->table)
    {
        /*alloc fail*/
        free(new);
        return NULL;
    }
    new->size = size;
    for(uint32_t i = 0; i < numsSize; i++)
    {
        int val = nums[i];
        int idx = (val % size + size) % size;
        while(new->table[idx] != 0 && new->table[idx] != val)
        {
            idx = (idx + 1) % size;
        }
        new->table[idx] = val;
    }
    return new;
}

static void DestroyHashSet(HashSet* set)
{
    if(set && set->table)
    {
        free(set->table);
        free(set);
    }
}

static bool Contains(HashSet* set, int val)
{
    int idx = (val % set->size + set->size) % set->size;
    while(set->table[idx] != 0)
    {
        if(set->table[idx] == val) return true;
        idx = (idx + 1) % set->size;
    }
    return false;
}

int findFinalValue(int* nums, int numsSize, int original)
{
    HashSet* set = ConstructHashSet(nums, numsSize);
    search:
    if(Contains(set, original))
    {
        original *= 2;
        goto search;
    }
    DestroyHashSet(set);
    return original;
}
