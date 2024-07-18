#include <ctype.h>
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int top = -1;
char *stack = NULL;

void push(char ch)
{
  stack[++top] = ch;
  return;
}

void pop(char *ch)
{
  *ch = stack[top--];
  return;
}

bool isStackEmpty()
{
  return (top == -1) ? true : false;
}

bool isStackFull(int len)
{
  // len - Length of String
  return (top == (len - 1)) ? true : false;
}

void stringReverse()
{
  char str[32];

  memset(&str,0,32);
  printf("Enter String: ");
  fgets(str,sizeof(str),stdin);
  printf("%s",str);

  stack = (char*)malloc(strlen(str));

  int len  = 0;
  while(str[len++] != '\0')
  {
  }

  for(int i = 0; i < len; i++)
  {
    if(isspace(str[i])) 
    {
      int temp_len = top;
      int j; 
      for(int k = 0,j = (i-(temp_len + 1)); k <= temp_len; j++,k++)
      {
        pop(&str[j]);
      }
    }
    else
    {
      push(str[i]);
    }
  }

  printf("Reverse String: [%s]\n",str);

  return;
}

int main() {
  // Write C code here

  stringReverse();
  printf("Try programiz.pro");

  if(stack)
    free(stack);

  return 0;
}
