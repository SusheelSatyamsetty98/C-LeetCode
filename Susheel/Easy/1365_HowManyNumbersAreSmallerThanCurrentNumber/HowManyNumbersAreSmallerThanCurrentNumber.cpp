#include <bits/stdc++.h>

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> res;  
    int count[101] = {0};
   
    for(auto it : nums)
    {
        count[it]++;
    }

    for(int i = 1; i < 101; i++)
    {
        count[i] += count[i - 1];
    }

    for(auto it : nums)
    {
        res.push_back(it > 0 ? count[it - 1] : 0);
    }
   
    return res;
}

int main() {
    vector<int> a;
    vector<int> res;
    int numSize = 0;
   
    cout << "Enter size: ";
    cin >> numSize;
   
    for(int i = 0; i < numSize; i++)
    {
        int val;
        cout << i << ": ";
        cin >> val;
        a.push_back(val);
    }
   
    res = smallerNumbersThanCurrent(a);
   
    for(auto val : res)
        cout << val << " ";

    return 0;
}