/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> ans;
    Solution() : ans(vector<string>()){}
    
    void genParen(string s, int o, int c)
    {
        if(!o && !c)
        {
            ans.push_back(s);
            return;
        }
        if(c > o)
        {
            if(o != 0)
            {
                s.push_back('(');
                genParen(s, o - 1, c);
                s.pop_back();
            }
            s.push_back(')');
            genParen(s, o, c - 1);
        }
        else
        {
            s.push_back('(');
            genParen(s, o - 1, c);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return {};
        genParen(string(), n, n);
        return ans;
    }
};
// @lc code=end

