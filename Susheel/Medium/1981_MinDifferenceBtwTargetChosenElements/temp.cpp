// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int allPossibleSetCount = 0;
    std::vector<int> dp_vec;
    int helpFn(int start,vector<int>& mat,int k)
    {
        int res = 0;
        int temp = start;
        int itr = start + 1;

        while(temp < mat.size() - 1)
        {
            if (itr > mat.size()) return res;
            
            if(abs(mat[start] - mat[itr++]) != k)
            {
                res++;
            }
            temp++;
        }

        return res;
    }
    
    int findAllPossibleSubsets()
    {
        return allPossibleSetCount;
    }
    
    int beautifulSubsets(vector<int>& nums, int k)
    {
        dp_vec.resize(nums.size());
        allPossibleSetCount += nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 1; i++)
        {
            dp_vec[i] = helpFn(i,nums,k);
            allPossibleSetCount += dp_vec[i];
            cout << i << " " << dp_vec[i] << " " << allPossibleSetCount << endl;
        }
        exit(1);
        return findAllPossibleSubsets();
    }
};

int main() {
    Solution sol;
    int res = 0;
    vector<int> nums = {1,2,4,3,5};
    int k = 1;
    
    res = sol.beautifulSubsets(nums,k);
    return 0;
}
