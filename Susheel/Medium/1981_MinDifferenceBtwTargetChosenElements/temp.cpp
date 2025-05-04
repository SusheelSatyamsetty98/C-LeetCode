// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        map<pair<int,int>,int> dp;
        int i = 0;
        
        while(i <= s.size())
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                if(!st.empty())
                {
                    dp[{i,st.top()}] = (i - st.top())+1);
                    st.pop();
                }
            }
            i++;
        }
        
        for(auto it = dp.begin(), it != dp.end(); ++it)
        {
            pair<int,int> first_p = it->first;
            int  first_c = it->second;
            //Write the logic here
        }
        return count;
    }
};

int main()
{
    Solution sol;
    string temp = "(()";

    int res = sol.longestValidParentheses(temp);
 
    cout << "Longest substring is : " << res << endl;
    return 0;
}