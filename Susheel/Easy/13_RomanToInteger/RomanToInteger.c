#include<stdint.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_RAMAN_STR_LEN 10

/*
 * @brief RomanToInt function responsible for converting the 
 * string input to the interger value.
 *
 * @params[in]: *in - Stores the roman string entered by user.
 *              in_len- Length of the string.
 *
 * @returns - Roman value in Success/ -1 in failure.
 *
 */
int RomanToInt(char* in,int in_len);

/*
 * @brief RomanVal responsible to send the roman equvalent value to
 * specific character.
 *
 * @params[in]: ch - stores the character value.
 *
 * @returns - Roman value of the character/ 0 in failure.
 *
 */

int RomanVal(char ch);

/*********** MAIN FUNCTION DEFINATION ***********/
int main(char**argv, char* argc)
{
  char *input = NULL;
  int res = 0;

  input = (char*)malloc(MAX_RAMAN_STR_LEN);

  printf("Enter the Roman in CAPITAL Letters: ");
  scanf("%s",input);

  res = RomanToInt(input,strlen(input));
  
  printf("\nEntered Roman is :%s It equivalent Number is : %d\n",input, res);

  free(input);

  return 0;
}

/*********** LOCAL FUNCTION DEFINATION ***********/
int RomanVal(char ch)
{
  if (ch=='I') return 1;
  else if (ch== 'V') return 5;
  else if (ch=='X') return 10;
  else if (ch=='L') return 50;
  else if (ch=='C') return 100;
  else if (ch=='D') return 500;
  else if (ch=='M') return 1000;
  else return 0;
}

int RomanToInt(char* in,int in_len)
{
  int num = 0;
  int current_idx_value = 0;
  int next_idx_value = 0;

  if(in_len <= 0)
  {
    return -1;
  }

  for (uint8_t i = 0; i <= in_len; i++)
  {
    current_idx_value = RomanVal(in[i]);
    next_idx_value = RomanVal(in[i+1]);
    
    if(current_idx_value < next_idx_value)
    {
      num -= current_idx_value;
    }
    else
    {
      num += current_idx_value;
    }
  }

  return num;
}

