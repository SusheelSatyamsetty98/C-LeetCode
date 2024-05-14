#include <stdint.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * @brief longest_common_prefix function is responsible for detemining whether
 * input strings has common prefix among them if so it will return that common
 * prefix, if doesn't match with one among them it will return empty string.
 *
 * @params[in]: *in - Contains the list of the strings.
 *              in_len - Holds the length of the input string.
 * @params[out]: *out - Common prefix if have something in common case of Success/
 *                      Empyt in case of failure.
 *
 * @returns: > 0 in Success/ 0 in Failure.
 *
 */
uint8_t longest_common_prefix(char** in, int in_len, char* out);

int main(char**argv, char*argc)
{
  char* input[10];
  char* temp = NULL;
  uint8_t no_of_strings = 0;
  char* prefix = NULL;
  uint8_t outlen = 0;

  printf("Enter No of String List: ");
  scanf("%hhd", &no_of_strings);

  temp = (char*)malloc(10);
  prefix = (char*)malloc(10);

  for(uint8_t i = 0; i < no_of_strings; i++)
  {
    memset(temp,0, sizeof(temp));

    printf("Enter String:");
    scanf("%s",temp);

    uint8_t len = sizeof(temp);
    input[i] = (char*)malloc(len);

    memcpy(input[i] ,temp, len);
  }

  outlen = longest_common_prefix(input, no_of_strings, prefix);

  (outlen > 0) ? printf("Common Prefix among the strings is %s", prefix) : printf("There is no common prefix among the input strings");
  
  free(temp);
  free(prefix);
  return 0;
}

int min(int a, int b)
{
  return (a > b) ? b : a;
}

uint8_t longest_common_prefix(char** in, int in_len, char* out)
{
  uint8_t out_len = 0;
  uint8_t min_len = strlen(in[0]);

  for(uint8_t i = 1; i < in_len; i++)
  {
    min_len = min(min_len, strlen(in[i]));
  }
  
  for(uint8_t i = 0; i < min_len; i++)
  {
    char ch = in[0][i];
    for(uint8_t j = 1; j < in_len; j++)
    {
      if (in[j][i] != ch)
      {
        out[out_len] = '\0';
        return out_len;
      }

    }
    out[out_len++] = ch;
  }

  out[out_len] = '\0';
  return out_len;
}
