#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PARENTHESES_INDEX 4

/*
 * @brief is_validParenthese function is responsible for checking whether the
 * input is valid parenthese or not.
 *
 * @params[in]: *ch - Stores the input 
 *              len - length of the input.
 *
 * @returns: true in Success/ false in failure
 *
 */
bool is_validParenthese(char* in, int len);

/*
 * @brief parentheseIndex function is responsible for sending the parentheses
 * respective index which are predefined.
 *
 * @params[in]: ch - store the ch that specify the parentheses
 *
 * @return: Index of the parentheses in success /-1 in failure.
 *
 */
int parentheseIndex(char ch);

int main(char** argv, char*argc)
{
  char *input = NULL;
  bool res = false;

  input = (char*)malloc(10);

  printf("Enter the String with these mentioned '(',')','['']' or '{''}' parenthese:");
  scanf("%s", input);
  
  res = is_validParenthese(input, strlen(input));

  (res == true) ? printf("Entered String :%s has Valid Parentheses\n", input) : printf("Enterned String %s has No Valid Parentheses\n", input);

  free(input);
  return 0;
}

bool is_validParenthese(char* in, int len)
{
  uint8_t res[MAX_PARENTHESES_INDEX] = {0};
  bool rc = false;

  for (uint8_t i = 0; i < len; i++)
  {
    uint8_t idx = parentheseIndex(in[i]);
    if (idx > 0)
    {
      uint8_t temp = res[idx];
      temp += 1;
      res[idx] = temp;
    }
  }

  for(uint8_t i = 0; i < MAX_PARENTHESES_INDEX; i++)
  {
    if((res[i] % 2) == 0)
    {
      rc = true;
    }
    else
    {
      rc = false;
      break;
    }
  }

  return rc;
}

int parentheseIndex(char ch)
{
  if((ch == '(') || (ch == ')')) return 1;
  else if((ch == '[') || (ch == ']')) return 2;
  else if((ch == '{') || (ch == '}')) return 3;
  else return 0;
}
