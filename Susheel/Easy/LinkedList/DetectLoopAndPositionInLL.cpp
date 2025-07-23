#include <bits/stdc++.h>

using namespace std;

struct Linkedlist{
  int a;
  Linkedlist * next;
  
  Linkedlist() : a(0), next(nullptr) {}
  Linkedlist(int x) : a(x), next(nullptr) {}
  Linkedlist(int x, Linkedlist *nxt) : a(x),next(nxt) {}
};

/* Used Loop variable to simulate the looping scenario */
Linkedlist *loop = nullptr;

void printLinkedlist(int noe, Linkedlist *n)
{
  for(int i = 0; i < noe; i++)
  {
  cout << n->a;
  n = n->next;
  }
  return;
}

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
  loop = head;
  
  for (int i = 1; i < noe; i++)
  {
      cout << "Enter the element : ";
      cin >> temp;
      temp_h->next = new Linkedlist(temp);
      if(i+1 == (int)noe/2)
      {
          loop = temp_h->next;
      }
      temp_h = temp_h->next;
  }
  
  temp_h->next = loop;
}

/* itr to get the index position */
int itr = 0;
bool isLoopExists(Linkedlist *head)
{
    Linkedlist *t = head;
    Linkedlist *h = head;
    map<Linkedlist*, int> mp;
    
    while(h != nullptr && h->next != nullptr)
    {
        mp[t] = itr++;
        t = t->next;
        h = h->next->next;
        
        if(t == h)
        {
            cout << "Index  " << itr << "(Val : " << t->a << ")" <<  "is Looping/Pointing to Index  " << mp[t->next] << "(Val : " << t->next->a << ")" << endl;
            return true;
        }
    }
    
    return false;
}

int main()
{
  Linkedlist *head = nullptr;
  int no_of_element = 0;
  
  cout << "Enter no of ele : " << endl;
  cin >> no_of_element;
  createLinkedlist(no_of_element,head);
  
  cout << "Linked List : " << endl;
  printLinkedlist(no_of_element, head);
  cout << endl;
  
  isLoopExists(head) ? cout << "Loop Exists" : cout << "Not Exists" ;

  return 0;
}
