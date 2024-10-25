#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char *in;
    fgets(in, 100, stdin);
    printf("%s",in);
    return 0;
}