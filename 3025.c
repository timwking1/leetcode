/*=============================================================================
*       3025.c
*       timwking1
*       2-Sep 2025
*       Leetcode 3025 - Find the Number of Ways to Place People I
=============================================================================*/

#include <stdlib.h>     //malloc, free, qsort
#include <stdint.h>     //uint32_t, size_t
#include <stdbool.h>    //bool
#include <string.h>     //memcpy

typedef struct
{
    int x;
    int y;
} Vector2;

typedef struct
{
    int left;
    int right;
    int top;
    int bottom;
} RECT;

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) 
{
    int sol = 0;

    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = 0;

    Vector2* pts = calloc(pointsSize, sizeof(Vector2));
    if(!pts)
    {
        //alloc fail
        return -1;
    }

    for(i = 0; i < pointsSize; i++)
    {
        //Convert 2D array to Vector2 array
        pts[i].x = points[i][0];
        pts[i].y = points[i][1];
    }

    //double loop brute force method...
    for(i = 0; i < pointsSize; i++)
    {
        for(j = 0; j < pointsSize; j++)
        {
            if(i == j)
            {
                continue;
            }

            int x1 = pts[i].x;
            int y1 = pts[i].y;

            int x2 = pts[j].x;
            int y2 = pts[j].y;

            if (x1 <= x2 && y1 >= y2 && (x1 < x2 || y1 > y2))
            {
                RECT rt = (RECT){0};
                rt.left = x1;
                rt.right = x2;
                rt.top = y1;
                rt.bottom = y2;

                bool valid = true;
                for(k = 0; k < pointsSize; k++)
                {
                    if(k == i || k == j)
                    {
                        //Skip over ourself
                        continue;
                    }
                    int x = pts[k].x;
                    int y = pts[k].y;

                    if (x >= rt.left && x <= rt.right && y >= rt.bottom && y <= rt.top)
                    {
                        if (!(x == x1 && y == y1) && !(x == x2 && y == y2))
                        {
                            valid = false;
                            break;
                        }
                    }
                }
                if(valid)
                {
                    sol++;
                }
            }
        }
    }
    
    free(pts);
    return sol;
}
