#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
  int data;
  struct node* next;
};

struct node* head = NULL;
struct node* top = NULL;

void displayLinkedList()
{
  struct node *temp = head;
  
  while(temp != NULL)
  {
    printf("Data is :%d\n",temp->data);
    temp = temp->next;
  }
}


void createLinkedList()
{
  struct node* temp = NULL;
  struct node* newnode = NULL;
  struct node *newStacknode = NULL;
  int choice = 1;

  do
  {
    newnode = (struct node*)malloc(sizeof(struct node));
    newStacknode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter the Data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    if(head == NULL)
    {
      head = temp = newnode;
    }
    else {
      temp->next = newnode;
      temp = temp->next;
    }
    
    newStacknode->data = newnode->data;
    newStacknode->next = top;
    top = newStacknode;
    
    printf("\nDo you want to continue(0/1): ");
    scanf("%d", &choice); 
  }while(choice);

  return;
}

bool isPalindrome()
{
  struct node *temp = head;
  struct node *temp2 = top;

  createLinkedList();

  while(temp != NULL)
  {
    if(temp2->data == temp->data)
    {
      temp = temp->next;
      temp2 = temp2->next;
    }
    else
    {
      return false;
    }
  }
  
  return true;
}

int main()
{
  bool result = isPalindrome();

  if (result == true) 
    printf("Entered List are Palindrome"); 
  else
    printf("Entered List are Not Palindrome");

  return 0;
}
