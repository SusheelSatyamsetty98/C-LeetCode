#include <stdio.h>
#include <stdlib.h>

int *h = NULL;

void contain_max_water(int start, int end, int *max_area)
{
    int height = (h[start] <= h[end]) ? h[start] : h[end];

    int area = height * (end - start);
    *max_area = *max_area > area ? *max_area : area;

#ifdef DEBUG_MODE    
    printf("Height: %d Width: %d Prod: %d\n",height,(end-start), area);
#endif

    (h[start] == height) ? start ++ : end--;

    if((end - start) == 0)
        return;

    contain_max_water(start, end, max_area);
}

int main()
{
    int no_of_elements = 0;
    int max =  0;

    printf("Total No of Elements you want to create");
    scanf("%d", &no_of_elements);

    h = (int*)malloc(no_of_elements);

    for (int i = 0; i < no_of_elements; i++)
        scanf("%d", &h[i]);

    contain_max_water(0, no_of_elements - 1,&max);

    printf("MAX Area it can contain is : %d\n", max);

    free(h);

    return 0;
}