/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;
    bool IsPalin(string& s, int st, int en)
    {
        while(st <= en) if(s[st++] != s[en--]) return false;
        return true;
    }
    void dfs(string& s, int st, vector<string> temp)
    {
        if(st == s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = st; i < s.length(); i++)
        {
            if(IsPalin(s, st, i))
            {
                temp.push_back(s.substr(st, i - st + 1));
                dfs(s, i + 1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        ans = vector<vector<string>>();
        dfs(s, 0, vector<string>());
        return ans;
    }
};
// @lc code=end

