// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

vector<int> FindAllNumbersDisappearedInArray(vector<int> &nums)
{
    int i = 1;
    set<int> a;
    vector<int> res;
    
    for(auto it : nums)
    {
        a.insert(it);
    }
    
    // i = *a.rbegin();
    set<int>::iterator it = a.begin(); 
    for(int i = 1; i <= nums.size(); i++)
    {
        if(i != *it)
        {
            res.push_back(i);
        }
        else
        {
            it++;
        }
    }
    
    return res;
}

int main() {
    vector<int> a;
    vector<int> res;
    int numSize = 0;
    
    cout << "enter size :";
    cin>>numSize;
    
    for(int i = 0; i < numSize; i++)
    {
        int val;
        cout << i << ": "; 
        cin>>val;
        a.push_back(val);
    }
    
    res = FindAllNumbersDisappearedInArray(a);
    
    for(auto val : res)
        cout << val << " ";

    return 0;
}