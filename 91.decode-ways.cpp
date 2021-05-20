/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int dp[101];

    int CounWays(string s, int n)
    {
        if(dp[n] != -1) return dp[n];
        if(n < 0) return 0;
        if(n == 0) return dp[n] = 1;
        if(n == 1)
        {
            if(s[n - 1] != '0') return dp[n] = 1;
            else return dp[n] = 0;
        }
        char dl = s[n - 1];
        char dsl = s[n - 2];
        
        int ans = 0;
        if(dl == '0' && (dsl == '1' || dsl == '2')) ans += CounWays(s, n - 2);
        if(dsl == '1' && dl >= '1' && dl <= '9') ans += CounWays(s, n - 2);
        if(dsl == '2' && dl >= '1' && dl <= '6') ans += CounWays(s, n - 2);
        if(dl != '0') ans += CounWays(s, n - 1);
        return dp[n] = ans;
    } 
    int numDecodings(string s) 
    {
        memset(dp, -1, sizeof(dp));
        return CounWays(s, s.length());
    }
};
// @lc code=end

