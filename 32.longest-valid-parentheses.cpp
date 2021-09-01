/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> st;
        vector<int> valid(s.size());
        for(int i = 0; i < s.size(); i++)        
        {
            if(s[i] == '(') st.push_back(i);
            else
            {
                if(st.size())
                {
                    valid[st.back()] = 1;
                    valid[i] = 1;
                    st.pop_back();
                }
            }
        }

        int cur = 0, mx = 0;
        for(int i = 0; i < valid.size(); i++)
        {
            if(valid[i]) cur++;
            else cur = 0;
            mx = max(cur, mx);
        }
        return mx;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = ")()())";
    cout << Solution().longestValidParentheses(s);
    return 0;
}