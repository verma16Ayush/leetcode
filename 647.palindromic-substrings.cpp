/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1000][1000];
    int IsPalin(string s, int i, int j)
    {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == j) dp[i][j] = 1;
        else if(i + 1 == j && s[i] == s[j]) dp[i][j] = 1;
        else if(s[i] == s[j] && IsPalin(s, i + 1, j - 1))
            dp[i][j] = 1;
        else dp[i][j] = 0;
        return dp[i][j];
    }

    int countSubstrings(string s) 
    {
        memset(dp, -1, sizeof(dp));
        // IsPalin(s, 0, s.length() - 1);
        int mx = 0;
        int ires = -1;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(IsPalin(s, i, j))
                {
                    mx++;
                }
            }
        }
        return mx;
    }
};
// @lc code=end

