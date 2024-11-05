#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *h = NULL;

void ProductOfArrayExceptSelf(int no_of_elements, int* result)
{
    for(int i = 0; i < no_of_elements; i++)
    {
        int prod = 1;
        for(int j = 0; j < no_of_elements; j++)
        {
            if(i == j)
                continue;

            prod *= h[j];
        }
        result[i] = prod;
    }
}

int main()
{
    int no_of_elements = 0;
    int *result = NULL;

    printf("Total No of Elements you want to create");
    scanf("%d", &no_of_elements);

    h = (int*)malloc(no_of_elements);

    for (int i = 0; i < no_of_elements; i++)
        scanf("%d", &h[i]);

    result = (int*)malloc(no_of_elements);
    memset(result,1,no_of_elements);

    ProductOfArrayExceptSelf(no_of_elements, result);

    for(int i = 0; i < no_of_elements; i++)
        printf("%d - ", result[i]);

    free(h);
    free(result);

    return 0;
}
