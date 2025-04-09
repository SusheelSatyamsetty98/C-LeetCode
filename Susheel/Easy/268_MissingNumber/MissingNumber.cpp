// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

bool MissingNumber(vector<int> &num)
{
    bool res = false;
    set<int> a;
    
    for(auto it : num)
    {
        a.insert(it);
    }
    
    (a.size() == num.size()) ? res = false : res = true;
    
    return res;
}

int main() {
    vector<int> a;
    bool res = false;
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
    
    res = MissingNumber(a);
    
    cout << "res : " << res << endl;

    return 0;
}