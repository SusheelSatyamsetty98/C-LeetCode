#include <stdio.h>
#include <stdbool.h>

#define MAX 50

int s_len = 0;
int t_len = 0;

bool insert_delete(char *s, char *t,int len)
{
    char add_element;
    int j = 0;

    for (int i = 0; i < len;i++)
    {
        if(s[i] != t[j])
        {
            if (s[i+1] != t[j])
                return false;
            else
            {
                add_element = s[i];
            }
        }
        else {
            j++;
        }
    }

    printf("Need to insert/delete \'%c\' to make it same\n", add_element);
    return true;
}

bool replace(char *s, char *t)
{
    char s_element;
    char t_element;
    bool rc = true;

    for(int i = 0; i < s_len; i++)
    {
        if(s[i] != t[i])
        {
            s_element = s[i];
            t_element = t[i];
            if(s[i+1] != t[i+1])
                return false;
            else
                rc = true;
        }
        else
        {
            rc = false;
        }
    }
    
    printf("The \'%c\' Need to replaced with \'%c\' to make it same\n", s_element, t_element);

    return rc;
}

int main()
{
    char s[MAX] = {0};
    char t[MAX] = {0};
    bool res = false;

    printf("Enter s string: ");
    scanf("%s",s);

    
    printf("Enter t string: ");
    scanf("%s",t);

    while(s[++s_len] != '\0');
    while(t[++t_len] != '\0');

    if ((s_len == 0) || (t_len == 0))
    {
        printf("Not an One Edit Distance\n");
        return -1;
    }

    if (s_len == t_len)
    {
        res = replace(s,t);
    }
    else if (s_len > t_len)
    {
        insert_delete(s,t,s_len);
    }
    else if (s_len < t_len)
    {
        insert_delete(t,s,t_len);
    }

    if (res)
    {
        printf("It's One Edit Distance\n");
    }
    else
    {
        printf("Not an One Edit Distance\n");
    }
    return 0;
}
