#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <string.h>

#define MAX_ALPHABETS 26

char sCount[MAX_ALPHABETS] = {0};
char tCount[MAX_ALPHABETS] = {0};
int max = 0;

void updateCountInList(char ch, bool isSList)
{
	int idx = 0;
	int temp = 0;

	if(ch > 'a' && ch < 'z')
	{
		idx = ch - 'a';
	}
	else if (ch > 'A' && ch < 'Z')
	{
		idx = ch - 'A';
	}

	max = (max > idx) ? max : idx;
	if(isSList)
	{
		temp = sCount[idx];
		temp += 1;
		sCount[idx] = temp;
	}
	else
	{
		temp = tCount[idx];
		temp += 1;
		tCount[idx] = temp;
	}
}

bool validAnagram(char *s, char* t)
{
	int s_len = strlen(s);
	int t_len = strlen(t);
	int isFound = 0;

	if((s_len <= 0) || (t_len <= 0) || (s_len != t_len))
	{
		return false;
	}

	//Both Lengths needs to be same so selecting either of len
	for(int i = 0; i < s_len; i++)
	{
		updateCountInList(s[i],true);
		updateCountInList(t[i],false);
	}

	for(int i = 0; i < max; i++)
	{
		if(sCount[i] != tCount[i])
		{
			return false;
		}
		else
		{
			if(sCount > 0)
			{
				isFound++;
				if(isFound == s_len)
				{
					return true;
				}
			}
		}
	}
}

int main()
{
	char *s = NULL;
	char *t = NULL;

	s = (char*)malloc(10 * sizeof(char));
	t = (char*)malloc(10 * sizeof(char));

	printf("\nS - String : ");
	scanf("%s",s);

	printf("\nT - String : ");
	scanf("%s",t);

	bool res = validAnagram(s, t);

	printf("Is Duplicate(0-False/1-True): %d\n", res);
	
	return 0;
}
