#include <stdio.h>

#define MAX 50

int main()
{
    int a[MAX] = {0};
    int no_of_elements = 0;
    int target = 0;
    int position = 0;

    printf("Enter no of elements: ");
    scanf("%d", &no_of_elements);

    for(int i = 0; i < no_of_elements; i++)
    {
        scanf("%d", &a[i]);
    }
    
    target = a[0];
    for(int i = 0; i < no_of_elements - 1; i++)
    {
        for(int j = i+1; j < no_of_elements; j++)
        {
            if(a[i] > a[j])
            {
                a[i] = a[j] + a[i];
                a[j] = a[i] - a[j];
                a[i] = a[i] - a[j];
            }
        }
        /* a[i] holds the target, saying because for every swap the a[i] will get updated. target is at 0th index. 
        * When a[i] gets updated we need to update the position
        * Eg: [3, 4, 5, 1, 2]
        * target = 3;
        * for i = 0: j rotates from 1 to no_of_elements
        * j = 1:    3 > 4 - No swap Req - Arr: [3, 4, 5, 1, 2] Pos: 0
        * j = 2:    3 > 5 - No swap Req - Arr: [3, 4, 5, 1, 2] Pos: 0
        * j = 3:    3 > 1 - swap Req - Arr: [1, 4, 5, 3, 2] Pos: 3
        * j = 4:    1 > 2 - No swap Req - Arr: [1, 4, 5, 3, 2] Pos: 3
        
        * for i = 1: j rotates from 2 to no_of_elements
        * j = 2:    4 > 5 - No swap Req - Arr: [1, 4, 5, 3, 2] Pos: 3
        * j = 3:    4 > 3 - swap Req - Arr: [1, 3, 5, 4, 2] Pos: 2
        * j = 4:    3 > 2 - swap Req - Arr: [1, 2, 5, 4, 3] Pos: 4

        * for i = 2: j rotates from 3 to no_of_elements
        * j = 3:    5 > 4 - swap Req - Arr: [1, 2, 4, 5, 3] Pos: 4
        * j = 4:    4 > 3 - swap Req - Arr: [1, 2, 3, 5, 4] Pos: 3
        
        * for i = 3: j rotates from 4 to no_of_elements
        * j = 4:    5 > 4 - swap Req - Arr: [1, 2, 3, 4, 5] Pos: 3
        Note: Pos is index, to get Pos = index + 1
        */
        if((a[i] == target))
            position = i + 1;
    }

    // If Pos = 1 that means it's has to complete one rotate(i.e., length of the array) to get back to it's original position 
    if (position == 1)
        position = no_of_elements;

    printf("Position Value: %d\n",position);

    return 0;
}
