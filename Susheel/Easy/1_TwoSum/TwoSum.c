#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int twoSum(int *a, int len, int target, int *b)
{
  int k = 0;
  for (int i = 0; i <= len - 1; i++)
  {
    for (int j = i + 1; j <= len; j++)
    {
      if ((a[i] + a[j]) == target)
      {
        b[k++] = i;
        b[k] = j;
        k++;
      }
    }
  }

  return k;
}

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

  int *b = (int *)malloc(len);
  int size = twoSum(a, len, target, b);
  if (size > 0)
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
