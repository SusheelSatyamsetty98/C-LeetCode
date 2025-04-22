// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> final;
    vector<int> temp;
    
    void helpFn(vector<int>& res, vector<int>& temp)
    {
        if(temp.empty())
        {
            final.push_back(res);
            return;
        }
        int n = temp.size();
        for(int i = 0; i  < n; ++i)
        {
            int var = temp[i];
            res.push_back(var);
            temp.erase(temp.begin() + i);
            helpFn(res,temp);
            res.pop_back();
            temp.insert(temp.begin() + i,var);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        temp = nums;
        for(int i = 0; i < nums.size(); i++)
        {
            temp.erase(temp.begin() + i);
            res.push_back(nums[i]);
            
            helpFn(res,temp);
            
            res.clear();
            temp = nums;
        }
        return final;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3};
    
    sol.permute(nums);
    
    for(auto it : sol.final)
    {
        for(int i : it)
        {
            cout << i << " " ;
        }
        cout << endl;
    }
    
    return 0;
}