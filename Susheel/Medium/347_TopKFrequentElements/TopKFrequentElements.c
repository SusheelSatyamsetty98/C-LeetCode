// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int *output = NULL;

int comparision(const void* num1, const void* num2)
{
	return(*(int*)num1 - *(int*)num2); // num1 - num2 gives descending order
}

int* topFreqListFn(int *nums, int numsSize, int k, int* returnSize)
{
    output = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    bool isValFound = false;
    int idx = 0;

	qsort(nums,numsSize,sizeof(int),comparision);
	
	for(int i = 0; i < numsSize; i++)
	{
		if(nums[i] == nums[i+1])
        {
            count++;
        }
        else
        {
            count = 1;
        }

        if(count == k)
        {
            output[idx++] = nums[i];
        }
	}

    if(*returnSize < numsSize)
    {
        int new_size = idx * sizeof(int);
        int *temp = realloc(output, new_size);
        output = temp;
    }

    *returnSize = idx;
    return output;
}

int main() {
    int numsSize = 0;
    int *nums = NULL;
    int returnSize = 0;
    int k = 0;
   
    scanf("%d", &numsSize);
   
    nums = (int*)malloc(numsSize * sizeof(int));
    
    for(int i = 0; i < numsSize; i++)
    {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &k);
   
    output = topFreqListFn(nums, numsSize, k, &returnSize);    

    for(int i = 0; i < returnSize; i++)
    {
        printf("%d ", output[i]);
    }
    printf("\n");

    free(output);
    free(nums);
    return 0;
}