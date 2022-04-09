/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_map<char, string> keypad;
    vector<string> ans;
    Solution() : keypad({
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    }), ans(vector<string>()) {}
    
    void dfs(string digs, int i, string s)
    {
        if(i == digs.size())
        {
            ans.push_back(s);
            return;
        }
        for(int k = 0; k < keypad[digs[i]].length(); k++)
        {
            s.push_back(keypad[digs[i]][k]);
            dfs(digs, i + 1, s);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        dfs(digits, 0, "");
        return ans;
    }
};
// @lc code=end

