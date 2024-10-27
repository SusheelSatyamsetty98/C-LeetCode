#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int no_of_elements = 0;
int *list = NULL;

void create_linked_list()
{
    struct node *temp = NULL;
    struct node *newnode = NULL;

    for(int i = 0; i < no_of_elements; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode == NULL)
        {
            printf("Failed to create Memory for new node\n");
            return;
        }

        printf("\nEnter the Value: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        {
            temp = head = newnode;
        }
        else 
        {
            temp->next = newnode;
            temp = temp->next;
        }
    }

    printf("No of Elements: %d\n", no_of_elements);

    list = (int*)malloc(no_of_elements/2);
    
    return;
}

void display_linked_list()
{
    struct node *temp = head;

    for(int i = 0; i < no_of_elements; i++)
    {
        printf("Value: %d\n",temp->data);
        temp = temp->next;
    }

    return;
}

int get_max_twin_pair_from_linked_list()
{
    int max = 0;
    struct node *temp = head;
    int idx = 0;
    int i = 0;

    while(temp != NULL)
    {
        if(i < no_of_elements/2)
        {
            list[idx++] = temp->data;
            i++;
        }
        else
        {
            int sum = list[--idx] + temp->data;
            max = max > sum ? max : sum;   
        }

        temp = temp->next;
    }

    return max;
}

int main()
{
    int max = 0;

    printf("Enter no of elements: ");
    scanf("%d", &no_of_elements);

    if(no_of_elements%2 != 0)
    {
        printf("Enter a valid Even number\n");
        return -1;
    }

    create_linked_list();
#ifdef DEBUG_MODE
    display_linked_list();
#endif
    max = get_max_twin_pair_from_linked_list();
    printf("Max Twin Value : %d\n", max);

    return 0;
}