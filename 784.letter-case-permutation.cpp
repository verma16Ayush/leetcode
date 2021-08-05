/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> ans;
    void help(string& s, string res, int i)
    {
        if(i == s.length())
        {
            ans.push_back(res);
            return;
        }
        if(s[i] >= '0' && s[i] <= '9')
        {
            res.push_back(s[i]);
            help(s, res, i + 1);
        }
        else
        {
            res.push_back(toupper(s[i]));
            help(s, res, i + 1);
            res.pop_back();
            res.push_back(tolower(s[i]));
            help(s, res, i + 1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        ans = vector<string>();
        string res = "";
        help(s, res, 0);
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
    return 0;
}
