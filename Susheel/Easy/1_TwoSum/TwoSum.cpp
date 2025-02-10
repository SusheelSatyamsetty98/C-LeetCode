// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

#define Ver_1 1

using namespace std;

vector<int> TwoSum(vector<int> &nums,int target)
{
    vector<pair<int,int>> a;
    vector<int> res;
    int itr  = 0;
    
    a.emplace_back((target - nums[0]), 0);
#if Ver_1  //Performed better than ver_2  
    for(int i = 1; i < nums.size(); i++)
    {
        vector<pair<int,int>>::iterator it = a.begin(); 
        for (int j = 0 ; j < a.size(); j++, it++)
        {
            if(((it->first)) == nums[i])
            {
                res.push_back(i);
                res.push_back((it->second));
                return res;
            }
        }
        a.emplace_back((target - nums[i]), i);
    }
#endif    
#if Ver_2
    for(int i = 1; i < nums.size(); i++)
    {
        auto idx = find_if(a.begin(),a.end(),[&](pair<int,int> & p){
            return p.first == nums[i];
        });
        
        if (idx != a.end())
        {
            res.push_back(i);
            res.push_back(idx->second);
            return res;
        }
        else
        {
            a.emplace_back((target - nums[i]), i);
        }
    }
#endif    
    return res;
}

int main() {
    vector<int> a;
    vector<int> res;
    int numSize = 0;
    int target = 0;
    
    cout << "enter size :";
    cin>>numSize;
    
    for(int i = 0; i < numSize; i++)
    {
        int val;
        cout << i << ": "; 
        cin>>val;
        a.push_back(val);
    }
    cout << "target: ";
    cin>>target;
    
    res = TwoSum(a,target);
    
    for(auto val : res)
        cout << val << " ";

    return 0;
}