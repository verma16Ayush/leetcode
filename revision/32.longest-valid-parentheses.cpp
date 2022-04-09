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
        stack<int> st;
        vector<int> valid(s.length());
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            else
            {
                if(st.size() && s[st.top()] == '(')
                {
                    valid[st.top()] = 1;
                    valid[i] = 1;
                    st.pop();
                }
            }
        }
        int cnt = 0;
        int mx = 0;
        for(int i = 0; i < valid.size(); i++)
        {
            if(valid[i] == 1)
                cnt++;
            else
            {
                mx = max(cnt, mx);
                cnt = 0;
            }
        }
        return max(cnt, mx);
    }
};
// @lc code=end
int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = "(()";
    cout << Solution().longestValidParentheses(s) << endl;
    return 0;
}

