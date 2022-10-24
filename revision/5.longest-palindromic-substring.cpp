/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s)
    {
        pair<int, int> ans = {0, 1};
        for(int i = 0; i < s.length(); i++)
        {
            auto p = getFromMid(s, i, i);
            auto q = getFromMid(s, i, i + 1);
            ans = max({p, q, ans}, [&](const pair<int, int>& a, const pair<int, int>& b)->bool{
                return a.second < b.second;
            });
        }
        return s.substr(ans.first, ans.second);
    }

    pair<int, int> getFromMid(string& s, int i, int j)
    {
        if(s == "" || i > j) return {};
        while(i >= 0 && j <= s.length() - 1 && s[i] == s[j]) i--, j++;
        return {i + 1, j - i - 1};
    }
};
// @lc code=end

int32_t main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string a = "babad";
    string b = "bab";
    cout << Solution().longestPalindrome(a);

    return 0;
}