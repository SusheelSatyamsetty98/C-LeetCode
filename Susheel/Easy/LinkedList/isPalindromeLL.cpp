#include <bits/stdc++.h>

using namespace std;

struct ListNode{
  int val;
  ListNode * next;
  
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *nxt) : val(x),next(nxt) {}
};

void printListNode(ListNode *n)
{
  while(n != nullptr)
  {
  cout << n->val;
  n = n->next;
  }
  return;
}

/*Note: Commented code below will create the reverse link at the time of creation only with O(N) space complexity.*/
//void createListNode(int noe,ListNode *&head, ListNode *&tail)
void createListNode(int noe,ListNode *&head)
{
  if(noe <= 0)
  {
  return;
  }
  int temp = 0;
  
  cout << "Enter the element : ";
  cin >> temp;
  
  head = new ListNode(temp);
  ListNode *temp_h = head;
//ListNode *temp_t = NULL;
  
  for (int i = 1; i < noe; i++)
  {
  cout << "Enter the element : ";
  cin >> temp;
  temp_h->next = new ListNode(temp);
  temp_h = temp_h->next;
  
  // ListNode *temp_nwt = new ListNode(temp);
  // temp_nwt->next = temp_t;
  // temp_t = temp_nwt;
  }
  // tail = temp_t;
  // printListNode(head);
}

/*
*  Time: O(N)
*  Space: O(1)
*/
ListNode * reverseLL(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    ListNode *current = head;
    
    while(current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool isPalindromeOptimized(ListNode* head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    
    while((fast != nullptr) && (fast->next != nullptr))
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast!= nullptr) //To skip middle if in case of odd length
        slow = slow->next;

    ListNode *rev = reverseLL(slow);
    slow->next = nullptr;
    while(rev != nullptr)
    {
        if(head->val != rev->val) return false;
        rev = rev->next;
        head = head->next;
    }
    
    return true;
}

/*
*  Time: O(N)
*  Space: O(N/2) -> Bcoz Of stack
*/
bool isPalindrome(ListNode *head)
{
    stack<int> st;
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while((fast != nullptr) && (fast->next != nullptr))
    {
        st.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast!= nullptr) //To skip middle if in case of odd length
        slow = slow->next;
    
    while(slow != nullptr)
    {
        if(st.top() != slow->val) return false;
        slow = slow->next;
        st.pop();
    }
    
    return true;
}

int main()
{
  ListNode *head = nullptr;
  int no_of_element = 0;
  
  cout << "Enter no of ele : " << endl;
  cin >> no_of_element;
  createListNode(no_of_element,head);

  cout << "Head : " << endl;
  printListNode(head);
  cout << endl;

bool res =  isPalindrome(head);
    cout << "is Palindorme : " <<res << endl;
  return 0;
}
