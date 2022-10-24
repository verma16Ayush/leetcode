/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int dp[1001][1001];
    int LcsHelp(string& a, string& b, int n, int m)
    {
        if(dp[n][m] != -1)
            return dp[n][m];
        if(n == 0 || m == 0)
            return dp[n][m] = 0;
        if(a[n - 1] == b[m - 1])
            return dp[n][m] = 1 + LcsHelp(a, b, n - 1, m - 1);
        return dp[n][m] = max(LcsHelp(a, b, n - 1, m), LcsHelp(a, b, n, m - 1));
    }
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        memset(dp, -1, sizeof(int) * 1001 * 1001);
        return LcsHelp(s, rev, s.size(), s.size());
    }
};
// @lc code=end

