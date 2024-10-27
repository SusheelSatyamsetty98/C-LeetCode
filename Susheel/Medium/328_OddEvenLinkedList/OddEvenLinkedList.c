#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int no_of_elements = 0;
int *even_list = NULL;
int *odd_list = NULL;
int even_idx = 0;
int odd_idx = 0;

void create_linked_list()
{
    struct node *temp = NULL;
    struct node *newnode = NULL;
    int choice = 0;

    do
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

        no_of_elements++;
        printf("\nDo you want to continue(0/1): ");
        scanf("%d",&choice);
    }while(choice); 

    printf("No of Elements: %d\n", no_of_elements);

    even_list = (int*)malloc(no_of_elements/2);
    odd_list = (int*)malloc(no_of_elements/2);
    
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

void get_even_odd_list()
{
    struct node *temp = NULL;
    bool is_even = true;

    if ((even_list == NULL) && (odd_list == NULL))
    {
        printf("Failed to Allocate the memory for Odd/Even list...exiting!!!");
        return;
    }

    temp = head;
    temp = temp->next; //Moving to 2nd node instead of from 1st node as 1 is odd no need to change the first postition

    while(temp != NULL)
    {
        if(is_even)
        {
            even_list[even_idx++] = temp->data;
        }
        else
        {
            odd_list[odd_idx++] = temp->data;
        }

        temp = temp->next;
        is_even = !(is_even);
    }

#ifdef DEBUG_MODE
    printf("EVEN : ");
    for(int i = 0; i < even_idx; i++)
    {
        printf("%d ",even_list[i]);
    }

    printf("\nODD : ");
    for(int i = 0; i < odd_idx; i++)
    {
        printf("%d ",odd_list[i]);
    }
#endif
    return;
}

void form_odd_even_linked_list()
{
    struct node *temp = head->next;

    for(int i = 0; i < odd_idx; i++)
    {
        temp->data = odd_list[i];
        temp = temp->next;
    }

    
    for(int i = 0; i < even_idx; i++)
    {
        temp->data = even_list[i];
        temp = temp->next;
    }

    display_linked_list();
    return;
}

int main()
{
    create_linked_list();

#ifdef DEBUG_MODE
    display_linked_list();
#endif

    get_even_odd_list();

    form_odd_even_linked_list();

    return 0;
}
