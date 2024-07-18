#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

/*
 * @brief */
void merger2List(struct node* list1, struct node* list2, struct node** result);

void merger2List(struct node* list1, struct node* list2, struct node** result)
{
  struct node *temp = *result;
  struct node *current_2 = list2;
  struct node *current_1 = list1;


  while(current_1 != NULL && current_2 != NULL)
  {
    temp = current_1;
    current_1 = current_1->next;
    temp = temp->next;
    temp = current_2;
    current_2 = current_2->next;
    temp = temp->next;

  }

  if(list1 != NULL)
  {
    temp = list1;
  }
  if(list2 != NULL)
  {
    temp = list2;
  }
  return;
}

void displayLinkedList(struct node *list)
{
  while(list != NULL)
  {
    printf(" Data is %d\n", list->data);
    list = list->next;
  }

  return;
}

void createList(struct node **list, int no_of_elements)
{
  struct node *newnode = NULL;
  struct node *temp = NULL;
  for(int i = 0; i < no_of_elements; i++)
  {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if(*list == NULL)
    {
      temp = *list = newnode;
    }
    else
    {
      temp->next = newnode;
      temp = newnode;
    }

  }

  if(newnode)
    free(newnode);
}

void createLinkedList(int no_of_elements1, int no_of_elements2)
{
  struct node *list_1 = NULL;
  struct node *list_2 = NULL;
  struct node *result = NULL;
  
  createList(&list_1,no_of_elements1);
  createList(&list_2,no_of_elements2);

  struct node *list = list_1;

  printf("List 1\n");
  displayLinkedList(list_1);

  printf("List 2\n");
  displayLinkedList(list_2);


  merger2List(list_1, list_2, &result);
  
  printf("Merged List \n");
  displayLinkedList(result);
}

int main()
{
  int no_of_elements1 = 0;
  int no_of_elements2 = 0;

  printf("Enter No of Elements for List 1: ");
  scanf("%d", &no_of_elements1);


  printf("Enter No of Elements for List 2: ");
  scanf("%d", &no_of_elements2);

  createLinkedList(no_of_elements1, no_of_elements2);

  return 0;
}
