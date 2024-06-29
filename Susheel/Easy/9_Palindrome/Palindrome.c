#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_DIGIT_LEN 10

/*
 * @brief is_Palindriome function responsible for checking whether the
 * input value is a palindrome or not.
 *
 * @params[in]: num - store the input value,
 *
 * @returns true - Success/ false - Failue.
 *
 */
bool is_Palindriome(int num);

/*********** MAIN FUNCTION DEFINATION ***********/
int main(char **argv, char* argc)
{
    int num = 0;
    bool result = false;

    printf("Enter No: ");
    scanf("%d", &num);

    result = is_Palindriome(num);
    
    (result == true) ? printf("\n%d is a Palindrome\n",num) : printf("\n%d is not a Palindrome\n",num);

	return 0;
}

/*********** LOCAL FUNCTION DEFINATION ***********/
bool is_Palindriome(int num)
{
  int temp = num;
  unsigned int res = 0;
  uint8_t len = 0;
  char* ch = NULL;
  bool rc = false;

  if (num > 0) 
  {
    ch = (char*)malloc(MAX_DIGIT_LEN);
    sprintf(ch,"%d",num);
    len = strlen(ch);

    while(len > 0)
    {
      int temp1 = temp % 10;
      res = (res * 10 ) + temp1;
      temp = temp/10;
      len--;
    }
    
    if (res == num)
    {
      rc = true;
    }
    
    free(ch);
  }

  return rc;
}
