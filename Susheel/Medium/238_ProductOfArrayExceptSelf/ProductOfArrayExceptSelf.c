#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* ProductOfArrayExceptSelf(int *nums, int numsSize, int *returnsSize)
{
    int *result = (int*)malloc(numsSize * sizeof(int));
    int *zeroidxList = NULL;
    int zeroidxCount = 0;
    int prod = 1;

    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0)
        {
            prod *= nums[i];
        }
        else
        {
            if(zeroidxList == NULL)
            {
                zeroidxList = (int*)malloc(2 * sizeof(int));
            }

            zeroidxList[zeroidxCount++] = i;
            
            if(zeroidxCount == 2)
            {
                memset(result,0, numsSize * sizeof(int));
                *returnSize = numsSize;
                return result;
            }

            prod *= 1;
        }
    }

    if ((zeroidxList != NULL) && (zeroidxCount == 1))
    {
        memset(result,0, numsSize * sizeof(int));
        result[zeroidxList[0]] = prod;
    }
    else
    {
        for(int i = 0; i < numsSize ; i++)
        {
            result[i] = prod / nums[i];
        }
    }

    *returnSize = numsSize;
    return result;
}

int main()
{
    int numsSize = 0;
    int *result = NULL;
    int returnsSize = 0;

    printf("Total No of Elements you want to create");
    scanf("%d", &numsSize);

    int* nums = (int*)malloc(numsSize);

    for (int i = 0; i < numsSize; i++)
        scanf("%d", &nums[i]);

    result = ProductOfArrayExceptSelf(nums, numsSize, &returnsSize);

    for(int i = 0; i < returnsSize; i++)
        printf("%d ", result[i]);

    free(result);

    return 0;
}
