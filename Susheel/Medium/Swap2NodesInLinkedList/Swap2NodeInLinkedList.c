#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct swapNode {
    struct node *previousNode;
    struct node *currentNode;
    struct node *nextNode;
};

struct swapNode swap[2];

void create_linked_list()
{
    struct node *newnode = NULL;
    struct node *temp = NULL;
    int choice = 1;

    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter the Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }

        printf("Do you want to continue(0/1) : ");
        scanf("%d", &choice);
    }

    return;
}

void display_linked_list()
{
    struct node *temp = head;
    int i = 1;

    while(temp != NULL)
    {
        printf("%d Data is : %p - %d\n",i,temp,temp->data);
        temp = temp->next;
        i++;
    }

    return;
}

int cal_len_of_linked_list()
{
    struct node *temp = head;
    int len = 0;

    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    
    return len;
}
#if 0
void traverse_ll_to_store_node_data(int *node_list)
{
    struct node *temp = head;
    int itr = 0;
    int pos = 0;
    // int ll_len = cal_len_of_linked_list();

    if (node_list[0] == 0)
    {
        swap[pos].previousNode = NULL;
    }
    else
    {
        while (itr < node_list[0] - 1)
        {
            temp = temp->next;
            itr++;
        }
        swap[pos].previousNode = temp;
        temp = temp->next;
        itr++;
    }

    swap[pos].currentNode = (struct node*)malloc(sizeof(struct node));
    swap[pos].currentNode->data = temp->data;
    swap[pos].currentNode->next = temp;
    temp = temp->next;
    itr++;
    swap[pos++].nextNode = temp;

    if((node_list[1] - 1) != itr)
    {
        while (itr < node_list[1] - 1)
        {
            temp = temp->next;
            itr++;
        }
    }        
    
    swap[pos].previousNode = temp;
    temp = temp->next;
    swap[pos].currentNode = (struct node*)malloc(sizeof(struct node));
    swap[pos].currentNode->data = temp->data;
    swap[pos].currentNode->next = temp;
    temp = temp->next;
    swap[pos].nextNode = temp;

    for(int i = 0; i < 2; i++)
    {
        printf("--------------------------------------------------------\n");
        printf("swap[%d].previousNode %p\n",i,swap[i].previousNode);
        printf("swap[%d].currentNode->data %d\n",i,swap[i].currentNode->data);
        printf("swap[%d].currentNode->next %p\n",i,swap[i].currentNode->next);
        printf("swap[%d].nextNode %p\n",i,swap[i].nextNode);
        printf("--------------------------------------------------------\n");
    }

    return;
}
#endif

void traverse_ll_to_store_node_data(int *node_list)
{
    int pos = 0;
    int itr = 0;
    struct node *temp = head;

    if (node_list[pos] == 0)
    {
        swap[pos].previousNode = NULL;
    }
    else
    {
        while(itr <= (node_list[0] - 1))
        {
            temp = temp->next;
            swap[pos].previousNode = temp;
            itr++;
        }
        
        // swap[pos].previousNode = temp;
        // temp = temp->next;
        // itr++;
    }

    swap[pos].currentNode = (struct node*)malloc(sizeof(struct node));
    swap[pos].currentNode->data = temp->data;
    swap[pos].currentNode->next = temp;         //Storing self address
    swap[pos].nextNode = temp->next;
    pos++;

    while(itr <= (node_list[pos] - 1))
    {
        temp = temp->next;
        swap[pos].previousNode = temp;
        itr++;
    }

    // swap[pos].previousNode = temp;
    // temp = temp->next;
    // itr++;
    swap[pos].currentNode = (struct node*)malloc(sizeof(struct node));
    swap[pos].currentNode->data = temp->data;
    swap[pos].currentNode->next = temp;
    swap[pos].nextNode = temp->next;

    for(int i = 0; i < 2; i++)
    {
        printf("--------------------------------------------------------\n");
        printf("swap[%d].previousNode %p\n",i,swap[i].previousNode);
        printf("swap[%d].currentNode->data %d\n",i,swap[i].currentNode->data);
        printf("swap[%d].currentNode->next %p\n",i,swap[i].currentNode->next);
        printf("swap[%d].nextNode %p\n",i,swap[i].nextNode);
        printf("--------------------------------------------------------\n");
    } 

    return;
}

void swap_nodes_linked_list()
{
    struct node *temp = head;
    int ll_len = 0;
    int node_list[2] = {0};
    int itr = 0 ;
    int pos = 1;
    
    ll_len = cal_len_of_linked_list();

    if (ll_len <= 1)
    {
        printf("No sufficient nodes to swap");
        return;
    }

    printf("which 2 node you want to swap between 0-%d", ll_len);
    scanf("%d", &node_list[0]);
    scanf("%d", &node_list[1]);

    if (node_list[0] > node_list[1])
    {
        /* If node[0] is greater than node[1] swapping the nodes */
        node_list[0] = node_list[0] + node_list[1];
        node_list[1] = node_list[0] - node_list[1];
        node_list[0] = node_list[0] - node_list[1];
    }

    traverse_ll_to_store_node_data(node_list);

    if (node_list[0] > 0)
    {
        while(itr < (node_list[0] - 1))
        {
            temp = temp->next;
            itr++;
        }
    }

    temp->next = swap[pos].currentNode->next;
    temp = temp->next;
    itr++;
    
    temp->data = swap[pos].currentNode->data;
    temp->next = swap[--pos].nextNode;

    while(itr < node_list[1] - 1)
    {
        temp = temp->next;
        itr++;
    }

    temp->next = swap[pos].currentNode->next;
    temp = temp->next;
    itr++;
    temp->data = swap[pos].currentNode->data;
    // if (itr == ll_len)
    // {
    //     temp->next = NULL;
    // }
    // else
    // {
        temp->next = swap[++pos].nextNode;
    // }

    if(node_list[0] == 0)
    {
        head = swap[pos].currentNode->next;
    }
        //TODO: Bug - Not working when trying to swap the head with another node. Need to Fix it
#if 0
    if (node_list[0] == 0)
    {
        // head  = swap[pos].currentNode->next;
        temp->data = swap[pos].currentNode->data;
        temp->next = swap[pos - 1].nextNode;
    }
    else
    {
        while (itr < node_list[0] - 1)
        {
            temp = temp->next;
            itr++;
        }

        temp->next = swap[pos].currentNode->next;
        temp = temp->next;
        itr++;
        temp->data = swap[pos].currentNode->data;
        temp->next = swap[--pos].nextNode;
    }


    while (itr < node_list[1] - 1)
    {
        temp = temp->next;
        itr++;
    }

    temp->next = swap[pos].currentNode->next;
    temp = temp->next;
    itr++;
    temp->data = swap[pos].currentNode->data;
    if (itr == ll_len)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = swap[++pos].nextNode;
    }
#endif
}

int main()
{
    create_linked_list();
// #ifdef DEBUG_MODE
    display_linked_list();
// #endif

    swap_nodes_linked_list();
    printf("After\n");
// #ifdef DEBUG_MODE
    display_linked_list();
// #endif    
    return 0;
}
