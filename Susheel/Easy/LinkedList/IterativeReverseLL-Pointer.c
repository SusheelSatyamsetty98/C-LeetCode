#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct node
{
  int data;
  struct node *next;
};


void createLinkedList(struct node* head);
int lengthOfLinkedList(struct node* head);
void insertNodeToList(struct node *head, int pos);
void displayLinkedList(struct node *head);
void reverseLinkedList(struct node **head);


void reverseLinkedList(struct node **head)
{
  struct node *current = *head;
  struct node *next = NULL;
  struct node *previous = NULL;

  while(current != NULL)
  {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  *head = previous;

  return;
}

void insertNodeToList(struct node *head, int pos)
{
  int idx = 0;
  struct node *temp;
  struct node *start;

  start = head;

  temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter the value you want to insert: ");
  scanf("%d", &temp->data);
  temp->next = NULL;
  
  if (pos <= 1)
  {
    temp->next = head;
    head = temp;
  }
  else 
  {
    while(idx < (pos - 1))
    {
      start = start->next;
      idx++;
    }

    temp->next = start->next;
    start->next = temp;
  }


  printf("**********Data After Insertion******************\n");
  displayLinkedList(head);
  lengthOfLinkedList(head);
  printf("*************************************************\n");

  reverseLinkedList(&head);

  printf("**********Data After Reverse******************\n");
  displayLinkedList(head);
  lengthOfLinkedList(head);
  printf("*************************************************\n");

  if(temp)
    free(temp);
}

int lengthOfLinkedList(struct node* head)
{
  int count = 0;
  while(head != NULL)
  {
    head = head->next;
    count++;
  }

  printf("Length of the List is : %d\n",count);

  return count;
}

void displayLinkedList(struct node *head)
{
  uint8_t idx = 0;
  while(head != NULL)
  {
    printf("Data is at %d is %d \n",idx,head->data);
    head = head->next;
    idx++;
  }
  return;
}

void createLinkedList(struct node* head)
{
  struct node *temp, *newnode;
  int choice = 0;

  printf("Do you want to create a Linked List (1/0) : ");
  scanf("%d",&choice);

  while(choice)
  {
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode)
    {
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
        temp = newnode;
      }
      
    }

    printf("Do you want to continue (1/0) :");
    scanf("%d",&choice);
  }
  

  displayLinkedList(head);

  bool is_insert = false;
  uint8_t pos = 0;
  uint8_t val = 0;

  printf("Do you want to insert a Node(0/1): ");
  scanf("%d", &is_insert);

  if(is_insert)
  {
    uint8_t len = lengthOfLinkedList(head);
    printf("Enter the Position from (0-%d) you want to Insert a node: ", len);
    scanf("%d",&pos);

    if(pos < len)
    {
      printf("Enter an Invalid Position : %d ", pos);
      return 1;
    }

    insertNodeToList(head,pos);
  }

  if(newnode)
   free(newnode);

  return;
}

int main()
{
  struct node *head1;
  createLinkedList(head1);

  return 0;
}
