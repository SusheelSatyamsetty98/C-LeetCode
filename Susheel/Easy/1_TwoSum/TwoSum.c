#include <stdio.h>
#include <stdlib.h>

#define MAX 10

/*
 * @brief twoSum function is  responsible for checking in input any
 * two indexes are summing upto the targeted value.
 *
 * @params[in]: *a - stores the input data.
 *              numsSize - numsSizegth of the input data.
 *              target - specify the target value.
 * @params[out]: *b - stores the indexes of that accumilating to the target value.
 *
 * @return k > 0 in Success/ 0 in failure.
 *
 */
int twoSum(int *a, int numsSize, int target, int *b);

/*********** MAIN FUNCTION DEFINATION ***********/
int main(int argc, char **argv[])
{
  int a[MAX] = {0};
  int len = 0;
  int target = 0;

  printf("Enter Length : ");
  scanf("%d", &len);

  printf("Enter Target : ");
  scanf("%d", &target);

  for (int i = 0; i < len; i++)
  {
    printf("Enter data at Index : %d ...", i);
    scanf("%d", &a[i]);
  }

  int *b = (int *)malloc(2 * sizeof(int));
  int size = 0;
  b = twoSum(a, len, target, &size);
  if ((size > 0) && (b != NULL))
  {
  	for (int i = 0; i < size; i += 2)
  	{
    		printf("target Found in this Pairs size : %d - %d\n", b[i], b[i + 1]);
  	}
  }
  else
  {
    printf("Target Not Found in the List of Input\n");
  }

  free(b);
  return 0;
}

/*********** LOCAL FUNCTION DEFINATION ***********/
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
  int * list = NULL;
  for (int i = 0; i <= numsSize - 1; i++)
  {
    for (int j = i + 1; j < numsSize; j++)
    {
      if ((nums[i] + nums[j]) == target)
      {
        list = (int*)malloc(2 * sizeof(int));
        list[0] = i;
        list[1] = j;
		    *returnSize = 2;
        return list;
      }
    }
  }
  return list;
}
