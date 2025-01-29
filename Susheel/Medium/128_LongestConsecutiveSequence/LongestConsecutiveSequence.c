#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* num1, const void* num2)
{
    return (*(int*)num1 - *(int*)num2);
}

int longestConsecutive(int* nums, int numsSize) {
    int max = 0;
    int returnSize = 1;

    if(numsSize <= 0)
    {
        return 0;
    }
    else if(numsSize <= 1)
    {
        return 1;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    for(int i = 0; i < numsSize - 1; i++)
    {
        if(nums[i] + 1 == nums[i+1])
        {
            returnSize++;
        }
        else if (nums[i] == nums[i+1])
        {
            continue;
        }
        else
        {
            max = (max > returnSize) ? max : returnSize;
            returnSize = 1;
        }
    }

    max = (max > returnSize) ? max : returnSize;
    return max;    
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

    returnsSize = longestConsecutive(nums, numsSize);

    printf("returnsSize : %d\n", returnsSize);

    free(result);

    return 0;
}