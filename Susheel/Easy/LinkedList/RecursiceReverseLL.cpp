#include <bits/stdc++.h>

using namespace std;

struct Linkedlist{
  int a;
  Linkedlist * next;
  
  Linkedlist() : a(0), next(nullptr) {}
  Linkedlist(int x) : a(x), next(nullptr) {}
  Linkedlist(int x, Linkedlist *nxt) : a(x),next(nxt) {}
};

void printLinkedlist(Linkedlist *n);
void createLinkedlist(int noe,Linkedlist *&head);
Linkedlist *copyHeadrContent(Linkedlist *&head);
/*Pointer approach*/
void reverseLinkedlist(Linkedlist *&head, Linkedlist *&tail);
/*Recursive approach*/
void reverseLinkedlistRecur(Linkedlist *current, Linkedlist *&tail);

void printLinkedlist(Linkedlist *n)
{
  while(n != nullptr)
  {
  cout << n->a;
  n = n->next;
  }
  return;
}

/*Note: Commented code below will create the reverse link at the time of creation only with O(N) space complexity.*/
//void createLinkedlist(int noe,Linkedlist *&head, Linkedlist *&tail)
void createLinkedlist(int noe,Linkedlist *&head)
{
  if(noe <= 0)
  {
  return;
  }
  int temp = 0;
  
  cout << "Enter the element : ";
  cin >> temp;
  
  head = new Linkedlist(temp);
  Linkedlist *temp_h = head;
//Linkedlist *temp_t = NULL;
  
  for (int i = 1; i < noe; i++)
  {
  cout << "Enter the element : ";
  cin >> temp;
  temp_h->next = new Linkedlist(temp);
  temp_h = temp_h->next;
  
  // Linkedlist *temp_nwt = new Linkedlist(temp);
  // temp_nwt->next = temp_t;
  // temp_t = temp_nwt;
  }
  // tail = temp_t;
  // printLinkedlist(head);
}

/*
* This is to ensure in the same code we want to reverse and store the head link seperately
* This will create a duplicate of head link, and the return Linkedlist* can be used for that purpose
*/
Linkedlist *copyHeadrContent(Linkedlist *&head)
{
    Linkedlist *org = head;
    Linkedlist *clone = nullptr;
    
    if(org != nullptr)
        clone = new Linkedlist(org->a);
    
    Linkedlist *temp = clone;
    org = org->next;
    
    while(org != nullptr)
    {
        temp->next = new Linkedlist(org->a);
        temp = temp->next;
        org = org->next;
    }
    return clone;
}

/*Pointer approach*/
void reverseLinkedlist(Linkedlist *&head, Linkedlist *&tail)
{
  Linkedlist *prev = nullptr;
  Linkedlist *current = head;
  Linkedlist *next = nullptr;
  
  while(current != nullptr)
  {
  next = current->next;
  current->next = prev;
  prev = current;
  current = next;
  }
  tail = prev;
}

/*Recursive approach*/
Linkedlist *prev_recur = nullptr;
Linkedlist *next_recur = nullptr;
void reverseLinkedlistRecur(Linkedlist *current, Linkedlist *&tail)
{
  if(current == nullptr)
  {
    tail = prev_recur;
    return;
  }

  next_recur = current->next;
  current->next = prev_recur;
  prev_recur = current;
  
  reverseLinkedlistRecur(next_recur, tail);
  return;
}

int main()
{
  Linkedlist *head = nullptr;
  Linkedlist *tail = nullptr;
  int no_of_element = 0;
  
  cout << "Enter no of ele : " << endl;
  cin >> no_of_element;
  createLinkedlist(no_of_element,head);
 
  Linkedlist *temp = nullptr;
  temp = copyHeadrContent(head);
  
  cout << "Head : " << endl;
  printLinkedlist(head);
  cout << endl;
  
  cout << "Temp : " << endl;
  printLinkedlist(temp);
  cout << endl;
  
  reverseLinkedlist(temp, tail);
  cout << "Reverse : " << endl;
  printLinkedlist(tail);
  cout << endl;
  
  cout << "Head : " << endl;
  printLinkedlist(head);
  cout << endl;
  
  temp = head;
  Linkedlist *res = nullptr;
  reverseLinkedlistRecur(temp, res);
  cout << "Recursive : " << endl;
  printLinkedlist(res);
  cout << endl;

  return 0;
}
