#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int no_of_elements = 0;

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

void delete_n_node_after_m_node(int n, int m)
{
    struct node *temp = head;
    struct node *connect_node = head;
    struct node *list_to_delete = NULL;


    /* Eg: 1->2->3->4->5->6
    * If n = 2, m =2:
    *   temp = head, connect_node = head;    
    *    for n = 2 traversing the temp and connect node till n-1 positions (i.e, now @ position-1)
    *   at this point temp and connect_node is pointing at temp->data = 2 
    *   temp node has to move to the next position to reach the node it has to delete (i.e., temp->data =3)
    *   for m = 2, the list_to_delete holds first the address of temp->data = 3 node  and temp will move to next node
    *       (i.e., temp->data = 4) and free up the memory of temp->data =3 node. After looping for m types
    *   temp now at temp->data = 5 node. the connect_node current position is @ temp->data = 2.
    *   to the connect_node->next add the address of temp->data =5.*/
    for(int i = 0; i < n - 1; i++)
    {
        temp = temp->next;
        connect_node = connect_node->next;
    }
    
    // This move will point to the node which need to get delete
    temp = temp->next;

    for(int i = 0; i < m; i++)
    {
        list_to_delete = temp;
        temp = temp->next; 
        free(list_to_delete);   
    }

    connect_node->next = temp;
    no_of_elements -= m;
}

int main()
{
    int n, m;

    create_linked_list();
#ifdef DEBUG_MODE
    display_linked_list();
#endif

    printf("After how many position you want to delete: ");
    scanf("%d", &m);

    printf("How many nodes you want to delete?");
    scanf("%d", &n);

    //TODO: Need to handle the negative test cases
    //Need to some modifications

    delete_n_node_after_m_node(n,m);
    display_linked_list();

    return 0;
}
