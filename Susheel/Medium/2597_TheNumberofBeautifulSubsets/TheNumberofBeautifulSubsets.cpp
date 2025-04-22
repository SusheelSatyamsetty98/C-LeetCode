// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    set<vector<int>> subset;
    void calNoOfSubsets(int idx, vector<int>& vct, vector<int>& nums, int target)
    {
        if(idx >= nums.size())
            return;
    
        // Try including nums[idx] if it doesn't violate the condition
        bool isValid = true;
        for (int val : vct) {
            if (abs(val - nums[idx]) == target) {
                isValid = false;
                break;
            }
        }
    
        if (isValid) {
            vct.push_back(nums[idx]);
            subset.insert(vct);
            calNoOfSubsets(idx + 1, vct, nums, target);
            vct.pop_back(); // correct backtracking
        }
    
        // Always explore not picking current element
        calNoOfSubsets(idx + 1, vct, nums, target);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> vct = {};
        calNoOfSubsets(0,vct,nums,k);
        
        return subset.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,2,5,9,10,3};
    int target = 1;
    sort(nums.begin(),nums.end());
    
    int res = sol.beautifulSubsets(nums,target);
    
    cout << "No Of Beautiful Subsets Can Form are : " << res << endl;
    
    for(auto it : sol.subset)
    {
        for(int i : it)
            cout << i << " ";
        cout << endl;
    }
    
    return 0;
}