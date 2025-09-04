/*=============================================================================
*       3000.c
*       timwking1
*       26-Aug 2025
*       Leetcode 3000 - Maximum Area of Longest Diagonal Rectangle
=============================================================================*/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <stdint.h>

int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) 
{
    uint32_t w;
    uint32_t l;

    double diagSq;
    uint32_t area;

    double largestSq = 0;
    uint32_t largest = 0;
    uint32_t largestIndex = 0;

    for(uint32_t i = 0; i < dimensionsSize; i++)
    {
        w = dimensions[i][0];
        l = dimensions[i][1];

        diagSq = (double)(w * w) + (double)(l * l);
        area = w * l;

        if(diagSq > largestSq || (diagSq == largestSq && area > largest))
        {
            largestSq = diagSq;
            largest = area;
            largestIndex =i;
        }
    }
    return dimensions[largestIndex][0] * dimensions[largestIndex][1];
}


int main(void)
{
    int dimensionsSize = 2;
    int *dimensionsColSize;
    int **dimensions;
    int i;

    dimensionsColSize = malloc(dimensionsSize * sizeof(int));
    if (!dimensionsColSize)
    {
        //alloc fail
        return 1;
    }

    dimensions = malloc(dimensionsSize * sizeof(int*));
    if (!dimensions)
    {
        //alloc fail
        free(dimensionsColSize);
        return 1;
    }

    dimensions[0] = malloc(2 * sizeof(int));
    dimensions[0][0] = 3;
    dimensions[0][1] = 4;
    dimensionsColSize[0] = 2;

    dimensions[1] = malloc(2 * sizeof(int));
    dimensions[1][0] = 4;
    dimensions[1][1] = 3;
    dimensionsColSize[1] = 2;

    int result = areaOfMaxDiagonal(dimensions, dimensionsSize, dimensionsColSize);

    printf("%d\n", result);

    for (i = 0; i < dimensionsSize; i++)
    {
        free(dimensions[i]);
    }
    free(dimensions);
    free(dimensionsColSize);

    return 0;
}
