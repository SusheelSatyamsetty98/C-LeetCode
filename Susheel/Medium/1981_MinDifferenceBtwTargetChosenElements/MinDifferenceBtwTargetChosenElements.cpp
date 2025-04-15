// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
 
using namespace std;
class Solution {
public:
    int row = 0;
    int column = 0;
    int ans = INT_MAX;
    unordered_map<int,unordered_map<int,int>> dp;

    int helpFn(int r,int sum, vector<vector<int>>& mat, int target)
    {
        if(r >= row)
        {
            ans = min(ans, abs(sum-target));
            dp[r][sum] = ans;
            return ans;
        }
        
        if (dp.find(r) != dp.end() && dp[r].find(sum) != dp[r].end())
        {
            return dp[r][sum];
        }
        
        for(int i = 0; i < column; i++)
        {
            if(sum + mat[r][i] <= target)
            {
                helpFn(r + 1,sum + mat[r][i], mat, target);
                if(ans == 0)
                {
                    break;
                }
            }
        }
        return 0;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target)
    {
        row = mat.size();
        column = mat[0].size();
        if(row == 1)
        {
            set<int> temp;
            for(int i = 0 ; i < column; i++)
            {
                temp.insert(abs(mat[0][i] - target));
            }
            ans = *temp.begin();
        }
        else
        {
            helpFn(0,0,mat,target);
        }
        return ans;
    }
};    
 
 
int main()
{
    vector<vector<int>> matrix;
    Solution sol;
    int row;
    int column;
    int target;

    cout << "No of Matrix you want to enter(Row) : ";
    cin >> row;

    cout << "No of max no of elements in each row(Column) : ";
    cin >> column;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            int temp = 0;
            cin >> temp;
            cout << i << "th row enter " << j  << " elements value was : " << temp << endl; 
            matrix[i][j] = row;
        }
    }
    cin >> target;
    int res = sol.minimizeTheDifference(matrix, target);
 
    cout << "Minimum difference: " << res << endl;
    return 0;
}