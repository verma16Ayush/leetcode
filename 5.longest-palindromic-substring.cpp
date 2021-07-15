/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// template<typename t1, typename t2>
// struct pair{
//     t1 first;
//     t2 second;
// };



class Solution {
public:
    // int dp[1000][1000];
    // int IsPalin(string s, int i, int j)
    // {
    //     if(i > j) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(i == j) dp[i][j] = 1;
    //     else if(i + 1 == j && s[i] == s[j]) dp[i][j] = 1;
    //     else if(s[i] == s[j] && IsPalin(s, i + 1, j - 1))
    //         dp[i][j] = 1;
    //     else dp[i][j] = 0;
    //     return dp[i][j];
    // }

    // string longestPalindrome(string s) 
    // {
    //     // dp = vector<vector<int>>(s.size(), vector<int>(s.length(), -1));
    //     memset(dp, -1, sizeof(dp));
    //     // IsPalin(s, 0, s.length() - 1);
    //     int mx = 0;
    //     int ires = -1;
    //     for(int i = 0; i < s.size(); i++)
    //     {
    //         for(int j = i; j < s.size(); j++)
    //         {
    //             if(IsPalin(s, i, j) && j - i + 1 > mx)
    //             {
    //                 mx = j - i + 1;
    //                 ires = i;
    //             }
    //         }
    //     }
    //     return s.substr(ires, mx);
    // } // no need

    string longestPalindrome(string s)
    {
        pair<int, int> ans = {0, 1};
        for(int i = 0; i < s.length(); i++)
        {
            auto p = getFromMid(s, i, i);
            auto q = getFromMid(s, i, i + 1);
            ans = max({p, q, ans}, [&](const pair<int, int>& a, const pair<int, int>& b)->bool{
                return a.second < b.second; // works like heap
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
    string s = "cbbd";
    Solution sol;
    cout << sol.longestPalindrome(s);
    return 0;
}
