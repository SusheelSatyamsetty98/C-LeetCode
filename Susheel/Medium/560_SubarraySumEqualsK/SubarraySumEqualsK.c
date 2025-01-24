#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int subarraySum(int *nums, int numsSize,int k)
{
	int res = 0;

	for(int i = 0; i <= numsSize - 1; i++)
	{		
		if (nums[i] == k)
		{
			res++;
		}
		
		int sum = nums[i];
		for(int j = i+1; j < numsSize; j++)
		{
			if (sum + nums[j] == k)
			{
				res++;
			}
			sum += nums[j];
		}
	}
	return res;
}

int main()
{
	int numsSize =0;
	int k =0;
	int *nums = NULL;

	scanf("%d",&numsSize);

	nums = (int*)malloc(numsSize * sizeof(int));

	for(int i = 0; i < numsSize; i++)
		scanf("%d", &nums[i]);

	scanf("%d",&k);

	int res = subarraySum(nums, numsSize,k);

	printf("Max Formed Array's are: %d\n", res);
	
	return 0;
}
