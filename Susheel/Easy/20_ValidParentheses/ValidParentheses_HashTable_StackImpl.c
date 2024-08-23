#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdbool.h"

#define MAX 3

char hashTable[MAX];
char stack[10];
int top = -1;

int closePramasMap(char s)
{
  switch(s)
  {
    case ')' : return 1;              
    case '}' : return 2;              
    case ']' : return 3;              
  }
}

int paramMap(char s)
{
  switch(s)
  {
    case '(' : hashTable[1] = ')'; return 1;
    case '{' : hashTable[2] = '}'; return 2;
    case '[' : hashTable[3] = ']'; return 3;
    default: return 0;
  }
}

bool validParam(char* str)
{
  for (int i = 0; i < strlen(str); i++)
  {
    char s = str[i];
    int idx = paramMap(s);

    if (idx > 0)
    {
      stack[++top] = hashTable[idx];
    }
    else
    {
      int j = closePramasMap(s);
      if( (stack[top] != hashTable[j]))
        return false;
      else
        {
          top--;
          
        }
    }
  }
  if (top == -1) 
    return true;
}

int main(int argc, char** argv[])
{
  char *str = NULL;

  str = (char*)malloc(10);

  printf("Enter Test param pattern: ");
  scanf("%s", str);

  bool rc = validParam(str);
  (rc == true) ? printf("Valid Params") : printf("Invalid Params");

  return 0;
}
