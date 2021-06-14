/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    void Gen(string s, int o, int c)
    {
        if(o == 0 && c == 0) 
        {
            ans.push_back(s);
            return;
        }
        if(c > o)
        {
            if(o != 0)
            {
                s.push_back('(');
                Gen(s, o - 1, c);
                s.pop_back();
            }
            s.push_back(')');
            Gen(s, o, c - 1);
        }
        else
        {
            if(o != 0)
            {
                s.push_back('(');
                Gen(s, o - 1, c);
                s.pop_back();
            }
        }
        return;
    }
    vector<string> generateParenthesis(int n) 
    {
        if(n == 0) return {};
        Gen(string(), n, n);
        return ans;
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    vector<string> s = sol.generateParenthesis(3);
    return 0;
}