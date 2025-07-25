// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

struct Linkedlist{
  int a;
  Linkedlist * next;
  
  Linkedlist() : a(0), next(nullptr) {}
  Linkedlist(int x) : a(x), next(nullptr) {}
  Linkedlist(int x, Linkedlist *nxt) : a(x),next(nxt) {}
};

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
  
  for (int i = 1; i < noe; i++)
  {
      cout << "Enter the element : ";
      cin >> temp;
      temp_h->next = new Linkedlist(temp);
      temp_h = temp_h->next;
  }
}

void helperFn(Linkedlist *&temp, queue<Linkedlist*> &q)
{
    if(q.empty())
        return;

    if(temp->next != nullptr)
    {
        q.push(temp->next);
    }
    else
    {
        temp->next = q.front();
        q.pop();
        return;
    }
    
    temp->next = q.front();
    q.pop();
    temp = temp->next;
    
    if(!q.empty())
        helperFn(temp,q);
    
    return;
}

Linkedlist *mergeLinkedlistRecu(Linkedlist *&head, Linkedlist *&head2)
{
    Linkedlist *merge = nullptr;
    Linkedlist *temp = nullptr;
    
    queue<Linkedlist*> q;
    
    if(head != nullptr) q.push(head);
    if (head2 != nullptr) q.push(head2);
    
    if(merge == nullptr)
    {
        merge = temp = q.front();
        q.pop();
    }
    
    if(!q.empty())
    {
        helperFn(temp, q);
    }
    return merge;
}

Linkedlist *mergeLinkedlist(Linkedlist *&head, Linkedlist *&head2)
{
    Linkedlist *merge = nullptr;
    Linkedlist *temp = nullptr;
    
    queue<Linkedlist*> q;
    
    if(head != nullptr) q.push(head);
    if (head2 != nullptr) q.push(head2);
    
    if(merge == nullptr)
    {
        merge = temp = q.front();
        q.pop();
    }
    
    while(!q.empty())
    {
        
        if(temp->next != nullptr)
        {
            q.push(temp->next);
        }
        else
        {
            temp->next = q.front();
            q.pop();
            return merge;
        }
        
        temp->next = q.front();
        q.pop();
        temp = temp->next;
    }
    return merge;
}

int main()
{
  Linkedlist *head = nullptr;
  int no_of_element = 0;
  Linkedlist *head2 = nullptr;
  int no_of_element2 = 0;
  
  cout << "Enter no of ele : " << endl;
  cin >> no_of_element;
  createLinkedlist(no_of_element,head);
  
  cout << "1st Linked List : " << endl;
  printLinkedlist(no_of_element, head);
  cout << endl;
  
    cout << "Enter no of ele : " << endl;
  cin >> no_of_element2;
  createLinkedlist(no_of_element2,head2);
  
  cout << "2nd Linked List : " << endl;
  printLinkedlist(no_of_element2, head2);
  cout << endl;
  
  Linkedlist *res = mergeLinkedlist(head, head2);
  
    cout << "Merge Linked List : " << endl;
  printLinkedlist(no_of_element + no_of_element2, res);
  cout << endl;

  
  res = mergeLinkedlistRecu(head, head2);
  
    cout << "Merge Recursive Linked List : " << endl;
  printLinkedlist(no_of_element + no_of_element2, res);
  cout << endl;

  return 0;
}
