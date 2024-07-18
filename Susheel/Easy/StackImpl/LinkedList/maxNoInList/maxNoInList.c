#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
  int data;
  struct node* next;
};

struct node* head = NULL;

void displayLinkedList()
{
  struct node *temp = head;
  
  while(temp != NULL)
  {
    printf("Data is :%d\n",temp->data);
    temp = temp->next;
  }
}

void maxNoInList(int* max_no)
{
  struct node* newnode = NULL;
  int choice = 1;

  do
  {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);

    if (newnode->data > *max_no)
    {
      *max_no = newnode->data;
    } 

    newnode->next = head;
    head = newnode;

    printf("Do you want to continue(0/1): ");
    scanf("%d",&choice);
  }while(choice);

  displayLinkedList();

  return;
}

int main()
{
  int max_no = 0;
  maxNoInList(&max_no);

  printf("Max no is : %d", max_no);
  return 0;
}
