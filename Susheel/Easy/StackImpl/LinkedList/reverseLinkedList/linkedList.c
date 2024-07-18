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

void reverseLinkedList()
{
  struct node* newnode = NULL;
  int choice = 1;

  do
  {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);
    
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
  reverseLinkedList();
  return 0;
}
