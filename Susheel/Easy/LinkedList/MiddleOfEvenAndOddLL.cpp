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

/* IMPORTANT NOTE: START THE Fast Pointer with head->next Instead of head
If there are two middle nodes, return the second middle node. -> Then run the fast pointer from head only. */

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

// int middleOfLL(Linkedlist* &head)
// {
//     Linkedlist *slow = head;
//     Linkedlist *fast = head;
    
//     while((fast != nullptr)  && (fast->next) != nullptr)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
    
//     return slow->a;
// }

Linkedlist* middleOfLL(Linkedlist* head) {
    if (head == nullptr) return nullptr;

    Linkedlist* slow = head;
    Linkedlist* fast = head->next;  // ← Key change

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // First middle (if even length)
}



int main()
{
  Linkedlist *head = nullptr;
  int no_of_element = 0;
  
  cout << "Enter no of ele : " << endl;
  cin >> no_of_element;
  createLinkedlist(no_of_element,head);
  
  cout << "1st Linked List : " << endl;
  printLinkedlist(no_of_element, head);
  cout << endl;

//   cout << middleOfLL(head) << endl;
  Linkedlist *res = middleOfLL(head);
  cout << "Middle Val : " << res->a << endl;
  

  return 0;
}
