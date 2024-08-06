#include <stdio.h>
#include <stdlib.h>

int find2ndGreatestNo(int *a, int len)
{
  int max[2] = {0};

 for(int i = 0; i < len; i++)
  {
    printf("%d - %d\n",i, a[i]);
  }


  max[0] = a[0] > a[1] ? a[0]: a[1]; 
  max[1] = a[0] < a[1] ? a[0]: a[1]; 

  for(int i = 2; i < len; i++)
  {
    int temp = a[i] > max[0] ? a[i] : max[0];

    if(temp > max[0])
    {
      max[1] = max[0];
      max[0] = temp;
    }
    else
    {
      temp = a[i] > max[1] ? a[i] : max[1];
      max[1] = temp;
    }
  }  

  return max[1];
}

int main()
{
  int *arr = NULL;
  int no_of_elements = 0;

  printf("Enter Max No of Elements:");
  scanf("%d", &no_of_elements);

  arr = (int*)malloc(no_of_elements);

  for(int i = 0; i < no_of_elements; i++)
  {
    scanf("%d", &arr[i]);
  }

   int max = find2ndGreatestNo(arr, no_of_elements);

  printf("Second Largest No: %d",max);


  return 0;
}
