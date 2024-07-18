#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
 
char* replaceSmallWithCapitalVV(char* input)
{
  int k = 0;
  char *output = (char*)malloc(strlen(input));

  printf("Input Str: %s\n", input);

  for(int i = 0; i < strlen(input); i++)
  {
    if(input[i] >= 'a' && input[i] <= 'z')
    {
      output[k++] = 'a' - 32 + (input[i] - 'a');
    }
    else if(input[i] >= 'A' && input[i] <= 'Z')
    {
      output[k++] = 'A' + 32 + (input[i] - 'A');
    }
  }

  return output;
}
 
int main()
{
  char *input = NULL;
  char *output = NULL;

  input = (char*)malloc(10);
  output = (char*)malloc(10);

  printf("Enter Input: ");
  scanf("%s",input);

  output = replaceSmallWithCapitalVV(input);

  printf("Output: %s\n", output);

  return 0;
}
