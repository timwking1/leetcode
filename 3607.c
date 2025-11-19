/*=============================================================================
*       3607.c
*       timwking1
*       5-Nov 2025
*       Leetcode 3607 - Power Grid Maintenance
=============================================================================*/
#include <stdint.h>     /*uint32_t, size_t*/
#include <stdlib.h>     /*malloc, free*/
#include <stdbool.h>    /*boolean type*/

/*uthash hash map struct*/
typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} hash_t;

/*disjoint set struct*/
typedef struct {
    int* parent;
    int size;
} dsu_t;

dsu_t* ConstructDsu(size_t size)
{
    dsu_t* new = (dsu_t*)malloc(sizeof(dsu_t));
    new->size = size;
    new->parent = (int*)malloc(size * sizeof(int));
    for(uint32_t i = 0; i < size; i++)
    {
        new->parent[i] = i;
    }
    return new;
}

void DestroyDsu(dsu_t* dsu)
{
    free(dsu->parent);
    free(dsu);
}

int FindDsu(dsu_t* dsu, int x)
{
    if(dsu->parent[x] != x)
    {
        dsu->parent[x] = FindDsu(dsu, dsu->parent[x]);
    }
    return dsu->parent[x];
}

void JoinDsu(dsu_t* dsu, int u, int v)
{
    dsu->parent[FindDsu(dsu, v)] = FindDsu(dsu, u);
}

hash_t* HashFind(hash_t** item, int key)
{
    hash_t* entry = NULL;
    HASH_FIND_INT(*item, &key, entry);
    return entry;
}

bool HashAdd(hash_t** item, int key, int val)
{
    if(HashFind(item, key))
    {
        return false;
    }
    hash_t* entry = (hash_t*)malloc(sizeof(hash_t));
    entry->key = key;
    entry->value = val;
    HASH_ADD_INT(*item, key, entry);
    return true;
}

bool HashSetItem(hash_t** item, int key, int val)
{
    hash_t* entry = HashFind(item, key);
    if(!entry)
    {
        HashAdd(item, key, val);
    }
    else
    {
        entry->value = val;
    }
    return true;
}

int HashGetItem(hash_t** item, int key, int def)
{
    hash_t* entry = HashFind(item, key);
    if(!entry)
    {
        return def;
    }
    return entry->value;
}

void DestroyHash(hash_t** item)
{
    hash_t* cur = NULL;
    hash_t* tmp = NULL;
    HASH_ITER(hh, *item, cur, tmp)
    {
        HASH_DEL(*item, cur);
        free(cur);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* processQueries(int c, int** connections, int connectionsSize, int* connectionsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
    uint32_t i = 0;
    dsu_t* dsu = ConstructDsu(c + 1);
    for(i = 0; i < connectionsSize; i++)
    {
        JoinDsu(dsu, connections[i][0], connections[i][1]);
    }
    bool* online = (bool*)malloc((c+1) * sizeof(bool));
    int* offlineCounts = (int*)calloc(c+1, sizeof(int));
    for(i = 0; i <= c; i++)
    {
        online[i] = true;
    }

    hash_t* minimumOnline = NULL;
    for(i = 0; i < queriesSize; i++)
    {
        int op = queries[i][0];
        int x = queries[i][1];
        if(op == 2)
        {
            online[x] = false;
            offlineCounts[x]++;
        }
    }

    for(i = 1; i <= c; i++)
    {
        int root = FindDsu(dsu, i);
        if(!HashFind(&minimumOnline, root))
        {
            HashAdd(&minimumOnline, root, -1);
        }
        int station = HashGetItem(&minimumOnline, root, -1);
        if(online[i])
        {
            if(station == -1 || station > i)
            {
                HashSetItem(&minimumOnline, root, i);
            }
        }
    }

    int* result = (int*)malloc(queriesSize * sizeof(int));
    size_t resSize = 0;
    int j = 0;
    for(j = queriesSize - 1; j >= 0; j--)
    {
        int op = queries[j][0];
        int x = queries[j][1];
        int root = FindDsu(dsu, x);
        int station = HashGetItem(&minimumOnline, root, -1);
        if(op == 1)
        {
            if(online[x])
            {
                result[resSize++] = x;
            }
            else
            {
                result[resSize++] = station;
            }
        }
        if(op == 2)
        {
            if(offlineCounts[x] > 1)
            {
                offlineCounts[x]--;
            }
            else
            {
                online[x] = true;
                if(station == -1 || station > x)
                {
                    HashSetItem(&minimumOnline, root, x);
                }
            }
        }
    }
    int k = 0;
    int l = 0;
    for(k = 0, l = resSize - 1; k < l; k++, l--)
    {
        int tmp = result[k];
        result[k] = result[l];
        result[l] = tmp;
    }

    *returnSize = resSize;
    DestroyDsu(dsu);
    free(online);
    free(offlineCounts);
    DestroyHash(&minimumOnline);

    return result;
}
